#include "RayTracer.h"
#include "Math/Random.h"
#include "Math/Math.h"

#include <iostream>
#include <execution>


namespace rt
{
	RayTracer::RayTracer(int width, int height) :
		m_Image(std::make_unique<Image>(width, height)),
		m_AccumulationImage(std::make_unique<AccImage>(width, height)), // Just for debug it will get recalculated later
		m_Camera(glm::vec3(0, 0, 3), glm::vec3(0, 0, 1.5), glm::vec3(0, 1, 0), 90.0f, (float)width / (float)height)
	{
	}

	void RayTracer::Trace()
	{	
		Timer timer(m_RenderTime.timeDiff, m_RenderTime.FPS);

		if (m_FrameIndex == 1)
			m_AccumulationImage->Clear();

		PerPixel([this](uint32_t x, uint32_t y)
		{
				Ray ray = m_Camera.get_ray(x, y, m_Settings.antialiasing, glm::vec2((float)m_Image->Width(), (float)m_Image->Height()));

				m_AccumulationImage->Accumulate(x, y, Trace(ray));
				color accumulationColor = m_AccumulationImage->PixelColor(x, y);
				accumulationColor /= (float)m_FrameIndex;
				accumulationColor.a = 1.0f;

				if (m_Settings.gammaCorection)
					m_Image->SetPixel(x, y, Math::GammaCorection2(accumulationColor));
				else
					m_Image->SetPixel(x, y, accumulationColor);
		});

		if (m_Settings.accumulate and !m_Camera.IsMoving())
			m_FrameIndex++;
		else
		{
			m_FrameIndex = 1;
			m_ImageReset = true;
		}
	}

	void RayTracer::Raster()
	{
		std::for_each(std::execution::par, m_Image->Begin(), m_Image->End(),
			[this](uint32_t y)
			{
				for (int x = 0; x < m_Image->Width(); ++x)
				{
					Ray ray = m_Camera.get_ray(x, y, m_Settings.antialiasing, glm::vec2((float)m_Image->Width(), (float)m_Image->Height()));


					color col = Raster(ray);

					if (m_Settings.gammaCorection)
						m_Image->SetPixel(x, y, Math::GammaCorection2(col));
					else
						m_Image->SetPixel(x, y, col);
				}
			});
	}

	void RayTracer::Resize(int width, int height)
	{
		if (m_Image->Width() == width and m_Image->Height() == height) return;
		if (width < 1 or height < 1) return;

		NewImage(width, height);
	}

	color RayTracer::Trace(Ray& ray)
	{
		color incomingLight = Color::Black;
		color rayColor = Color::White;

		for (int i = 0; i < m_Settings.maxBounces; i++)
		{
			HitInfo hitInfo = m_World.Intesection(ray);
			if (hitInfo.didHit)
			{
				Material material = hitInfo.material;
				ray.Origin(hitInfo.hitPoint);
				glm::vec3 diffuseDir = glm::normalize(hitInfo.normal + Random::InUnitSphere());
				glm::vec3 specularDir = glm::reflect(ray.Direction(), hitInfo.normal);
				bool isSpecularBounce = material.specularProbability >= Random::Float();
				if (material.isMetalic)
					ray.Direction(glm::mix(diffuseDir, specularDir, material.smoothness));
				else
					ray.Direction(glm::mix(diffuseDir, specularDir, material.smoothness * isSpecularBounce));


				glm::vec4 emittedLight = material.emissionColor * material.emissionStrenght;
				incomingLight += (emittedLight * rayColor); 
				rayColor *= glm::mix(material.albedo, material.specularColor, isSpecularBounce);
			}
			else
			{
				incomingLight += m_World.Background(ray) * rayColor;
				break;
			}
		}
		incomingLight.a = 1.0f; // Set the alpha to 1.0f
		return glm::clamp(incomingLight, glm::vec4(0.0f), glm::vec4(1.0f));
	}

	color RayTracer::Raster(const Ray& ray)
	{
		HitInfo hitInfo = m_World.Intesection(ray);
		if (hitInfo.didHit)
			return hitInfo.material.albedo;

		return m_World.Background(ray);
	}

	void RayTracer::NewImage(int width, int height)
	{
		m_FrameIndex = 1;

		m_Image = std::make_unique<Image>(width, height);
		m_AccumulationImage = std::make_unique<AccImage>(width, height);
		m_Camera.Recalculate(m_Image->AspectRatio());
	}

	void RayTracer::PerPixel(std::function<void(uint32_t, uint32_t)> func)
	{
		std::for_each(std::execution::par, m_Image->Begin(), m_Image->End(),
			[&func, this](uint32_t y)
			{
				for (int x = 0; x < m_Image->Width(); ++x)
				{
					func(x, y);
				}
			});
	}
} // rt
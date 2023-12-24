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
		m_Camera(60.0f, glm::vec3{ 0.0f }, { 0.0f, 0.0f, 1.0f })
	{
		m_Camera.Recalculate(*m_Image);

		//For teting
		Material red{ Color::Red };
		Material cyan{ Color::Cyan };
		Material yellow{ Color::Yellow };
		Material magenta{ Color::Magenta };


		Sphere redSphere(0.5f, point(0, 0, -1.0f), red);
		Sphere blueSphere(0.6f, point(1.0f, 0.0f, -1.0f), cyan);
		Sphere cSphere(0.6f, point(1.0f, 0.0f, -1.0f), yellow);
		Sphere mSphere(0.6f, point(1.0f, 0.0f, -1.0f), magenta);

		m_World.Add(blueSphere);
		m_World.Add(redSphere);
		m_World.Add(cSphere);
		m_World.Add(mSphere);


		//////---------------
	}

	void RayTracer::Trace()
	{
		if (m_FrameIndex == 1)
			m_AccumulationImage = std::make_unique<AccImage>(m_Image->Width(), m_Image->Height());

		std::for_each(std::execution::par, m_Image->Begin(), m_Image->End(),
			[this](uint32_t y)
			{
				for (int x = 0; x < m_Image->Width(); ++x)
				{
					float offset_x = Random::Float2(-0.9f, 0.9f);
					float offset_y = Random::Float2(-0.9f, 0.9f);

					Ray ray = m_Camera.GetRay(x, y, m_Settings.antialiasing);
					

					m_AccumulationImage->Accumulate(x, y, Trace(ray));
					color accumulationColor = m_AccumulationImage->PixelColor(x, y);
					accumulationColor /= (float)m_FrameIndex;
					accumulationColor.a = 1.0f;

					if (m_Settings.gammaCorection)
						m_Image->SetPixel(x, y, Math::GammaCorection2(accumulationColor));
					else
						m_Image->SetPixel(x, y, accumulationColor);
				}
			});

		if (m_Settings.accumulate)
			m_FrameIndex++;
		else
			m_FrameIndex = 1;
	}

	void RayTracer::Resize(int width, int height)
	{
		if (m_Image->Width() == width and m_Image->Height() == height) return;
		if (width < 1 or height < 1) return;

		m_FrameIndex = 1;

		m_Image = std::make_unique<Image>(width, height);
		m_AccumulationImage = std::make_unique<AccImage>(width, height);
		m_Camera.Recalculate(*m_Image);
	}

	void RayTracer::Export()
	{
		ImGui::Begin("Settings");
		ImGui::Checkbox("Accumulate", &m_Settings.accumulate);
		ImGui::Checkbox("Gamma Corection", &m_Settings.gammaCorection);
		ImGui::Checkbox("AntiAliasing", &m_Settings.antialiasing);
		ImGui::End();
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
				incomingLight += m_World.SkyboxColor(ray) * rayColor;
				break;
			}
		}
		incomingLight.a = 1.0f; // Set the alpha to 1.0f
		return glm::clamp(incomingLight, glm::vec4(0.0f), glm::vec4(1.0f));
	}
} // rt
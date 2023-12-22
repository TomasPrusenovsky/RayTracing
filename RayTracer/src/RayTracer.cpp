#include "RayTracer.h"
#include "Math/Random.h"

#include <iostream>
#include <execution>

#define MT 1

namespace rt
{
	glm::vec3 ray_color(const Ray& r) // TODO: to be removed
	{
		glm::vec3 unit_direction = glm::normalize(r.Direction());
		auto a = 0.5f * (unit_direction.y + 1.0f);
		return (1.0f - a) * glm::vec3(1.0f, 1.0f, 1.0f) + a * glm::vec3(0.5f, 0.7f, 1.0f);
	}

	RayTracer::RayTracer(int width, int height) :
		m_Image(std::make_unique<Image>(width, height)),
		m_Camera(60.0f, glm::vec3{ 0.0f }, { 0.0f, 0.0f, 1.0f })
	{
		m_Camera.Recalculate(*m_Image);

		//For teting
		Material red{ Color::Red };
		Material blue{ Color::Blue };

		Sphere redSphere(0.5f, point(0, 0, -1.0f), red);
		Sphere blueSphere(0.6f, point(1.0f, 0.0f, -1.0f), blue);
		m_World.Add(blueSphere);
		m_World.Add(redSphere);

		//////---------------
	}

	void RayTracer::Trace()
	{
#if MT
		std::for_each(std::execution::par, m_Image->Begin(), m_Image->End(),
			[this](uint32_t y)
			{
				for (int x = 0; x < m_Image->Width(); ++x)
				{
					Ray ray = m_Camera.GetRay(x, y);
					color r_color;
					HitInfo hit{ m_World.Intesection(ray) };

					if (hit.didHit)
						r_color = hit.material.albedo;
					else
						r_color = m_World.Background();

					m_Image->SetPixel(x, y, r_color);
				}
			});
#else
		for (int y = 0; y < m_Image->Height(); ++y)
		{
			for (int x = 0; x < m_Image->Width(); ++x)
			{
				Ray ray = m_Camera.GetRay(x, y);
				m_Image->SetPixel(x, y, color(ray_color(ray), 1.0f));
			}
		}
#endif
	}

	void RayTracer::Resize(int width, int height)
	{
		if (m_Image->Width() == width and m_Image->Height() == height) return;
		if (width < 1 or height < 1) return;

		m_Image = std::make_unique<Image>(width, height);
		m_Camera.Recalculate(*m_Image);
	}
} // rt
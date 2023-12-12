#include "RayTracer.h"
#include "Math/Random.h"

#include <iostream>


namespace rt
{
	glm::vec3 ray_color(const Ray& r)
	{
		glm::vec3 unit_direction = glm::normalize(r.Direction());
		auto a = 0.5f * (unit_direction.y + 1.0f);
		return (1.0f - a) * glm::vec3(1.0f, 1.0f, 1.0f) + a * glm::vec3(0.5f, 0.7f, 1.0f);
	}

	RayTracer::RayTracer(int width, int height) :
		m_Image(std::make_unique<Image>(width, height)),
		m_Camera(60.0f, glm::vec3{0.0f}, {0.0f, 0.0f, 1.0f})
	{
		m_Camera.Recalculate(*m_Image);
	}

	void RayTracer::Trace()
	{
		for (int y = 0; y < m_Image->Height(); ++y)
		{
			for (int x = 0; x < m_Image->Width(); ++x)
			{
				Ray ray = m_Camera.GetRay(x, y);
				m_Image->SetPixel(x, y, color(ray_color(ray), 1.0f));
			}
		}
	}

	void RayTracer::Resize(int width, int height)
	{
		if (m_Image->Width() == width and m_Image->Height() == height) return;
		if (width < 1 or height < 1) return;

		m_Image = std::make_unique<Image>(width, height);
		m_Camera.Recalculate(*m_Image);
	}
} // rt
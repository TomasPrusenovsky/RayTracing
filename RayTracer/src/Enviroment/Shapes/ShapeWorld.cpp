#include "ShapeWorld.h"

namespace rt
{
	ShapeWorld::ShapeWorld()
	{
	}

	void ShapeWorld::Add(const Sphere& shape)
	{
		m_Shapes.push_back(std::make_unique<Sphere>(shape));
	}
	HitInfo ShapeWorld::Intesection(const Ray& ray)
	{
		HitInfo closest;
		closest.distance = std::numeric_limits<float>::max();
		for (auto&& shape : m_Shapes)
		{
			HitInfo hit = shape->Intersection(ray);
			if (hit.didHit)
			{
				if (hit.distance < closest.distance)
					closest = hit;
			}
		}

		return closest;
	}
}
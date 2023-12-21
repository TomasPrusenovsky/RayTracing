#include "Sphere.h"
#include "Math/Math.h"

namespace rt
{
	Sphere::Sphere(float radius, point position, Material material) :
		m_Radius(radius), m_Position(position)
	{
		m_Material = material;
	}

	const HitInfo Sphere::Intersection(const Ray& ray) const
	{
		const direction orig_pos = ray.Origin() - m_Position;
		const auto a = glm::dot(ray.Direction(), ray.Direction());
		const auto half_b = glm::dot(orig_pos, ray.Direction());
		const auto c = Math::length_squared(orig_pos) - m_Radius * m_Radius;
		const auto discriminant = half_b * half_b - a * c;

		if (discriminant < 0.0f)
			return { false };

		const point hit_point = ray[(-half_b - glm::sqrt(discriminant)) / a];
		return { true, hit_point, m_Material };
	}
} // rt
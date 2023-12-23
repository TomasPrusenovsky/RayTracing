#include "Sphere.h"
#include "Math/Math.h"

namespace rt
{
	unsigned int Sphere::s_Instance = 0;

	Sphere::Sphere(float radius, point position, Material material) :
		m_Radius(radius), m_Position(position)
	{
		m_Name += std::to_string(s_Instance);
		++s_Instance;
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
		const float distance = glm::distance(hit_point, ray.Origin());

		return { true, hit_point, m_Material, distance };
	}
	void Sphere::Export()
	{
		ImGui::Begin(m_Name.c_str());
		ImGui::DragFloat("Radius", &m_Radius, 0.01f);
		MaterialExport();
		ImGui::End();
	}
} // rt
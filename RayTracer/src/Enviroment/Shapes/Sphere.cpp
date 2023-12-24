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

		float distance = (-half_b - glm::sqrt(discriminant)) / a;
		if (distance < 0.0f)
			return { false };

		point hit_point = ray[distance];
		const point normal = glm::normalize(hit_point - m_Position);
		hit_point += normal * 0.00001f; // move it slightly so the reflected ray doesnt interact with itself

		return { true, hit_point, m_Material, normal, distance };
	}
	void Sphere::Export()
	{
		ImGui::Begin(m_Name.c_str());
		ImGui::DragFloat("Radius", &m_Radius, 0.01f, 0.0f, 10.0f);
		ImGui::DragFloat3("Position", &m_Position.x, 0.01f);
		MaterialExport();
		ImGui::End();
	}
} // rt
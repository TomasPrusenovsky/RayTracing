#pragma once
#include "Shape.h"
#include <string>

namespace rt
{
	class Sphere : public Shape
	{
	public:
		Sphere(float radius, point position, Material material);
		~Sphere() = default;
		const HitInfo Intersection(const Ray& ray) const override;
		
		void Export() override;

	private:
		std::string m_Name = "Sphere";
		static unsigned int s_Instance;

		float m_Radius;
		point m_Position;
	};
} // rt

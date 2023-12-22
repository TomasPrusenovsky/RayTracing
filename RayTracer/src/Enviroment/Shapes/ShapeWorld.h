#pragma once
#include "Shape.h"
#include "Sphere.h"

#include <memory>
#include <vector>

namespace rt
{
	class ShapeWorld
	{
	public:
		ShapeWorld();
		void Add(const Sphere& shape);
		HitInfo Intesection(const Ray& ray);


	private:
		auto begin() { return m_Shapes.begin(); }
		auto end() { return m_Shapes.end(); }

	private:
		using ShapePtr = std::unique_ptr<Shape>;
		std::vector<ShapePtr> m_Shapes;
	};
}
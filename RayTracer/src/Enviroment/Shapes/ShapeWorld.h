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
		using ShapePtr = std::unique_ptr<Shape>;
		using ShapeList = std::vector<ShapePtr>;

		ShapeWorld();
		void Add(const Sphere& shape); // TODO: change this to move the shapes
		HitInfo Intesection(const Ray& ray);
		const ShapeList& Shapes() const { return m_Shapes; }

	private:
		auto begin() { return m_Shapes.begin(); }
		auto end() { return m_Shapes.end(); }

	private:
		ShapeList m_Shapes;
	};
}
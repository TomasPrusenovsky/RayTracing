#pragma once
#include "Shape.h"
#include <vector>
#include <memory>

namespace rt
{
	class ShapeWorld
	{
	public:
		ShapeWorld();
		void Add(const Shape& shape);

		auto begin() { return m_Test.begin(); }
		auto end() { return m_Test.end(); }

	private:
		using ShapePtr = std::unique_ptr<Shape>;
		std::vector<ShapePtr> m_Test;
	};
}
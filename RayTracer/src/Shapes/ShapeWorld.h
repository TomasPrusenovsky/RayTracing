#pragma once
#include "Shape.h"
#include <vector>

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
		std::vector<int> m_Test;
	};
}
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
}
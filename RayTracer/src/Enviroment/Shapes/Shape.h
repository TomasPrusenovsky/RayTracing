#pragma once
#include "Utils/Ray.h"

namespace rt
{
	class Shape
	{
	public:
		virtual const HitInfo Intersection(const Ray& ray) const = 0;

	protected:
		Material m_Material = {};
	};
}

#pragma once
#include "Utils/Ray.h"
#include "imgui.h"


namespace rt
{
	class Shape
	{
	public:
		virtual const HitInfo Intersection(const Ray& ray) const = 0;
		void Export();

	protected:
		Material m_Material = {};
	};
}

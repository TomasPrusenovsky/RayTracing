#pragma once
#include "Utils/Ray.h"
#include "imgui.h"


namespace rt
{
	class Shape
	{
	public:
		virtual const HitInfo Intersection(const Ray& ray) const = 0;
		virtual void Export() = 0;

		// must be called between ImGui::Begin() and ImGui::End();
		void MaterialExport();

	protected:
		Material m_Material = {};
	};
}

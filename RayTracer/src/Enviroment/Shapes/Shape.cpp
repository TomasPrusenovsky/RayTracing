#include "Shape.h"

namespace rt
{
	void Shape::Export()
	{
		ImGui::Begin("TestWindow");
		ImGui::ColorEdit3("Albedo", &m_Material.albedo.r);
		ImGui::End();
	}
}
#include "Shape.h"

namespace rt
{
	void Shape::MaterialExport()
	{
		ImGui::ColorEdit3("Albedo", &m_Material.albedo.r);
	}
}
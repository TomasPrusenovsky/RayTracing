#include "Shape.h"

namespace rt
{
	void Shape::MaterialExport()
	{
		ImGui::ColorEdit3("Albedo", &m_Material.albedo.r);
		ImGui::DragFloat("Specular", &m_Material.specularProbability, 0.01f, 0.0f, 1.0f);
		ImGui::DragFloat("Smoothness", &m_Material.smoothness, 0.01f, 0.0f, 1.0f);
		ImGui::Checkbox("Light Source", &m_Material.isLightSource);
		ImGui::Checkbox("Metalic", &m_Material.isMetalic);

		if (m_Material.isLightSource)
		{
			ImGui::ColorEdit3("LightColor", &m_Material.emissionColor.r);
			ImGui::DragFloat("Emission strenght", &m_Material.emissionStrenght, 0.01f, 0.0f, 1.0f);
		}
	}
}
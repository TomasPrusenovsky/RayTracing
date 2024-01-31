#include "RtLayer.h"

void RtLayer::OnUpdate()
{
	s_RayTracer.Trace();
	auto& image = s_RayTracer.GetImage();
	m_ImageTexture.Update(image);
}

void RtLayer::OnImGuiUpdate()
{
	RtExport();
	auto& image = s_RayTracer.GetImage();

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	ImGui::Begin("Image");
	s_RayTracer.Resize(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y);
	ImGui::Image((ImTextureID)m_ImageTexture.GetID(), { static_cast<float>(image.Width()), static_cast<float>(image.Height()) });
	ImGui::End();
	ImGui::PopStyleVar();
}

void RtLayer::RtExport()
{
	for (auto&& shape : s_RayTracer.Shapes())
		shape->Export();
	
	auto& rtSettings = s_RayTracer.RtSettings();
	ImGui::Begin("Settings");
	ImGui::Checkbox("Accumulate", &rtSettings.accumulate);
	ImGui::Checkbox("Gamma Corection", &rtSettings.gammaCorection);
	ImGui::Checkbox("AntiAliasing", &rtSettings.antialiasing);

	if (s_RayTracer.RtWorld().HasSkybox())
		ImGui::Checkbox("Background", &s_RayTracer.RtWorld().GetSettings().showSkybox);
	ImGui::End();
}

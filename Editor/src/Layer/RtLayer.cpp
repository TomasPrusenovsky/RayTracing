#include "RtLayer.h"

RtLayer::RtLayer()
{
	s_RayTracer.RtWorld().LoadSkybox("assets/skyboxes/container_free_Ref.hdr");
}

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
	s_RayTracer.Export();
}

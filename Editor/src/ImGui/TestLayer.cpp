#include "TestLayer.h"
#include "imgui.h"
#include <iostream>

TestLayer::TestLayer() :
	m_RayTracer(400, 300)
{
}

void TestLayer::OnUpdate()
{
	m_RayTracer.Trace();
	const rt::Image& image = m_RayTracer.GetImage();
	m_ImageTexture.Update(image.Width(), image.Height(), image.GetData());
}

void TestLayer::OnImGuiUpdate()
{
	const rt::Image& image = m_RayTracer.GetImage();

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	ImGui::Begin("Image");
	m_RayTracer.Resize(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y);
	ImGui::Image((ImTextureID)m_ImageTexture.GetID(), { static_cast<float>(image.Width()), static_cast<float>(image.Height()) });
	ImGui::End();
	ImGui::PopStyleVar();
}
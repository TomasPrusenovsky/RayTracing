#include "Editor.h"

#include "Layer/TestLayer.h"
#include "Layer/RtLayer.h"
#include "Layer/SkyboxLayer.h"

Editor::Editor() : m_Window(Window("Ray Tracer")),
m_ImGui(m_Window.GetWinPtr())
{
	m_ImGuiLayers.push_back(std::make_unique<RtLayer>());
	m_ImGuiLayers.push_back(std::make_unique<SkyboxLayer>());

}

void Editor::Run()
{
	while (m_Window.IsRunning())
	{
		m_ImGui.OnUpdate();

		for (auto&& layer : m_ImGuiLayers)
		{
			layer->OnUpdate();
			layer->OnImGuiUpdate();
		}

		m_ImGui.Render();
		m_Window.OnUpdate();
	}
}
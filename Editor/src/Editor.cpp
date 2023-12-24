#include "Editor.h"

#include "Layer/RtLayer.h"
#include "Layer/SkyboxLayer.h"
#include "Layer/MenuLayer.h"

Editor::Editor() : m_Window(Window("Ray Tracer")),
m_ImGui(m_Window.GetWinPtr())
{
	m_ImGuiLayers.push_back(std::make_unique<RtLayer>());
	m_ImGuiLayers.push_back(std::make_unique<SkyboxLayer>());
	m_ImGuiLayers.push_back(std::make_unique<MenuLayer>());
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
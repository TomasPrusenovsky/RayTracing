#include "Editor.h"

#include "Layers/RtLayer.h"
#include "Layers/SkyboxLayer.h"
#include "Layers/MenuLayer.h"
#include "Layers/TestLayer.h"

Editor::Editor() : m_Window(Window("Ray Tracer")),
m_ImGui(m_Window.GetWinPtr())
{
	m_ImGui.EnableDarkMode();

	m_Layers.push_back(std::make_unique<RtLayer>());
	m_Layers.push_back(std::make_unique<SkyboxLayer>());
	m_Layers.push_back(std::make_unique<MenuLayer>());
	m_Layers.push_back(std::make_unique<TestLayer>());
}

void Editor::Run()
{
	while (m_Window.IsRunning())
	{
		m_ImGui.OnUpdate();

		for (auto&& layer : m_Layers)
		{
			layer->OnUpdate();
			layer->OnImGuiUpdate();
		}

		m_ImGui.Render();
		m_Window.OnUpdate();
	}
}
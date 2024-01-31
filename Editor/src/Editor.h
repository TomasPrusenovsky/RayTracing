#pragma once

#include "Window/Window.h"
#include <memory>
#include <vector>

#include "ImGui/ImGuiRenderer.h"
#include "Layer/Layer.h"

class Editor
{
public:
	Editor();

	void Run();
private:
	using Layers = std::vector<std::unique_ptr<Layer>>;

	Window m_Window;
	ImGuiRenderer m_ImGui;
	Layers m_Layers;
};

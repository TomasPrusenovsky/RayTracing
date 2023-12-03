#ifndef EDITOR_H
#define EDITOR_H

#include "Window.h"
#include <memory>
#include <vector>

#include "ImGui/ImGuiRenderer.h"
#include "ImGui/ImGuiLayer.h"

class Editor {
public:
    Editor();

    void Run();
private:
    using ImGuiLayers = std::vector<std::unique_ptr<ImGuiLayer>>;

    Window m_Window;
    ImGuiRenderer m_ImGui;
    ImGuiLayers m_ImGuiLayers;
};



#endif //EDITOR_H

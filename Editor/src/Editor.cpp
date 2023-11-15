#include "Editor.h"

Editor::Editor() :
    m_Window(Window("Ray Tracer")),
    m_ImGui(m_Window.GetWinPtr()){
}

void Editor::Run() {
    while (m_Window.IsRunning()) {
        m_ImGui.OnUpdate();

        m_ImGui.Render();
        m_Window.OnUpdate();
    }
}

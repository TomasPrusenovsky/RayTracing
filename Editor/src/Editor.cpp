#include "Editor.h"

Editor::Editor() :
    m_Window(Window("Ray Tracer"))
{}

void Editor::Run() {
    while (m_Window.IsRunning()) {
        m_Window.OnUpdate();
    }
}

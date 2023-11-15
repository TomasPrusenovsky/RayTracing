#ifndef EDITOR_H
#define EDITOR_H

#include "Window.h"
#include <memory>
#include "ImGui/ImGuiLayer.h"

class Editor {
public:
    Editor();

    void Run();
private:
    Window m_Window;
    ImGuiLayer m_ImGui;
};



#endif //EDITOR_H

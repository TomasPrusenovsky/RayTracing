
#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include <string>
#include "GLFW/glfw3.h"

class ImGuiLayer {
public:
    ImGuiLayer(GLFWwindow* window);
    ~ImGuiLayer();

    void OnUpdate(); // Needs to be called before Render()
    void Render();

private:
    void Init();
private:
    const std::string m_GLSL_version = "#version 460";
    GLFWwindow* m_GLFWwindow = nullptr;
};

#endif //IMGUILAYER_H

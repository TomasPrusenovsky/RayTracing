
#ifndef IMGUIRENDERER_H
#define IMGUIRENDERER_H

#include <string>
#include "GLFW/glfw3.h"
#include "../OpenGL/Texture.h"

class ImGuiRenderer {
public:
    ImGuiRenderer(GLFWwindow* window);
    ~ImGuiRenderer();

    void OnUpdate(); // Needs to be called before Render()
    void Render();

private:
    void Init();

    const std::string m_GLSL_version = "#version 400";
    GLFWwindow* m_GLFWwindow = nullptr;

    OpenGL::Texture m_Texture;
};

#endif //IMGUIRENDERER_H
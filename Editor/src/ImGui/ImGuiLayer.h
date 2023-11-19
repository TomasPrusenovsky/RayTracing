
#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include <string>
#include "GLFW/glfw3.h"
#include "../OpenGL/Texture.h"

class ImGuiLayer {
public:
    ImGuiLayer(GLFWwindow* window);
    ~ImGuiLayer();

    void OnUpdate(); // Needs to be called before Render()
    void Render();

private:
    void Init();

    const std::string m_GLSL_version = "#version 400";
    GLFWwindow* m_GLFWwindow = nullptr;

    OpenGL::Texture m_Texture;

    int width = 1280;
    int height = 720;

};

#endif //IMGUILAYER_H

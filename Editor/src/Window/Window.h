#ifndef RAYTRACING_WINDOW_H
#define RAYTRACING_WINDOW_H

#include "../rtpch.h"
#include "GLFW/glfw3.h"

class Window {
public:
    Window(
        const std::string&name,
        int width = 1280,
        int height = 720);

    ~Window();

    void SetVSync(bool enabled);

    void OnUpdate() const;

    int GetWidth() const { return m_Data.Width; }
    int GetHeight() const { return m_Data.Height; }

    bool IsRunning() const { return m_Data.ShouldRun; }

    GLFWwindow* GetWinPtr() const { return m_Window; }

private:
    static void InitializeOpenGL();

    void GLFWCallBacks();

private:
    GLFWwindow* m_Window = nullptr;
    static bool s_GLFWisInitialized;
    static bool s_OpenGLInitialized;

    struct WinData {
        std::string Title;
        int Width, Height;
        bool VSync = true;
        bool ShouldRun = true;
    };

    WinData m_Data;
};

#endif //RAYTRACING_WINDOW_H

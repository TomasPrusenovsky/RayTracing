//
// Created by tomas on 11/6/2023.
//

#ifndef RAYTRACING_WINDOW_H
#define RAYTRACING_WINDOW_H


#include "rtpch.h"
#include "GLFW/glfw3.h"

namespace Editor {

    class Window {
    public:
        Window(
                const std::string &name = "Ray Tracer",
                int width = 1280,
                int height = 720);

        void SetVSync(bool enabled) { m_Data.VSync = enabled; }

        int GetWidth() { return m_Data.Width; }
        int GetHeight() { return m_Data.Height; }

    private:
        GLFWwindow *m_Window = nullptr;
        static bool s_GLFWisInitialize;

        struct WinData {
            std::string Title;
            int Width, Height;
            bool VSync = true;
        };

        WinData m_Data;
    };

} // Editor

#endif //RAYTRACING_WINDOW_H

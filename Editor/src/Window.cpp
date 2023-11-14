//
// Created by tomas on 11/6/2023.
//
#include "rtpch.h"
#include "Window.h"

namespace Editor {

    bool Window::s_GLFWisInitialize = false;

    Window::Window(const std::string &name, const int width, const int height) :
            m_Data(name, width, height) {

        if (!s_GLFWisInitialize) {
            int success = glfwInit();
            if (!success) {
                std::cerr << "Failed to initialize Window" << std::endl;
            }
            m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
            s_GLFWisInitialize = true;
        }
    }
} // Editor
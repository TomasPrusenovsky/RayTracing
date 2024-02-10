#pragma once
#include "../rtpch.h"
#include "GLFW/glfw3.h"

#include <glm/glm.hpp>

class Window
{
public:
	Window(
		const std::string& name,
		int width = 1280,
		int height = 720);

	~Window();

	void SetVSync(bool enabled);
	void HideCursor() const { glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); };
	void ShowCursor() const { glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); }

	void OnUpdate() const;

	int GetWidth() const { return m_Data.Width; }
	int GetHeight() const { return m_Data.Height; }

	bool IsRunning() const { return m_Data.ShouldRun; }

	GLFWwindow* GetWinPtr() const { return m_Window; }

	bool MousePressed(int key) const;
	bool MouseReleased(int key) const;
	glm::vec2 MousePos() const; // TODO: set callback
	void MousePos(float x, float y) const;

	bool KeyPressed(int key) const;

private:
	static void InitializeOpenGL();

	void GLFWCallBacks();

private:
	GLFWwindow* m_Window = nullptr;
	static bool s_GLFWisInitialized;
	static bool s_OpenGLInitialized;

	struct WinData
	{
		std::string Title;
		int Width, Height;
		bool VSync = true;
		bool ShouldRun = true;
	};

	WinData m_Data;
};
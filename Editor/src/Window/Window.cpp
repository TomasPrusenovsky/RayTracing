#include "../rtpch.h"
#include "Window.h"
#include "glad/glad.h"

bool Window::s_GLFWisInitialized = false;
bool Window::s_OpenGLInitialized = false;

Window::Window(const std::string& name, const int width, const int height) :
	m_Data(name, width, height)
{
	if (!s_GLFWisInitialized)
	{
		int success = glfwInit();
		if (!success)
		{
			std::cerr << "Failed to initialize Window" << std::endl;
		}
		s_GLFWisInitialized = true;
	}

	m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_Window);
	SetVSync(true);
	s_GLFWisInitialized = true;

	glfwSetWindowUserPointer(m_Window, &m_Data);
	InitializeOpenGL();

	GLFWCallBacks();
}

Window::~Window()
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();
	s_GLFWisInitialized = false;
}

void Window::SetVSync(bool enabled)
{
	m_Data.VSync = enabled;
	glfwSwapInterval(m_Data.VSync);
}

void Window::OnUpdate() const
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

bool Window::MousePressed(int key) const
{
	return glfwGetMouseButton(m_Window, key) == GLFW_PRESS;
}

bool Window::MouseReleased(int key) const
{
	return glfwGetMouseButton(m_Window, key) == GLFW_RELEASE;
}

glm::vec2 Window::MousePos() const
{
	double x, y;
	glfwGetCursorPos(m_Window, &x, &y);
	return { (float)x, (float)y };
}

void Window::MousePos(float x, float y) const
{
	glfwSetCursorPos(m_Window, (double)x, (double)y);
}

bool Window::KeyPressed(int key) const
{
	return glfwGetKey(m_Window, key) == GLFW_PRESS;
}

void Window::InitializeOpenGL()
{
	s_OpenGLInitialized = true;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (!gladLoadGL())
		std::cerr << "Error loading OpenGL!" << std::endl;
}

void Window::GLFWCallBacks()
{
	glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WinData& data = *static_cast<WinData*>(glfwGetWindowUserPointer(window));
			data.ShouldRun = false;
		});

	glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WinData& data = *static_cast<WinData*>(glfwGetWindowUserPointer(window));
			data.Width = width;
			data.Height = height;
		});

	// TODO: 
	//glfwSetCursorPosCallback(m_Window, [](GLFWwindow* windwo, int x,))

}
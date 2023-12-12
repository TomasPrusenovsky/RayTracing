#pragma once
#include <string>
#include "GLFW/glfw3.h"

class ImGuiRenderer
{
public:
	ImGuiRenderer(GLFWwindow* window);
	~ImGuiRenderer();

	void OnUpdate(); // Needs to be called before Render()
	void Render();

private:
	void Init();

	const std::string m_GLSL_version = "#version 460";
	GLFWwindow* m_GLFWwindow = nullptr;
};
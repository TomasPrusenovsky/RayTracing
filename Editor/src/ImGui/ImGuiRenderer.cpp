#include "ImGuiRenderer.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Platform/Platforms.h"
#include "../OpenGL/OpenGL.h"

ImGuiRenderer::ImGuiRenderer(GLFWwindow* window) : m_GLFWwindow(window)
{
	Init();
}

ImGuiRenderer::~ImGuiRenderer()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void ImGuiRenderer::Init()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable Docking
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	ImGui::StyleColorsDark();
	io.FontGlobalScale = Platform::GetDpiScale();

	ImGui_ImplGlfw_InitForOpenGL(m_GLFWwindow, true);
	ImGui_ImplOpenGL3_Init(m_GLSL_version.c_str());
}

void ImGuiRenderer::OnUpdate()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	ImGui::DockSpaceOverViewport();
}

void ImGuiRenderer::Render()
{
	ImGui::Render();
	OpenGL::ClearColor(0, 0, 0, 1);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}
}
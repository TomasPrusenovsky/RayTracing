#include "MenuLayer.h"
#include "stb_image_write.h"
#include "imgui_stdlib.h"

void MenuLayer::OnUpdate()
{
}

void MenuLayer::OnImGuiUpdate()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("Image"))
		{
			if (ImGui::MenuItem("Save"))
			{
				m_ShowSavePopup = true;
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	if (m_ShowSavePopup)
		ImGui::OpenPopup("Image Save");

	if (ImGui::BeginPopup("Image Save"))
	{
		ImGui::InputText("Name", &m_Filename);

		if (m_SaveEmpty)
			ImGui::Text("You have to provide file name");

		if (ImGui::Button("Save"))
		{
			if (m_Filename.empty())
				m_SaveEmpty = true;
			else
			{
				m_SaveEmpty = false;
				SavePng();
				m_Filename.clear();

				ImGui::CloseCurrentPopup();
				m_ShowSavePopup = false;
			}
		}



		if (ImGui::Button("Cancel"))
		{
			ImGui::CloseCurrentPopup();
			m_SaveEmpty = false;
			m_ShowSavePopup = false;
		}
		ImGui::EndPopup();
	}
}

void MenuLayer::SavePng()
{
	auto& image = s_RayTracer.GetImage();
	auto data = image.GetData();
	std::unique_ptr<uint8_t[]> RGBAimage = std::make_unique<uint8_t[]>(image.Size());

	for (uint32_t y = 0; y < image.Height(); ++y)
	{
		for (uint32_t x = 0; x < image.Width(); ++x)
		{
			uint32_t index = (y * image.Width() + x) * image.Chanels();

			RGBAimage[index + 0] = data[index + 0] * 255.0f;
			RGBAimage[index + 1] = data[index + 1] * 255.0f;
			RGBAimage[index + 2] = data[index + 2] * 255.0f;
			RGBAimage[index + 3] = data[index + 3] * 255.0f;

		}
	}
	
	stbi_write_png((m_Filename + ".png").c_str(), image.Width(), image.Height(), image.Chanels(), RGBAimage.get(), image.Width() * image.Chanels());
}


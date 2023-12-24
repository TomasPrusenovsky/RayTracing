#include "SkyboxLayer.h"

void SkyboxLayer::OnUpdate()
{
}

void SkyboxLayer::OnImGuiUpdate()
{
    ImGui::Begin("Content Browser");

    if (m_currentDir != std::filesystem::path(m_assetsDir))
    {
        if (ImGui::Button("<-"))
        {
            m_currentDir = m_currentDir.parent_path();
        }
    }

    if (std::filesystem::exists(m_currentDir))
    {
        for (auto& p : std::filesystem::directory_iterator(m_currentDir))
        {
            std::string path = p.path().string();
            if (p.is_directory())
            {
                if (ImGui::Button(path.c_str()))
                {
                    m_currentDir /= p.path().filename();
                }
            }

            if (!p.is_directory())
            {
                if (ImGui::Button(p.path().filename().string().c_str()))
                {
                    if (p.path().extension() == ".hdr")
                    {
                        s_RayTracer.RtWorld().LoadSkybox(path);
                    }
                }
            }
        }
    }
    ImGui::End();
}

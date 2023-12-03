
#include "TestLayer.h"
#include "imgui.h"
#include <iostream>


TestLayer::TestLayer() {
    int width = 800;
    int height = 1000;
    uint32_t size = width * height * 4;
    auto* image = new float[size];

    for (int i = 0; i < size; ++i) {
        image[i] = 1.0f;
    }
    m_Image.Update(width, height, image);
    delete[] image;
}

void TestLayer::OnUpdate() {
    ImGui::Begin("Test window");
    if (ImGui::Button("Hello button"))
        std:: cout << "Hello world" << std::endl;
    ImGui::End();

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("Image");
    ImGui::Image((ImTextureID)m_Image.GetID(), {800, 1000});
    ImGui::End();
    ImGui::PopStyleVar();
}

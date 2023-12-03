#ifndef TESTLAYER_H
#define TESTLAYER_H

#include "ImGuiLayer.h"

// for test TODO: move this else
#include "../OpenGL/Texture.h"

class TestLayer : public ImGuiLayer {
public:
    TestLayer();

    ~TestLayer() override = default;
    void OnUpdate() override;

private:
    OpenGL::Texture m_Image;
};


#endif //TESTLAYER_H

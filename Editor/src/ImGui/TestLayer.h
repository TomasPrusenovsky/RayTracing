#ifndef TESTLAYER_H
#define TESTLAYER_H

#include "Layer.h"
#include "RayTracer.h"

// for test TODO: move this else
#include "../OpenGL/Texture.h"

class TestLayer : public Layer {
public:
    TestLayer();

    ~TestLayer() override = default;
    void OnUpdate() override;
    void OnImGuiUpdate() override;

private:
    OpenGL::Texture m_ImageTexture;
    rt::RayTracer m_RayTracer;
};


#endif //TESTLAYER_H

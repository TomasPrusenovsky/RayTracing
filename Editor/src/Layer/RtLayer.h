#pragma once
#include "Layer.h"
#include "RayTracer.h"

// for test TODO: move this else
#include "../OpenGL/Texture.h"

class RtLayer : public Layer
{
public:
	RtLayer();

	~RtLayer() override = default;
	void OnUpdate() override;
	void OnImGuiUpdate() override;

private:
	OpenGL::Texture m_ImageTexture;

private:
	void RtExport();
};
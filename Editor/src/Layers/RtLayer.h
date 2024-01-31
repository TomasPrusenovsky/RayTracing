#pragma once
#include "Layer/Layer.h"
#include "RayTracer.h"

#include "OpenGL/Texture.h"

class RtLayer : public Layer
{
public:
	RtLayer() = default;

	~RtLayer() override = default;
	void OnUpdate() override;
	void OnImGuiUpdate() override;

private:
	OpenGL::Texture m_ImageTexture;

private:
	void RtExport();
};
#pragma once
#include "Camera.h"
#include "Image/Image.h"
#include "Image/AccImage.h"
#include "Scene/Scene.h"
#include "Enviroment/World.h"

#include <imgui.h>
#include <memory>
#include <vector>

namespace rt
{
	class RayTracer
	{
	public:
		RayTracer(int width, int height);

		void SetScene(const Scene& scene) { m_ActiveScene = &scene; } // For now does nothing
		void Trace();
		void Resize(int width, int height);
		void Export();
		const Image& GetImage() const { return *m_Image; }
		const World::ShapeList& Shapes() const { return m_World.Shapes(); }
		World& RtWorld() { return m_World; }

	private:
		using ImagePtr = std::unique_ptr<Image>;
		struct Settings
		{
			uint16_t maxBounces = 20;
			bool accumulate = true;
			bool gammaCorection = true;
		};
		Settings m_Settings;

		uint32_t m_FrameIndex = 1;

		World m_World;
		Camera m_Camera;
		ImagePtr m_Image;
		std::unique_ptr<AccImage> m_AccumulationImage;
		const Scene* m_ActiveScene = nullptr;

	private:
		color Trace(Ray& ray);
	};
} // rt
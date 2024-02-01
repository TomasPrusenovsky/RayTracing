#pragma once
#include "Camera.h"
#include "Image/Image.h"
#include "Image/AccImage.h"
#include "Scene/Scene.h"
#include "Enviroment/World.h"

#include <imgui.h>
#include <memory>
#include <vector>
#include <functional>

namespace rt
{
	class RayTracer
	{
	public:
		RayTracer(int width, int height);

		void SetScene(const Scene& scene) { m_ActiveScene = &scene; } // For now does nothing
		void Trace();
		void Raster();
		void Resize(int width, int height);
		const Image& GetImage() const { return *m_Image; }
		const World::ShapeList& Shapes() const { return m_World.Shapes(); }
		World& RtWorld() { return m_World; }

		struct Settings
		{
			uint16_t maxBounces = 20;
			bool accumulate = false;
			bool gammaCorection = true;
			bool antialiasing = true;
		};
		Settings& RtSettings() { return m_Settings; }

	private:
		using ImagePtr = std::unique_ptr<Image>;

		Settings m_Settings;

		uint32_t m_FrameIndex = 1;

		World m_World;
		Camera m_Camera;
		ImagePtr m_Image;
		std::unique_ptr<AccImage> m_AccumulationImage;
		const Scene* m_ActiveScene = nullptr;

	private:
		color Trace(Ray& ray);
		color Raster(const Ray& ray); 
		void NewImage(int width, int height);
		void PerPixel(std::function<void(uint32_t, uint32_t)> func);

	};
} // rt
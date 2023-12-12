#pragma once
#include "Camera.h"
#include "Image/Image.h"
#include "Scene/Scene.h"
#include <memory>

namespace rt
{
	class RayTracer
	{
	public:
		RayTracer(int width, int height);

		void SetScene(const Scene& scene) { m_ActiveScene = &scene; }
		void Trace();
		void Resize(int width, int height);
		const Image& GetImage() const { return *m_Image; }

	private:
		Camera m_Camera;
		std::unique_ptr<Image> m_Image;
		const Scene* m_ActiveScene = nullptr;
	};
} // rt
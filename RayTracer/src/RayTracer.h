#pragma once
#include "Camera.h"
#include "Image/Image.h"
#include "Scene/Scene.h"
#include <memory>
#include<vector>

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
		// TODO: move this to image class
		using Iterator = std::vector<uint32_t>;
		Iterator m_VerticalIter;
		void IterResize(uint32_t width);
		////////////////////////////////////////////////
		Camera m_Camera;
		std::unique_ptr<Image> m_Image;
		const Scene* m_ActiveScene = nullptr;
	};
} // rt
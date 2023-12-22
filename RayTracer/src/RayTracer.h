#pragma once
#include "Camera.h"
#include "Image/Image.h"
#include "Scene/Scene.h"
#include "Enviroment/World.h"

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
		const Image& GetImage() const { return *m_Image; }
		const World::ShapeList& Shapes() const { return m_World.Shapes(); }

	private:
		World m_World;
		Camera m_Camera;
		std::unique_ptr<Image> m_Image;
		const Scene* m_ActiveScene = nullptr;
	};
} // rt
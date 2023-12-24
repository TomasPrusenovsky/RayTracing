#pragma once
#include "Shapes/ShapeWorld.h"
#include "stb_image.h"

#define PI 3.1415926538f

namespace rt
{

	class World : public ShapeWorld
	{
	public:
		World();
		color Background();
		void LoadSkybox(const std::string& file);
		color SkyboxColor(const Ray& ray);

	private:
		struct Skybox
		{
			std::string file;
			float* image = nullptr;
			int x = 0;
			int y = 0;
			int chanels = 4;
		};


		Skybox m_Skybox;
	};
}
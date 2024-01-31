#pragma once
#include "Shapes/ShapeWorld.h"
#include <filesystem>
#include "stb_image.h"

#define PI 3.1415926538f

namespace rt
{

	class World : public ShapeWorld
	{
	public:
		struct Settings
		{
			bool showSkybox = false;
		};

		World();
		color Background(const Ray& ray);
		void LoadSkybox(const std::string& file);
		color SkyboxColor(const Ray& ray);
		bool HasSkybox() const { return !m_Skybox.file.empty(); }
		Settings& GetSettings() { return m_Settings; }

	private:
		struct Skybox
		{
			std::string file;
			float* image = nullptr;
			int x = 0;
			int y = 0;
			int chanels = 4;
		};

		Settings m_Settings;

		Skybox m_Skybox;
	};
}
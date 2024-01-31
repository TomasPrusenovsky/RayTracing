#include "World.h"
#include <iostream>

namespace rt
{
	World::World()
	{
	}

	color World::Background(const Ray& ray)
	{
		if (m_Settings.showSkybox)
			return SkyboxColor(ray);

		return Color::Black;
	}

	void World::LoadSkybox(const std::string& file)
	{
		delete[] m_Skybox.image;

		m_Skybox.file = file;

		stbi_set_flip_vertically_on_load(true);
		m_Skybox.image = stbi_loadf(m_Skybox.file.c_str(), &m_Skybox.x, &m_Skybox.y, &m_Skybox.chanels, 0);
	}

	color World::SkyboxColor(const Ray& ray)
	{
		glm::vec3 dir = glm::normalize(ray.Direction());
		float u = 0.5f + (glm::atan(dir.x, dir.z)) / (2.0f * PI);
		float v = 0.5f + (glm::asin(dir.y)) / PI;

		int x = (int)(u * (m_Skybox.x - 1));
		int y = (int)(v * (m_Skybox.y - 1));

		int index = (x + y * m_Skybox.x) * m_Skybox.chanels;

		color color = { m_Skybox.image[index + 0], m_Skybox.image[index + 1], m_Skybox.image[index + 2], 1.0f };

		return color;
	}
}
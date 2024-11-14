#pragma once
#include <glm/glm.hpp>

namespace rt
{
	using color = glm::vec4;
	struct Material
	{
		color albedo;
		bool isLightSource = false;
		color emissionColor = color{ 1.0f };
		color specularColor = color{ 1.0f };
		float emissionStrenght = 0.0f;
		float smoothness = 0.90f;
		float specularProbability = 0.0f;
		bool isMetalic = false;
	};

	class Color
	{
	public:
		static const color Black;
		static const color White;
		static const color Red;
		static const color Green;
		static const color Blue;
		static const color Magenta;
		static const color Yellow;
		static const color Cyan;
	};
}

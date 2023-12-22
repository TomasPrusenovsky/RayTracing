#pragma once
#include <glm/glm.hpp>

namespace rt
{
	using color = glm::vec4;
	struct Material
	{
		color albedo;
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

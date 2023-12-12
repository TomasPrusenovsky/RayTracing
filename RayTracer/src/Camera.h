#pragma once
#include "Utils/Ray.h"
#include "Image/Image.h"

namespace rt
{
	class Camera
	{
	public:
		Camera(float FOV, point position, direction direction);
		void SetImageSize(uint32_t widht, uint32_t height);
		Ray GetRay(uint32_t x, uint32_t y) const;
		void Recalculate(const Image& image);

	private:

	private:
		struct ViewPlane
		{
			float width;
			float height;
			glm::vec3 u;
			glm::vec3 v;
			glm::vec3 u_delta;
			glm::vec3 v_delta;
			glm::vec3 upperLeft;
			glm::vec3 pixel_loc00;
		};

		float m_FOV;

		point m_Position;
		direction m_Derection;

		float m_FocalLen;
		ViewPlane m_ViewPlane;
	};
} // rt
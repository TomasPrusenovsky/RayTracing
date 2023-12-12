#include "Camera.h"
#include "Debug/Debug.h"

namespace rt
{
	Camera::Camera(float FOV, point position, direction direction) :
		m_FOV(FOV), m_Position(position), m_Derection(direction),
		m_FocalLen(1.0f)
	{	
	}

	Ray Camera::GetRay(uint32_t x, uint32_t y) const
	{
		auto pixelCenter = m_ViewPlane.pixel_loc00 + ((float)x * m_ViewPlane.u_delta) + ((float)y * m_ViewPlane.v_delta);
		auto direction = pixelCenter - m_Position;
		return { m_Position, direction };
	}

	void Camera::Recalculate(const Image& image)
	{
		m_ViewPlane.height = 2.0f;
		m_ViewPlane.width = m_ViewPlane.height * image.AspectRatio();
		m_ViewPlane.u = glm::vec3(m_ViewPlane.width, 0.0f, 0.0f);
		m_ViewPlane.v = glm::vec3(0.0f, -m_ViewPlane.height, 0.0f);
		m_ViewPlane.u_delta = m_ViewPlane.u / (float)image.Width();
		m_ViewPlane.v_delta = m_ViewPlane.v / (float)image.Height();
		m_ViewPlane.upperLeft = m_Position - glm::vec3(0, 0, m_FocalLen) - m_ViewPlane.u / 2.0f - m_ViewPlane.v / 2.0f;
		m_ViewPlane.pixel_loc00 = m_ViewPlane.upperLeft + 0.5f * (m_ViewPlane.u_delta + m_ViewPlane.v_delta);
	}
} // rt
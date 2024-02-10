#include "Camera.h"
#include "Debug/Debug.h"
#include "Math/Random.h"

namespace rt
{
	//Camera::Camera(float FOV, point position, direction direction) :
	//	m_FOV(FOV), m_Position(position), m_Derection(direction),
	//	m_FocalLen(1.0f)
	//{	
	//}

	//Ray Camera::GetRay(uint32_t x, uint32_t y, bool antialiasing) const
	//{
	//	const glm::vec2 offset = antialiasing ? Random::Vec2(-0.5f, 0.5f) : glm::vec2(0.0f);
	//	const glm::vec2 aaPos = glm::vec2((float)x + offset.x, (float)y + offset.y);

	//	auto pixelCenter = m_ViewPlane.pixel_loc00 + (aaPos.x * m_ViewPlane.u_delta) + (aaPos.y * m_ViewPlane.v_delta);
	//	auto direction = pixelCenter - m_Position;
	//	return { m_Position, direction };
	//}

	//void Camera::Recalculate(const Image& image)
	//{
	//	m_ViewPlane.height = 2.0f;
	//	m_ViewPlane.width = m_ViewPlane.height * image.AspectRatio();
	//	m_ViewPlane.u = glm::vec3(m_ViewPlane.width, 0.0f, 0.0f);
	//	m_ViewPlane.v = glm::vec3(0.0f, -m_ViewPlane.height, 0.0f);
	//	m_ViewPlane.u_delta = m_ViewPlane.u / (float)image.Width();
	//	m_ViewPlane.v_delta = m_ViewPlane.v / (float)image.Height();
	//	m_ViewPlane.upperLeft = m_Position - glm::vec3(0, 0, m_FocalLen) - m_ViewPlane.u / 2.0f - m_ViewPlane.v / 2.0f;
	//	m_ViewPlane.pixel_loc00 = m_ViewPlane.upperLeft + 0.5f * (m_ViewPlane.u_delta + m_ViewPlane.v_delta);
	//}



    Camera::Camera(
        glm::vec3 lookfrom,
        glm::vec3 lookat,
        glm::vec3 vup,
        float vfov, // vertical field-of-view in degrees
        float aspect_ratio
    )
    {
        m_position = lookfrom;
        m_positionOld = lookfrom;
        m_lookat = lookat;
        m_up = vup;
        m_settings.vfov = glm::radians(vfov);
        m_aspect_ratio = aspect_ratio;

        float h = glm::tan(m_settings.vfov / 2.0f);
        float viewport_height = 2.0f;
        float viewport_width = aspect_ratio * viewport_height;
        viewport_height *= h;

        m_orientation = glm::normalize(lookfrom - lookat);
        glm::vec3 u = glm::normalize(glm::cross(vup, m_orientation));
        glm::vec3 v = glm::cross(m_orientation, u);

        m_viewPlane.Recalculate(m_position, viewport_width * u, viewport_height * v, m_orientation);
    }

    void Camera::Recalculate(float aspect_ratio)
    {
        m_aspect_ratio = aspect_ratio;
        float h = glm::tan(m_settings.vfov / 2.0f);
        float viewport_height = 2.0 * h;
        float viewport_width = m_aspect_ratio * viewport_height;

        m_lookat = m_lookat + m_position - m_positionOld;
        m_positionOld = m_position;
        m_orientation = glm::normalize(m_position - m_lookat);

        m_angles.y = glm::clamp(m_angles.y, glm::radians(-89.0f), glm::radians(89.0f));

        glm::quat quatx = glm::normalize(glm::angleAxis(m_angles.x, glm::vec3(0, 1, 0)));
        glm::quat quaty = glm::normalize(glm::angleAxis(m_angles.y, glm::vec3(1, 0, 0)));

        m_orientation = glm::rotate(quatx * quaty, m_orientation);
        glm::vec3 u = glm::normalize(glm::cross(m_up, m_orientation));
        glm::vec3 v = glm::cross(m_orientation, u);

        m_viewPlane.Recalculate(m_position, viewport_width * u, viewport_height * v, m_orientation);
    }

    Ray Camera::get_ray(uint32_t x, uint32_t y, bool antialiasing, glm::vec2 imageSize) const
    {
        const glm::vec2 offset = antialiasing ? Random::Vec2(-0.1f, 0.1f) : glm::vec2(0.0f);
        float s = ((float)(x) / (float)imageSize.x) + offset.x;
        float t = ((float)(y) / (float)imageSize.y) + offset.y;
        return Ray(m_viewPlane.origin, m_viewPlane.lower_left_corner + s * m_viewPlane.horizontal + t * m_viewPlane.vertical - m_viewPlane.origin);
    }
} // rt
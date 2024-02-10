#pragma once
#include "Utils/Ray.h"
#include "Image/Image.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/glm.hpp"
#include<glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <imgui.h>

namespace rt
{
	//class Camera
	//{
	//public:
	//	Camera(float FOV, point position, direction direction);
	//	Ray GetRay(uint32_t x, uint32_t y, bool antialiasing) const;
	//	void Recalculate(const Image& image);

	//	void Rotate(float angleX, float angleY);
	//	void Move(point newPos);

	//private:
	//	struct ViewPlane
	//	{
	//		float width;
	//		float height;
	//		glm::vec3 u;
	//		glm::vec3 v;
	//		glm::vec3 u_delta;
	//		glm::vec3 v_delta;
	//		glm::vec3 upperLeft;
	//		glm::vec3 pixel_loc00;
	//	};

	//	float m_FOV;

	//	point m_Position;
	//	direction m_Derection;

	//	float m_FocalLen;
	//	ViewPlane m_ViewPlane;
	//};





    static struct ViewPlane
    {
        glm::vec3 origin;
        glm::vec3 lower_left_corner;
        glm::vec3 horizontal;
        glm::vec3 vertical;

        void Recalculate(const glm::vec3& origin,
            const glm::vec3& horizontal,
            const glm::vec3& vertical,
            const glm::vec3& orientation)
        {
            this->origin = origin;
            this->horizontal = horizontal;
            this->vertical = vertical;
            this->lower_left_corner = origin - horizontal / 2.0f - vertical / 2.0f - orientation;
        }
    };

    static struct Settings
    {
        float vfov; // vertical field-of-view in RADIANS
        float speed = 10.0f;
        float mouseSensitivity = 70.0f;
    };

    class Camera
    {
    public:
        Camera(
            glm::vec3 lookfrom,
            glm::vec3 lookat,
            glm::vec3 vup,
            float vfov, // vertical field-of-view in degrees
            float aspect_ratio
        );

        Ray get_ray(uint32_t x, uint32_t y, bool antialiasing, glm::vec2 imageSize) const;

        void Recalculate(float aspect_ratio);
        bool IsMoving() const { return m_isMoving; }
        void IsMoving(bool state) { m_isMoving = state; }

        glm::vec3& Position() { return m_position; }
        glm::vec3& Orientation() { return m_orientation; }
        glm::vec2& Angles() { return m_angles; }

        Settings& GetSettings() { return m_settings; }

    private:
        bool m_isMoving = false;
        bool m_firstClick = true;

        ViewPlane m_viewPlane;
        Settings m_settings;

        float m_aspect_ratio;
        glm::vec3 m_position;
        glm::vec3 m_positionOld;
        glm::vec3 m_lookat;
        glm::vec3 m_up;
        glm::vec3 m_orientation;
        glm::vec2 m_angles = glm::vec2(0.0f);
    };
} // rt
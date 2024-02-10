#include "MoveLayer.h"

MoveLayer::MoveLayer(const Window& window) :
	m_ActiveWindow(window)
{
}

void MoveLayer::OnUpdate()
{
    CalculateMovement();
    s_RayTracer.GetCamera().Recalculate(s_RayTracer.GetImage().AspectRatio());
}

void MoveLayer::OnImGuiUpdate()
{
}

void MoveLayer::CalculateMovement()
{
    float winWidth = s_RayTracer.GetImage().DimensionsVec().x;
    float winHeight = s_RayTracer.GetImage().DimensionsVec().y;

    float deltaTime = s_RayTracer.RenderTime().timeDiff;
    auto& position = s_RayTracer.GetCamera().Position();
    auto& orientation = s_RayTracer.GetCamera().Orientation();
    auto& angles = s_RayTracer.GetCamera().Angles();

    if (m_ActiveWindow.MousePressed(GLFW_MOUSE_BUTTON_RIGHT))
    {
        m_ActiveWindow.HideCursor();
        m_Settings.isMoving = true;

        if (m_ActiveWindow.KeyPressed(GLFW_KEY_W))
        {
            position += m_Settings.speed * -orientation * deltaTime;
        }
        if (m_ActiveWindow.KeyPressed(GLFW_KEY_A))
        {
            position += m_Settings.speed * -glm::normalize(glm::cross(orientation, m_Up)) * deltaTime;
        }
        if (m_ActiveWindow.KeyPressed(GLFW_KEY_S))
        {
            position += m_Settings.speed * orientation * deltaTime;
        }
        if (m_ActiveWindow.KeyPressed(GLFW_KEY_D))
        {
            position += m_Settings.speed * glm::normalize(glm::cross(orientation, m_Up)) * deltaTime;
        }
        if (m_ActiveWindow.KeyPressed(GLFW_KEY_SPACE))
        {
            position += m_Settings.speed * m_Up * deltaTime;
        }
        if (m_ActiveWindow.KeyPressed(GLFW_KEY_LEFT_SHIFT))
        {
            position += m_Settings.speed * -m_Up * deltaTime;
        }

        if (m_Settings.firstClick)
        {
            m_ActiveWindow.MousePos(winWidth / 2, winHeight / 2);
            m_Settings.firstClick = false;
        }

        glm::vec2 mouse = m_ActiveWindow.MousePos();
        float mouseXNorm = 2.0f * mouse.x / winWidth - 1.0f;
        float mouseYNorm = 2.0f * mouse.y / winHeight - 1.0f;


        angles.x += mouseXNorm * m_Settings.mouseSensitivity * deltaTime;
        angles.y -= mouseYNorm * m_Settings.mouseSensitivity * deltaTime;
        angles.y = glm::clamp(angles.y, -89.0f, 89.0f);

        m_ActiveWindow.MousePos(winWidth / 2, winHeight / 2);
    }
    else if (m_ActiveWindow.MouseReleased(GLFW_MOUSE_BUTTON_RIGHT))
    {
        m_Settings.isMoving = false;
        m_Settings.firstClick = true;
        m_ActiveWindow.ShowCursor();
    }
}

#pragma once
#include "Layer/Layer.h"
#include "Window/Window.h"

#include <glm/glm.hpp>

class MoveLayer : public Layer
{
public:
	MoveLayer(const Window& window);
	void OnUpdate() override;
	void OnImGuiUpdate() override;

private:
	void CalculateMovement();

	struct Settings
	{
		bool isMoving = false;
		bool firstClick = false;
		float speed = 10.0f;
		float mouseSensitivity = 70.0f;
	};

	Settings m_Settings;
	const Window& m_ActiveWindow;
	const glm::vec3 m_Up = glm::vec3(0.0f, 1.0f, 0.0f);
};
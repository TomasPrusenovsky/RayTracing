
#include "Camera.h"

namespace rt {
    Camera::Camera(float FOV, point position, direction direction) :
        m_FOV(FOV), m_Position(position), m_Derection(direction)
    {}
} // rt
#ifndef CAMERA_H
#define CAMERA_H

#include "Utils/Ray.h"

namespace rt {

    class Camera {
    public:
        Camera(float FOV, point position, direction direction);

    private:
        float m_FOV;

        point m_Position;
        direction m_Derection;
    };

} // rt

#endif //CAMERA_H

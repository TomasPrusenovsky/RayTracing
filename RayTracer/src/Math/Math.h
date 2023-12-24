#ifndef MATH_H
#define MATH_H

#include <glm/glm.hpp>
#include "Utils/Material.h"


namespace Math {
    float length_squared(const glm::vec3& vec);
    rt::color GammaCorection2(glm::vec4 color);
}

#endif //MATH_H

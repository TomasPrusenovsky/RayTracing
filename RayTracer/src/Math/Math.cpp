#include "Math.h"

namespace Math {
    float length_squared(const glm::vec3& vec) {
        return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
    }

    rt::color GammaCorection2(glm::vec4 color)
    {
        return glm::vec4(glm::sqrt(color));
    }
}
#include "Math.h"

namespace Math {
    float length_squared(const glm::vec3& vec) {
        return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
    }
}
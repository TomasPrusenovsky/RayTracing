#ifndef MATH_H
#define MATH_H

#include <glm/glm.hpp>

namespace rt {
class Math {
public:
    static float length_squared(const glm::vec3 vec);
};

} // rt

#endif //MATH_H

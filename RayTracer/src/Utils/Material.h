#ifndef MATERIAL_H
#define MATERIAL_H
#include <glm/glm.hpp>

namespace rt {
    using color = glm::vec4;
    struct Material {
        color albedo;
    };
}

#endif //MATERIAL_H

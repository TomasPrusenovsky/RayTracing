#ifndef RAY_H
#define RAY_H
#include <glm/glm.hpp>
#include "Material.h"

namespace rt {
    using point = glm::vec3;
    using direction = glm::vec3;

    struct HitInfo {
        bool didHit = false;
        point hitPoint;
        Material material;
        direction normal;
        float distance;
    };

    class Ray {
    public:
        Ray(point origin, direction direction);

        point operator[](float at) const;
        const point Origin() const { return m_Origin; }
        const direction Direction() const { return  m_Direction; }

        void Origin(point newOrigin) { m_Origin = newOrigin; }
        void Direction(direction newDirection) { m_Direction = newDirection; }

    private:
        point m_Origin;
        direction m_Direction;
    };
}



#endif //RAY_H

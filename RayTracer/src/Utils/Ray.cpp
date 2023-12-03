
#include "Ray.h"

namespace rt {
    Ray::Ray(point origin, direction direction) :
        m_Origin(origin), m_Direction(direction)
    {}

    point Ray::operator[](float at) const {
        return m_Origin + at * m_Direction;
    }
}

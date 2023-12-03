#ifndef SHAPE_H
#define SHAPE_H
#include "../Ray.h"

namespace rt {
    class Shape {
    public:
        virtual const HitInfo Intersection(const Ray& ray) const = 0;
        virtual ~Shape() = 0;

    protected:
        Material m_Material = {};
    };
}
#endif //SHAPE_H

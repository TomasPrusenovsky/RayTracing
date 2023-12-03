#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

namespace rt {

class Sphere : public Shape {
public:
    Sphere(float radius, point position, Material material);
    ~Sphere() override = default;
    const HitInfo Intersection(const Ray& ray) const override;

private:
    float m_Radius;
    point m_Position;
};

} // rt

#endif //SPHERE_H

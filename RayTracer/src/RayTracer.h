#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Camera.h"
#include "Image/Image.h"

namespace rt {
class RayTracer {
public:
    RayTracer(int width, int height);

    void Trace();
    const Image& GetImage() const { return m_Image; }

private:
    // Camera m_Camera;
    Image m_Image;
};

} // rt

#endif //RAYTRACER_H

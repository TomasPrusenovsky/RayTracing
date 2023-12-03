#include "RayTracer.h"
#include "Math/Random.h"

namespace rt {
    RayTracer::RayTracer(int width, int height) :
            m_Image(std::make_unique<Image>(width, height)) {

    }

    void RayTracer::Trace() {
        for (int y = 0; y < m_Image->GetHeight(); ++y) {
            for (int x = 0; x < m_Image->GetWidth(); ++x) {
                color rand_color{Random::Float2(0.0f, 1.0f), Random::Float2(0.0f, 1.0f),
                    Random::Float2(0.0f, 1.0f), 1.0f};
                m_Image->SetPixel(x, y, rand_color);
            }
        }
    }

    void RayTracer::Resize(int width, int height) {
        if (width < 1 or height < 1) return;
        if (m_Image->GetWidth() == width and m_Image->GetHeight() == height) return;

        m_Image = std::make_unique<Image>(width, height);
    }
} // rt
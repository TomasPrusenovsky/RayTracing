#pragma once
#include <glm/glm.hpp>

namespace rt {

class Image {
public:
    Image(int width, int heigh);
    ~Image();

    using color = glm::vec4;
    void SetPixel(uint32_t x, uint32_t y, color color);
    const float AspectRatio() const { return (float)m_Windth / (float)m_Height; }
    const int Width() const { return m_Windth; }
    const int Height() const { return m_Height; }
    const float* GetData() const { return m_Data; }

private:
    int m_Windth;
    int m_Height;
    int m_Chanels = 4;

    float* m_Data;
};

} // rt

#include "Image.h"

namespace rt {
    Image::Image(int width, int heigh) :
            m_Windth(width), m_Height(heigh) {
        uint32_t imageSize = m_Windth * m_Height * m_Chanels;
        m_Data = new float[imageSize];

        for (uint32_t i = 0; i < imageSize; ++i) { // initialize it with white
            m_Data[i] = 1.0f;
        }
    }

    Image::~Image() {
        delete[] m_Data;
    }

    void Image::SetPixel(uint32_t x, uint32_t y, color color) {
        uint32_t index = (y * m_Windth + x) * m_Chanels;
        m_Data[index + 0] = color.r;
        m_Data[index + 1] = color.g;
        m_Data[index + 2] = color.b;
        m_Data[index + 3] = color.a;

    }
} // rt
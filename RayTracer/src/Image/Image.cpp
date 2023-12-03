
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
} // rt
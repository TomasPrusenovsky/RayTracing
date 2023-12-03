#ifndef IMAGE_H
#define IMAGE_H

#include <memory>

namespace rt {

class Image {
public:
    Image(int width, int heigh);
    ~Image();

    const int GetWidth() const { return m_Windth; }
    const int GetHeight() const { return m_Height; }
    const float* GetData() const { return m_Data; }

private:
    int m_Windth;
    int m_Height;
    int m_Chanels = 4;

    float* m_Data;
};

} // rt

#endif //IMAGE_H

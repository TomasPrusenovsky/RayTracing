#include "Image.h"

namespace rt
{
	Image::Image(int width, int heigh) :
		m_Windth(width), m_Height(heigh)
	{
		uint32_t imageSize = m_Windth * m_Height * m_Chanels;
		m_Data = std::make_unique<PixelArray>(imageSize);

		IterResize(heigh);
	}

	Image::~Image()
	{
	}

	void Image::SetPixel(uint32_t x, uint32_t y, const color& color)
	{
		uint32_t index = (y * m_Windth + x) * m_Chanels;
		m_Data[index + 0] = color.r;
		m_Data[index + 1] = color.g;
		m_Data[index + 2] = color.b;
		m_Data[index + 3] = color.a;
	}


	void Image::IterResize(uint32_t newSize)
	{
		m_VerticalIter.resize(newSize);
		for (int i = 0; i < newSize; ++i)
			m_VerticalIter[i] = i;
	}
} // rt
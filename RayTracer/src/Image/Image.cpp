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

	void Image::PerPixel(std::function<void(pixel& pixel)> func)
	{
		std::for_each(std::execution::par, Begin(), End(),
			[&func, this](uint32_t y)
			{
				for (int x = 0; x < m_Windth; ++x)
				{
					func(Pixel(x, y));
				}
			});
	}

	Image::pixel& Image::Pixel(uint32_t x, uint32_t y)
	{
		const uint32_t index = (y * m_Windth + x) * m_Chanels;
		return (Image::pixel&)(m_Data[index]);
	}


	void Image::IterResize(uint32_t newSize)
	{
		m_VerticalIter.resize(newSize);
		for (int i = 0; i < newSize; ++i)
			m_VerticalIter[i] = i;
	}

	void Image::Clear()
	{
		for (uint32_t y = 0; y < m_Height; ++y)
		{
			for (uint32_t x = 0; x < m_Windth; ++x)
			{
				SetPixel(x, y, Color::Black);
			}
		}
	}
} // rt
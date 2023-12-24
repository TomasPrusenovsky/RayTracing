#include "AccImage.h"

namespace rt
{
	color AccImage::PixelColor(uint32_t x, uint32_t y) const
	{
		uint32_t index = (y * m_Windth + x) * m_Chanels;
		color color;

		color.r = m_Data[index + 0];
		color.g = m_Data[index + 1];
		color.b = m_Data[index + 2];
		color.a = m_Data[index + 3];

		return color;
	}
	void AccImage::Accumulate(uint32_t x, uint32_t y, color color)
	{
		uint32_t index = (y * m_Windth + x) * m_Chanels;
		m_Data[index + 0] += color.r;
		m_Data[index + 1] += color.g;
		m_Data[index + 2] += color.b;
		m_Data[index + 3] += color.a;
	}
}
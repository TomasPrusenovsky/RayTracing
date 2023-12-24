#pragma once 
#include "Image.h"

namespace rt
{
	class AccImage : public Image
	{
	public:
		using Image::Image;

		color PixelColor(uint32_t x, uint32_t y) const;
		void Accumulate(uint32_t x, uint32_t y, color color);
	};
}
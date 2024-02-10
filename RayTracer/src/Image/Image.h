#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include "Utils/Material.h"

#include <execution>
#include <functional>

namespace rt
{
	class Image
	{
	public:
		using pixel = glm::vec4;

		Image(int width, int heigh);
		~Image();

		void SetPixel(uint32_t x, uint32_t y, const color& color);
		void PerPixel(std::function<void(pixel& pixel)> func);
		pixel& Pixel(uint32_t x, uint32_t y);
		const float AspectRatio() const { return (float)m_Windth / (float)m_Height; }
		const int Width() const { return m_Windth; }
		const int Height() const { return m_Height; }
		glm::vec2 DimensionsVec() const { return { m_Windth, m_Height }; }
		const int Chanels() const { return m_Chanels; }
		const float* GetData() const { return m_Data.get(); }
		const uint32_t Size() const { return m_Windth * m_Height * m_Chanels; }
		void Clear();

		// ..........................................
		auto Begin() { return m_VerticalIter.begin(); }
		auto End() { return m_VerticalIter.end(); }
		// ............................................

	protected:
		// TODO: maybe separate class...................
		using Iterator = std::vector<uint32_t>;
		Iterator m_VerticalIter;
		void IterResize(uint32_t newSize);
		//..........................................
		int m_Windth;
		int m_Height;
		int m_Chanels = 4;

		using PixelArray = float[];
		std::unique_ptr<PixelArray> m_Data;
	};
} // rt

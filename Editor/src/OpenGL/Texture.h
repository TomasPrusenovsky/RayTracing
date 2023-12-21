#pragma once
#include "glad/glad.h"
#include "Image/Image.h"

namespace OpenGL
{
	class Texture
	{
	public:
		Texture();

		GLuint GetID() const { return m_ID; }

		void Update(const rt::Image& image);
		void Update(int width, int height, const float* data);

	private:
		void CreateTexture();

	private:
		GLuint m_ID = -1;
	};
} // OpenGL


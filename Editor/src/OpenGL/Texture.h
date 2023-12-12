#ifndef TEXTURE_H
#define TEXTURE_H
#include "glad/glad.h"

namespace OpenGL
{
	class Texture
	{
	public:
		Texture();

		GLuint GetID() const { return m_ID; }

		void Update(int width, int height, const float* data);

	private:
		void CreateTexture();

	private:
		GLuint m_ID = -1;
	};
} // OpenGL

#endif //TEXTURE_H

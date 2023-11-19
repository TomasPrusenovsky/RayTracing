#include "OpenGL.h"
#include "glad/glad.h"

namespace OpenGL {
    void ClearColor(float r, float g, float b, float a) {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

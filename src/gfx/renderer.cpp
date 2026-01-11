#include "../../include/gfx/renderer.h"
#include <stdlib.h>

namespace Minecraft {
	namespace GFX {
		Renderer::Renderer() {
			this->vbo = createVBO(GL_ARRAY_BUFFER);
			this->vao = createVAO();

			this->shaders[0] = createShader("res/shaders/triangle.vert",
											"res/shaders/triangle.frag");
			linkShaders(shaders[0]);
		}

		Renderer::~Renderer() {
			destroyVBO(this->vbo);
			destroyVAO(this->vao);
			destroyShader(shaders[0]);
		}

		void Renderer::renderTriangle() {
			float vertices[] = {
				-0.5f, -0.5f, 0.0f, // left
				0.5f,  -0.5f, 0.0f, // right
				0.0f,  0.5f,  0.0f	// top
			};

            bufferVBO(this->vbo, vertices, sizeof(vertices));
            attrVAO(this->vao, this->vbo, 0, 3, GL_FLOAT, 0);
		}
	} // namespace GFX
} // namespace Minecraft
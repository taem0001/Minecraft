#include "../../include/gfx/renderer.h"
#include <iostream>
#include <stdlib.h>

namespace Minecraft {
	namespace GFX {
		Renderer::Renderer()
			: vbo(createVBO(GL_ARRAY_BUFFER)), vao(createVAO()) {
			for (int i = 0; i < SHADERNUM; i++) {
				this->shader[i] = Shader("res/shaders/triangle.vert",
										 "res/shaders/triangle.frag");
			}
		}

		Renderer::~Renderer() {
			destroyVBO(this->vbo);
			destroyVAO(this->vao);
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

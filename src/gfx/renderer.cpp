#include "../../include/gfx/renderer.hpp"
#include <iostream>
#include <stdlib.h>

namespace Minecraft {
	namespace GFX {
		void Renderer::init() {
			this->vbo = createVBO(GL_ARRAY_BUFFER);
			this->ebo = createVBO(GL_ELEMENT_ARRAY_BUFFER);
			this->vao = createVAO();

			for (int i = 0; i < SHADERNUM; i++) {
				this->shader[i].init("res/shaders/block.vert",
									 "res/shaders/block.frag");
			}

			this->cam = Entity::Camera(glm::vec3(0.0f, 0.0f, 3.0f));
		}

		Renderer::~Renderer() {
			destroyVBO(this->vbo);
			destroyVBO(this->ebo);
			destroyVAO(this->vao);
		}

		void Renderer::prepareRect() {
			bufferVBO(this->vbo, vertices, sizeof(vertices));
			bufferVBO(this->ebo, indices, sizeof(indices));
			attrVAO(this->vao, this->vbo, this->ebo, 0, 3, GL_FLOAT, 0);
		}
	} // namespace GFX
} // namespace Minecraft

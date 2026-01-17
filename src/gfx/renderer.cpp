#include "../../include/gfx/renderer.h"
#include <iostream>
#include <stdlib.h>

namespace Minecraft {
	namespace GFX {
		float vertices[] = {
			0.5f,  0.5f,  0.0f, // top right
			0.5f,  -0.5f, 0.0f, // bottom right
			-0.5f, -0.5f, 0.0f, // bottom left
			-0.5f, 0.5f,  0.0f	// top left
		};
		unsigned int indices[] = {
			0, 1, 3, // first Triangle
			1, 2, 3	 // second Triangle
		};

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

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Minecraft {
	namespace World {
		float vertices[] = {
			0.5f,  0.5f,  0.0f, // top right
			0.5f,  -0.5f, 0.0f, // bottom right
			-0.5f, -0.5f, 0.0f, // bottom left
			-0.5f, 0.5f,  0.0f, // top left
			0.5f,  0.5f,  1.0f, // top right - behind
			0.5f,  -0.5f, 1.0f, // bottom right - behind
			-0.5f, -0.5f, 1.0f, // bottom left - behind
			-0.5f, 0.5f,  1.0f	// top left - behind
		};
		unsigned int indices[] = {
			0, 1, 3, // first Triangle
			1, 2, 3, // second Triangle
			4, 5, 7, // third Triangle
			5, 6, 7, // fourth Triangle
			5, 1, 0, // fifth Triangle
			0, 4, 5, // sixth Triangle
			1, 2, 5, // seventh Triangle
			5, 2, 6, // eighth Triangle
			0, 3, 4, // ninth Triangle
			4, 3, 7, // tenth Triangle
			6, 2, 3, // eleventh Triangle
			3, 7, 6	 // twelth Triangle
		};

		struct Block {
				glm::mat4 model;

                void render();
		};
	} // namespace World
} // namespace Minecraft
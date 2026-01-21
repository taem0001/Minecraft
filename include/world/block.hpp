#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Minecraft {
	namespace World {
		enum BlockType { AIR = 0, DIRT };

		static float vertices[] = {
										// Front face (z = 0)   v0 v1 v2 v3
    +0.5f, +0.5f, 0.0f,   1.0f, 1.0f,   // top-right
    +0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   // bottom-right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // bottom-left
    -0.5f, +0.5f, 0.0f,   0.0f, 1.0f,   // top-left
    									// Back face (z = 1)    v4 v5 v6 v7
    -0.5f, +0.5f, 1.0f,   1.0f, 1.0f,   // top-right (viewed from outside, back face is reversed in x)
    -0.5f, -0.5f, 1.0f,   1.0f, 0.0f,   // bottom-right
    +0.5f, -0.5f, 1.0f,   0.0f, 0.0f,   // bottom-left
    +0.5f, +0.5f, 1.0f,   0.0f, 1.0f,   // top-left
    									// Left face (x = -0.5)
    -0.5f, +0.5f, 1.0f,   1.0f, 1.0f,   // top-right
    -0.5f, +0.5f, 0.0f,   1.0f, 0.0f,   // bottom-right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // bottom-left
    -0.5f, -0.5f, 1.0f,   0.0f, 1.0f,   // top-left
    									// Right face (x = +0.5)
    +0.5f, +0.5f, 0.0f,   1.0f, 1.0f,   // top-right
    +0.5f, +0.5f, 1.0f,   1.0f, 0.0f,   // bottom-right
    +0.5f, -0.5f, 1.0f,   0.0f, 0.0f,   // bottom-left
    +0.5f, -0.5f, 0.0f,   0.0f, 1.0f,   // top-left
   										// Top face (y = +0.5)
    +0.5f, +0.5f, 1.0f,   1.0f, 1.0f,   // top-right
    +0.5f, +0.5f, 0.0f,   1.0f, 0.0f,   // bottom-right
    -0.5f, +0.5f, 0.0f,   0.0f, 0.0f,   // bottom-left
    -0.5f, +0.5f, 1.0f,   0.0f, 1.0f,   // top-left
    									// Bottom face (y = -0.5)
    +0.5f, -0.5f, 0.0f,   1.0f, 1.0f,   // top-right
    +0.5f, -0.5f, 1.0f,   1.0f, 0.0f,   // bottom-right
    -0.5f, -0.5f, 1.0f,   0.0f, 0.0f,   // bottom-left
    -0.5f, -0.5f, 0.0f,   0.0f, 1.0f,   // top-left
		};

		static unsigned int indices[] = {
			0,  1,  3,   1,  2,  3,   // Front
    4,  5,  7,   5,  6,  7,   // Back
    8,  9, 11,   9, 10, 11,   // Left
    12,13,15,   13,14,15,   // Right
    16,17,19,   17,18,19,   // Top
    20,21,23,   21,22,23    // Bottom
		};

		struct Block {
				BlockType type;
				glm::vec3 pos;
		};
	} // namespace World
} // namespace Minecraft
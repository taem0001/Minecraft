#pragma once

#include "gfx.hpp"
#include "vbo.hpp"

namespace Minecraft {
	namespace GFX {
		struct VAO {
				GLuint handle;
		};

		struct VAO createVAO();
		void bindVAO(struct VAO);
		void attrVAO(struct VAO, struct VBO, struct VBO, GLuint, GLint, GLenum, GLsizei);
		void destroyVAO(struct VAO);
	} // namespace GFX
} // namespace Minecraft
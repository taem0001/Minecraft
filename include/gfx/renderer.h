#pragma once

#include "../entity/camera.h"
#include "gfx.h"
#include "shader.h"
#include "vao.h"
#include "vbo.h"

namespace Minecraft {
	namespace GFX {
		enum ShaderType { TRIANGLE = 0 };
#define SHADERNUM (TRIANGLE + 1)

		struct Renderer {
				~Renderer();
				void init();
				void prepareRect();

				struct Shader shader[SHADERNUM];
				struct VBO vbo, ebo;
				struct VAO vao;

				Entity::Camera cam;
		};
	} // namespace GFX
} // namespace Minecraft

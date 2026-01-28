#pragma once

#include "../entity/camera.hpp"
#include "../meshing/chunkmesher.hpp"
#include "../world/world.hpp"
#include "chunkmesh.hpp"
#include "gfx.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Minecraft {
	namespace GFX {
#define WIDTH  1280
#define HEIGHT 720

		class Renderer {
			public:
				Renderer();

				void updateChunks(World::World &world);
				void renderWorld(const World::World &world);

				Entity::Camera &getCam() { return cam; }
				const Entity::Camera &getCam() const { return cam; }

				void setViewPortSize(int w, int h) {
					this->width = w;
					this->height = h;
				}

			private:
				Entity::Camera cam;

				Shader shader;
				Texture texture;

				int width;
				int height;
		};
	} // namespace GFX
} // namespace Minecraft

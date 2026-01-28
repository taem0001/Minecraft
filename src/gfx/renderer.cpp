#include "../../include/gfx/renderer.hpp"
#include <iostream>
#include <stdlib.h>

namespace Minecraft {
	namespace GFX {
		Renderer::Renderer()
			: cam(Entity::Camera(glm::vec3(0.0f, 20.0f, 18.0f))), width(WIDTH),
			  height(HEIGHT) {
			shader.init("res/shaders/block.vert", "res/shaders/block.frag");
			texture.init("res/textures/dirt.png");
		}

		void Renderer::updateChunks(World::World &w) {
			auto &chunks = w.getChunks();
			for (auto it = chunks.begin(); it != chunks.end(); it++) {
				auto &chunk = w.getChunk(it->first);
				if (!chunk.dirty) continue;

				Meshing::MeshData cpu = Meshing::ChunkMesher::build(chunk);
				chunk.mesh->upload(cpu);

				chunk.dirty = false;
			}
		}

		void Renderer::renderWorld(const World::World &w) {
			shader.use();
			texture.bind();

			glm::mat4 proj = glm::perspective(glm::radians((float)cam.fovy),
											  (float)width / (float)height,
											  (float)cam.near, (float)cam.far);
			shader.setMat4("projection", proj);

			glm::mat4 view = cam.getViewMat();
			shader.setMat4("view", view);

			auto &chunks = w.getChunks();
			for (auto it = chunks.begin(); it != chunks.end(); it++) {
				auto &chunk = w.getChunk(it->first);
				if (chunk.mesh->empty()) {
					continue;
				}

				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, chunk.worldOrigin());
				shader.setMat4("model", model);

				chunk.mesh->draw();
			}
		}
	} // namespace GFX
} // namespace Minecraft

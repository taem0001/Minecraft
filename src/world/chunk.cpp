#include "../../include/world/chunk.hpp"

namespace Minecraft {
	namespace World {
		Chunk::Chunk() : offset(glm::vec3(0.0f, 0.0f, 0.0f)) {
			for (int x = 0; x < CHUNK_SIZE_X; x++) {
				for (int z = 0; z < CHUNK_SIZE_Z; z++) {
					for (int y = 0; y < CHUNK_SIZE_Y; y++) {
						blocks[x][z][y] = {.pos = glm::vec3(x, y, z),
										   .type = DIRT};
					}
				}
			}
		}

		glm::vec3 Chunk::getOffset() { return offset; }
	} // namespace World
} // namespace Minecraft

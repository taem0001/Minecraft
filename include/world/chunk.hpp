#pragma once

#include "block.hpp"

namespace Minecraft {
	namespace World {
#define CHUNK_SIZE_X 16
#define CHUNK_SIZE_Z 16
#define CHUNK_SIZE_Y 16

		class Chunk {
			public:
				Chunk();
				~Chunk();

				glm::vec3 getOffset();
				struct Block ***getBlocks();

			private:
				glm::vec3 offset;
				struct Block ***blocks;
		};
	} // namespace World
} // namespace Minecraft

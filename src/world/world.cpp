#include "../../include/world/world.hpp"
#include <memory>

namespace Minecraft {
	namespace World {
		World::World() {
			Chunk chunk;
			chunk.init({0, 0, 0});

			chunks.emplace(chunk.coord, std::move(chunk));
		}

		void World::setBlock(const ChunkCoord &coord, int x, int y, int z,
							 Block::BlockID id) {
			chunks.at(coord).setBlock(x, y, z, id);
		}
	} // namespace World
} // namespace Minecraft

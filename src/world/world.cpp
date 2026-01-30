#include "../../include/world/world.hpp"
#include <memory>

namespace Minecraft {
	namespace World {
		World::World() {
			Chunk chunk;
			chunk.init({0, 0, 0});

			chunks.emplace(chunk.coord, std::move(chunk));
		}

		Chunk &World::getChunk(const ChunkCoord &coord) {
			return chunks.at(coord);
		}
		const Chunk &World::getChunk(const ChunkCoord &coord) const {
			return chunks.at(coord);
		}
		std::unordered_map<ChunkCoord, Chunk> &World::getChunks() {
			return chunks;
		}
		const std::unordered_map<ChunkCoord, Chunk> &World::getChunks() const {
			return chunks;
		}
		void World::setBlock(const ChunkCoord &coord, int x, int y, int z,
							 Block::BlockID id) {
			chunks.at(coord).setBlock(x, y, z, id);
		}
	} // namespace World
} // namespace Minecraft

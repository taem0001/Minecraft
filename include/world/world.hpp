#pragma once

#include "../gfx/chunkmesh.hpp"
#include "chunk.hpp"
#include <unordered_map>

namespace Minecraft {
	namespace World {
		class World {
			public:
				World();

				Chunk &getChunk(const ChunkCoord &coord) {
					return chunks.at(coord);
				}
				const Chunk &getChunk(const ChunkCoord &coord) const {
					return chunks.at(coord);
				}
				void setBlock(const ChunkCoord &coord, int x, int y, int z,
							  BlockID id);
				std::unordered_map<ChunkCoord, Chunk> &getChunks() {
					return chunks;
				}
				const std::unordered_map<ChunkCoord, Chunk> &getChunks() const {
					return chunks;
				}

			private:
				std::unordered_map<ChunkCoord, Chunk> chunks;
		};
	} // namespace World
} // namespace Minecraft

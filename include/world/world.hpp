#pragma once

#include "../gfx/chunkmesh.hpp"
#include "chunk.hpp"
#include <unordered_map>

namespace Minecraft {
	namespace World {
		class World {
			public:
				World();

				Chunk &getChunk(const ChunkCoord &coord);
				const Chunk &getChunk(const ChunkCoord &coord) const;
				std::unordered_map<ChunkCoord, Chunk> &getChunks();
				const std::unordered_map<ChunkCoord, Chunk> &getChunks() const;
				void setBlock(const ChunkCoord &coord, int x, int y, int z,
							  Block::BlockID id);

			private:
				std::unordered_map<ChunkCoord, Chunk> chunks;
		};
	} // namespace World
} // namespace Minecraft

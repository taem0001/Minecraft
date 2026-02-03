#pragma once

#include "../gfx/chunkmesh.hpp"
#include "../util/includes.hpp"
#include "../util/macros.hpp"
#include "chunk.hpp"

namespace Minecraft {
	namespace World {
		class World {
			public:
				World();

				Chunk *getChunk(const ChunkCoord &coord);
				const Chunk *getChunk(const ChunkCoord &coord) const;
				Chunk &getOrCreateChunk(const ChunkCoord &coord);
				std::unordered_map<ChunkCoord, Chunk> &getChunks();
				const std::unordered_map<ChunkCoord, Chunk> &getChunks() const;

				Block::BlockID getBlockWorld(int x, int y, int z) const;

			private:
				std::unordered_map<ChunkCoord, Chunk> chunks;

				void setBlockWorld(int wx, int wy, int wz, Block::BlockID id);
				void createChunk(const ChunkCoord &coord);
				void markDirtyIfLoaded(const ChunkCoord &coord);
		};
	} // namespace World
} // namespace Minecraft

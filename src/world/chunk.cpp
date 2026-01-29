#include "../../include/world/chunk.hpp"

namespace Minecraft {
	namespace World {
		void Chunk::init(const ChunkCoord &coord) {
			this->mesh = std::unique_ptr<GFX::ChunkMesh>(new GFX::ChunkMesh);
			this->coord = coord;
			this->dirty = true;

			for (int i = 0; i < CHUNK_MAX_X * CHUNK_MAX_Y * CHUNK_MAX_Z; i++) {
				this->blocks[i] = DIRT;
			}

			std::cout << "[INFO] Chunk generated at: " << this->coord << std::endl;
		}

		constexpr int Chunk::index(int x, int y, int z) {
			return x + CHUNK_MAX_X * (y + CHUNK_MAX_Y * z);
		}

		BlockID Chunk::getBlock(int x, int y, int z) const {
			return blocks[index(x, y, z)];
		}

		void Chunk::setBlock(int x, int y, int z, BlockID blockID) {
			if (blocks[index(x, y, z)] == blockID) return;

			blocks[index(x, y, z)] = blockID;
			dirty = true;
		}

		bool Chunk::isAirLocal(int x, int y, int z) const {
			if (x < 0 || x >= CHUNK_MAX_X) return false;
			if (y < 0 || y >= CHUNK_MAX_Y) return false;
			if (z < 0 || z >= CHUNK_MAX_Z) return false;

			return blocks[index(x, y, z)] == BlockType::AIR;
		}

		glm::vec3 Chunk::worldOrigin() const {
			return {coord.x * CHUNK_MAX_X, coord.y * CHUNK_MAX_Y,
					coord.z * CHUNK_MAX_Z};
		}
	} // namespace World
} // namespace Minecraft
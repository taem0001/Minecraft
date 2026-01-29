#pragma once

#include "../gfx/chunkmesh.hpp"
#include "../block/block.hpp"
#include "../util/types.hpp"
#include <array>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <memory>

#define CHUNK_MAX_X 16
#define CHUNK_MAX_Y 16
#define CHUNK_MAX_Z 16

namespace Minecraft {
	namespace World {
		struct ChunkCoord {
				int x, y, z;

				bool operator==(const ChunkCoord &other) const noexcept {
					return (x == other.x && y == other.y && z == other.z);
				}

				friend std::ostream &operator<<(std::ostream &out, const ChunkCoord &cc) noexcept {
					return out << "(" << cc.x << "; " << cc.y << "; " << cc.z << ")";
				}
		};

		struct Chunk {
				ChunkCoord coord;
				bool dirty = true;
				std::array<Block::BlockID, CHUNK_MAX_X * CHUNK_MAX_Y * CHUNK_MAX_Z>
					blocks{};
				std::unique_ptr<GFX::ChunkMesh> mesh;

				void init(const ChunkCoord &coord);
				static constexpr int index(int x, int y, int z);
				Block::BlockID getBlock(int x, int y, int z) const;
				void setBlock(int x, int y, int z, Block::BlockID blockID);
				bool isAirLocal(int x, int y, int z) const;
				glm::vec3 worldOrigin() const;
		};
	} // namespace World
} // namespace Minecraft

template <> struct std::hash<Minecraft::World::ChunkCoord> {
		size_t
		operator()(const Minecraft::World::ChunkCoord &c) const noexcept {
			size_t h1 = std::hash<int>{}(c.x);
			size_t h2 = std::hash<int>{}(c.y);
			size_t h3 = std::hash<int>{}(c.z);

			size_t seed = h1;
			seed ^= h2 + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
			seed ^= h3 + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
			return seed;
		}
};

#pragma once

#include "../world/chunk.hpp"
#include "meshdata.hpp"

namespace Minecraft {
	namespace Meshing {
		enum class FaceDir { PZ, NZ, PX, NX, PY, NY };

		class ChunkMesher {
			public:
				static MeshData build(const World::Chunk &chunk);

			private:
				static bool isAir(const World::Chunk &chunk, int x, int y,
								  int z);
				static void emitFace(MeshData &out, int bx, int by, int bz,
									 FaceDir dir, float texit);
		};
	} // namespace Meshing
} // namespace Minecraft
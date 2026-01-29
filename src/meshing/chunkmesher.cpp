#include "../../include/meshing/chunkmesher.hpp"

namespace Minecraft {
	namespace Meshing {
		static constexpr int SX = CHUNK_MAX_X;
		static constexpr int SY = CHUNK_MAX_Y;
		static constexpr int SZ = CHUNK_MAX_Z;

		static constexpr unsigned int INDICES[] = {0, 1, 2, 0, 2, 3};

		static constexpr float UV[] = {
			1.0f, 1.0f, // Top right
			1.0f, 0.0f, // Bottom right
			0.0f, 0.0f, // Bottom left
			0.0f, 1.0f	// Top left
		};

		static constexpr float FACE_PZ[] = {
			// +Z
			+0.5f, +0.5f, +0.5f, +0.5f, -0.5f, +0.5f,
			-0.5f, -0.5f, +0.5f, -0.5f, +0.5f, +0.5f,
		};
		static constexpr float FACE_NZ[] = {
			// -Z
			+0.5f, +0.5f, -0.5f, -0.5f, +0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f, +0.5f, -0.5f, -0.5f,
		};
		static constexpr float FACE_PY[] = {
			// +Y
			+0.5f, +0.5f, +0.5f, -0.5f, +0.5f, +0.5f,
			-0.5f, +0.5f, -0.5f, +0.5f, +0.5f, -0.5f,
		};
		static constexpr float FACE_NY[] = {
			// -Y
			+0.5f, -0.5f, +0.5f, +0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f, -0.5f, -0.5f, +0.5f,
		};
		static constexpr float FACE_PX[] = {
			// +X
			+0.5f, +0.5f, +0.5f, +0.5f, +0.5f, -0.5f,
			+0.5f, -0.5f, -0.5f, +0.5f, -0.5f, +0.5f,
		};
		static constexpr float FACE_NX[] = {
			// -X
			-0.5f, +0.5f, +0.5f, -0.5f, -0.5f, +0.5f,
			-0.5f, -0.5f, -0.5f, -0.5f, +0.5f, -0.5f,
		};

		static const float *faceVerts(FaceDir dir) {
			switch (dir) {
			case FaceDir::PZ:
				return FACE_PZ;
			case FaceDir::NZ:
				return FACE_NZ;
			case FaceDir::PX:
				return FACE_PX;
			case FaceDir::NX:
				return FACE_NX;
			case FaceDir::PY:
				return FACE_PY;
			case FaceDir::NY:
				return FACE_NY;
			}
			return FACE_PZ;
		}

		bool ChunkMesher::isAir(const World::Chunk &c, int x, int y, int z) {
			// TODO: Implement checking across chunks
			if (x < 0 || x >= SX) return true;
			if (y < 0 || y >= SY) return true;
			if (z < 0 || z >= SZ) return true;
			return c.getBlock(x, y, z) == World::AIR;
		}

		MeshData ChunkMesher::build(const World::Chunk &chunk) {
			MeshData out;
			out.vertices.clear();
			out.indices.clear();

			for (int z = 0; z < SZ; z++) {
				for (int y = 0; y < SY; y++) {
					for (int x = 0; x < SX; x++) {
						auto id = chunk.getBlock(x, y, z);
						if (id == World::AIR) continue;

						float texid = (float)id;

						if (isAir(chunk, x, y, z + 1))
							emitFace(out, x, y, z, FaceDir::PZ, texid);
						if (isAir(chunk, x, y, z - 1))
							emitFace(out, x, y, z, FaceDir::NZ, texid);
						if (isAir(chunk, x, y + 1, z))
							emitFace(out, x, y, z, FaceDir::PY, texid);
						if (isAir(chunk, x, y - 1, z))
							emitFace(out, x, y, z, FaceDir::NY, texid);
						if (isAir(chunk, x + 1, y, z))
							emitFace(out, x, y, z, FaceDir::PX, texid);
						if (isAir(chunk, x - 1, y, z))
							emitFace(out, x, y, z, FaceDir::NX, texid);
					}
				}
			}

			return out;
		}

		void ChunkMesher::emitFace(MeshData &out, int bx, int by, int bz,
								   FaceDir dir, float texid) {
			const float *f = faceVerts(dir);

			// Center the templates
			const float ox = (float)bx + 0.5f;
			const float oy = (float)by + 0.5f;
			const float oz = (float)bz + 0.5f;

			unsigned int base = (unsigned int)out.vertices.size();

			for (int i = 0; i < 4; i++) {
				Vertex v;
				v.position = {f[3 * i + 0] + ox, f[3 * i + 1] + oy,
							  f[3 * i + 2] + oz};
				v.uv = {UV[2 * i + 0], UV[2 * i + 1]};
				v.texid = texid;

				out.vertices.push_back(v);
			}

			for (unsigned int idx : INDICES) {
				out.indices.push_back(base + idx);
			}
		}
	} // namespace Meshing
} // namespace Minecraft
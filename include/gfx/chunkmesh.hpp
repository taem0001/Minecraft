#pragma once

#include "../meshing/meshdata.hpp"
#include "gfx.hpp"
#include <utility>

namespace Minecraft {
	namespace GFX {
		class ChunkMesh {
			public:
				ChunkMesh();
				~ChunkMesh();

				void upload(const Meshing::MeshData &data);
				void draw() const;

				bool empty() const;
				size_t getVertexCount() const;
				size_t getIndexCount() const;

			private:
				void createGLObjects();
				void destroyGLObjects();
				void moveFrom(ChunkMesh &other) noexcept;

				unsigned int vao;
				unsigned int vbo;
				unsigned int ebo;
				size_t vertexCount;
				size_t indexCount;
				bool configured;
		};
	} // namespace GFX
} // namespace Minecraft

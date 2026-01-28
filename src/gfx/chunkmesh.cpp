#include "../../include/gfx/chunkmesh.hpp"

namespace Minecraft {
	namespace GFX {
		ChunkMesh::ChunkMesh()
			: vao(0), vbo(0), vertexCount(0), configured(false) {
			createGLObjects();
		}

		ChunkMesh::~ChunkMesh() { destroyGLObjects(); }

		void ChunkMesh::upload(const Meshing::MeshData &data) {
			vertexCount = data.vertices.size();

			glBindVertexArray(vao);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);

			glBufferData(GL_ARRAY_BUFFER,
						 (GLsizeiptr)(vertexCount * sizeof(Meshing::Vertex)),
						 data.vertices.data(), GL_DYNAMIC_DRAW);

			// Configure vertex layout once
			if (!configured) {
				// loc 0 vertex location
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(
					0, 3, GL_FLOAT, GL_FALSE, sizeof(Meshing::Vertex),
					(void *)offsetof(Meshing::Vertex, position));

				// loc 1 uv location
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
									  sizeof(Meshing::Vertex),
									  (void *)offsetof(Meshing::Vertex, uv));

				// loc 2 texid location
				// glEnableVertexAttribArray(2);
				// glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE,
				//					  sizeof(Meshing::Vertex),
				//					  (void *)offsetof(Meshing::Vertex, texid));

				configured = true;
			}

			glBindVertexArray(0);
		}

		void ChunkMesh::draw() const {
			if (empty()) return;
			glBindVertexArray(vao);
			glDrawArrays(GL_TRIANGLES, 0, (GLsizei)vertexCount);
			glBindVertexArray(0);
		}

		bool ChunkMesh::empty() const { return vertexCount == 0; }
		size_t ChunkMesh::getVertexCount() const { return vertexCount; }

		void ChunkMesh::createGLObjects() {
			glGenVertexArrays(1, &vao);
			glGenBuffers(1, &vbo);
		}

		void ChunkMesh::destroyGLObjects() {
			if (vbo) glDeleteBuffers(1, &vbo);
			if (vao) glDeleteVertexArrays(1, &vao);
			vbo = 0;
			vao = 0;
			vertexCount = 0;
			configured = false;
		}

		void ChunkMesh::moveFrom(ChunkMesh &other) noexcept {
			vao = std::exchange(other.vao, 0);
			vbo = std::exchange(other.vbo, 0);
			vertexCount = std::exchange(other.vertexCount, 0);
			configured = std::exchange(other.configured, false);
		}
	} // namespace GFX
} // namespace Minecraft
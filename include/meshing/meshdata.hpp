#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Minecraft {
	namespace Meshing {
		struct Vertex {
				glm::vec3 position;
				glm::vec2 uv;
                float texid;
		};

		struct MeshData {
				std::vector<struct Vertex> vertices;
		};
	} // namespace Meshing
} // namespace Minecraft
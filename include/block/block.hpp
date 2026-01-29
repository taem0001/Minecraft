#pragma once

#include "../util/types.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Minecraft {
	namespace Block {
		using BlockID = u8;

		enum BlockType : BlockID { AIR, DIRT, STONE };

		struct TexCoord {
				int u;
				int v;
		};

		TexCoord getTexCoord(BlockType type);
	} // namespace Block
} // namespace Minecraft
#pragma once

#include "../util/types.hpp"

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
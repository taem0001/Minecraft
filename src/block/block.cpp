#include "../../include/block/block.hpp"

namespace Minecraft {
	namespace Block {
		TexCoord getTexCoord(BlockType type) {
			switch (type) {
			case DIRT:
				return {0, 1};
			case STONE:
				return {1, 1};
			default:
				return {0, 0};
			}
		}
	} // namespace Block
} // namespace Minecraft
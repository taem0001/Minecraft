#pragma once

#include "gfx.hpp"
#include "stb_image.h"

namespace Minecraft {
	namespace GFX {
		class Texture {
			public:
				void init(const char *texturepath);
				void bind();

				unsigned int getHandle();

			private:
				unsigned int handle;
		};
	} // namespace GFX
} // namespace Minecraft

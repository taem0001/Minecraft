#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Minecraft {
	namespace GFX {
		class Texture {
			public:
				Texture(const char *texturepath);

			private:
				unsigned int handle;
		};
	} // namespace GFX
} // namespace Minecraft

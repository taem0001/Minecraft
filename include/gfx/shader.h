#pragma once

#include "gfx.h"

namespace Minecraft {
	namespace GFX {
		struct Shader {
				GLuint handle, vs_handle, fs_handle;
		};
        
        struct Shader createShader(const char *, const char *);
        void linkShaders(struct Shader);
        void destroyShader(struct Shader);
	} // namespace GFX
} // namespace Minecraft
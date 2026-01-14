#pragma once

#include "gfx.h"

namespace Minecraft {
	namespace GFX {
		struct Shader {
				GLuint handle;

				~Shader();
				void init(const char *, const char *);
				void use();
				void setBool(const char *, bool) const;
				void setInt(const char *, int) const;
				void setFloat(const char *, float) const;
		};
	} // namespace GFX
} // namespace Minecraft

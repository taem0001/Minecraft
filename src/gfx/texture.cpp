#include "../../include/gfx/texture.hpp"

namespace Minecraft {
	namespace GFX {
		void Texture::init(const char *texturepath) {
			// Load texture image
			data = stbi_load(texturepath, &w, &h, &nrchannels, 0);

			// Generate the texture in OpenGL
			glGenTextures(1, &handle);
			glBindTexture(GL_TEXTURE_2D, handle);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB,
						 GL_UNSIGNED_BYTE, data);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

			// Free image data
			stbi_image_free(data);
		}

		void Texture::bind() { glBindTexture(GL_TEXTURE_2D, handle); }

		unsigned int Texture::getHandle() { return handle; }
	} // namespace GFX
} // namespace Minecraft
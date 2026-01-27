#include "../../include/gfx/vao.hpp"

namespace Minecraft {
	namespace GFX {
		struct VAO createVAO() {
			struct VAO self;
			glGenVertexArrays(1, &self.handle);
			return self;
		}

		void bindVAO(struct VAO self) { glBindVertexArray(self.handle); }

		void destroyVAO(struct VAO self) {
			glDeleteVertexArrays(1, &self.handle);
		}
	} // namespace GFX
} // namespace Minecraft
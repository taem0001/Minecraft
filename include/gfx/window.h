#pragma once

#include "../util/types.h"
#include "renderer.h"
#include "gfx.h"

namespace Minecraft {
	namespace GFX {
		class Window {
			public:
				Window(int, int);
				~Window();
				void windowLoop();

			private:
				GLFWwindow *handle;
				struct Renderer renderer;
				int width, height;

				void render(Renderer *);
		};
	} // namespace GFX
} // namespace Minecraft

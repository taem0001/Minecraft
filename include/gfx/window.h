#pragma once

#include "../util/types.h"
#include "gfx.h"
#include "renderer.h"
#include <chrono>

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
				u64 deltatime, lastframe;
				std::chrono::time_point<std::chrono::steady_clock> start;

				static void errorCallback(int, const char *);
				static void keyCallback(GLFWwindow *, int, int, int, int);
				static void framebufferSizeCallback(GLFWwindow *, int, int);
				void render();
				void processInput();
				u64 getTickCount();
		};
	} // namespace GFX
} // namespace Minecraft

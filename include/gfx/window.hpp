#pragma once

#include "../util/types.hpp"
#include "gfx.hpp"
#include "renderer.hpp"
#include <chrono>

namespace Minecraft {
	namespace GFX {
#define WIDTH  1280
#define HEIGHT 720

		class Window {
			public:
				Window();
				~Window();
				void windowLoop();

			private:
				GLFWwindow *handle;
				struct Renderer renderer;
				int width, height;
				u64 deltatime, lastframe;

				static float xoffset;
				static float yoffset;

				static void errorCallback(int, const char *);
				static void keyCallback(GLFWwindow *, int, int, int, int);
				static void framebufferSizeCallback(GLFWwindow *, int, int);
				static void mouseCallback(GLFWwindow *, double, double);
				void render();
				void processInput();
		};
	} // namespace GFX
} // namespace Minecraft

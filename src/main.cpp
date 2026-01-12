#include "../include/gfx/window.h"
#include "../include/gfx/renderer.h"
#include <iostream>

int main() {
	Minecraft::GFX::Window window(1280, 720);
	window.windowLoop();
	return 0;
}

#include "../../include/gfx/shader.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace Minecraft {
	namespace GFX {
		GLuint _convertShader(const char *path, GLenum type) {
			// Open shader file and save its contents in a string
			FILE *fp = fopen(path, "r");
			if (!fp) {
				fprintf(stderr, "[ERROR] Failed to open file.\n");
				exit(-1);
			}

			char *buf;

			fseek(fp, 0, SEEK_END);
			int size = ftell(fp);
			int n = size / sizeof(char);

			buf = (char *)malloc(sizeof(char) * n);
			if (!buf) {
				fprintf(stderr, "[ERROR] Failed to allocate memory.\n");
				exit(-1);
			}

			fseek(fp, 0, 0);
			int c, i = 0;
			while (EOF != (c = getc(fp))) {
				buf[i] = c;
				i++;
			}
			fclose(fp);

			// Compile the shader in OpenGL
			GLuint shader = glCreateShader(type);
			glShaderSource(shader, 1, &buf, NULL);
			glCompileShader(shader);

			// Check if shader compiled successfully
			int success;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success) {
				fprintf(stderr, "[ERROR] Failed to compile shader.\n");
			}

			free(buf);
			return shader;
		}

		struct Shader createShader(const char *vspath, const char *fspath) {
			struct Shader self;
			self.vs_handle = _convertShader(vspath, GL_VERTEX_SHADER);
			self.fs_handle = _convertShader(fspath, GL_FRAGMENT_SHADER);
			self.handle = glCreateProgram();
			return self;
		}

		void linkShaders(struct Shader self) {
			// Link shaders to the shader program
			glAttachShader(self.handle, self.vs_handle);
			glAttachShader(self.handle, self.fs_handle);
			glLinkProgram(self.handle);

			// Check shader linking success
			int success;
			glGetProgramiv(self.handle, GL_LINK_STATUS, &success);
			if (!success) {
				fprintf(stderr, "[ERROR] Failed to link shader.\n");
			}

			// Delete the fragment and vertex shaders as they are no longer
			// needed
			glDeleteShader(self.vs_handle);
			glDeleteShader(self.fs_handle);
		}

		void destroyShader(struct Shader self) { glDeleteProgram(self.handle); }
	} // namespace GFX
} // namespace Minecraft
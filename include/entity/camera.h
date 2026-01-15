#pragma once

#include "glm/ext/matrix_transform.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Minecraft {
	namespace Entity {
		class Camera {
			public:
				Camera(glm::vec3, glm::vec3, glm::vec3);

				glm::vec3 getPos() const;
				glm::vec3 getFront() const;
				glm::vec3 getUp() const;
				glm::mat4 getView() const;
				void setPos(glm::vec3);
				void setFront(glm::vec3);
				void setUp(glm::vec3);
				void setView(glm::mat4);

			private:
				glm::vec3 pos, front, up;
				glm::mat4 view;
		};
	} // namespace Entity
} // namespace Minecraft

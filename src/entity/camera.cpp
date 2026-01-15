#include "../../include/entity/camera.h"

namespace Minecraft {
	namespace Entity {
		Camera::Camera(glm::vec3 p, glm::vec3 f, glm::vec3 u)
			: pos(p), front(f), up(u), view(glm::lookAt(p, p + f, u)) {}

		glm::vec3 Camera::getPos() const { return pos; }
		glm::vec3 Camera::getFront() const { return front; }
		glm::vec3 Camera::getUp() const { return up; }
		glm::mat4 Camera::getView() const { return view; }
		void Camera::setPos(glm::vec3 p) { pos = p; }
		void Camera::setFront(glm::vec3 f) { front = f; }
		void Camera::setUp(glm::vec3 u) { up = u; }
		void Camera::setView(glm::mat4 v) { view = v; }
	} // namespace Entity
} // namespace Minecraft

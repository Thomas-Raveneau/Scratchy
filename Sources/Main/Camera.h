//
// Project: Scratchy
// File: Camera.h
//

#ifndef SCRATCHY_CAMERA_H
#define SCRATCHY_CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Scratchy {

	// Default values
	const float YAW         = -90.0f;
	const float PITCH       =  0.0f;
	const float SPEED       =  2.5f;
	const float SENSITIVITY =  0.1f;
	const float ZOOM        =  45.0f;

	class Camera {
		public:
			enum MOVEMENT {
				FORWARD,
				BACKWARD,
				LEFT,
				RIGHT
			};

		public:
			glm::vec3 position;
			glm::vec3 front;
			glm::vec3 up;
			glm::vec3 right;
			glm::vec3 worldUp;

			float yaw;
			float pitch;

			float movementSpeed;
			float mouseSensitivity;
			float zoom;

		public:
			Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
			Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

		public:
			void processKeyboard(MOVEMENT direction, float deltaTime);
			void processMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch = true);
			void processMouseScroll(float yOffset);

		private:
			void updateCameraVectors();

		public:
			glm::mat4 getViewMatrix();
	};
}

#endif //SCRATCHY_CAMERA_H

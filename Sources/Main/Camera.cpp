//
// Project: Scratchy
// File: Camera.cpp
//

#include "Camera.h"

using namespace Scratchy;

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch):
		front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), zoom(ZOOM) {
	Camera::position = position;
	Camera::worldUp = up;
	Camera::yaw = yaw;
	Camera::pitch = pitch;

	updateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch):
		front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), zoom(ZOOM) {
	Camera::position = glm::vec3(posX, posY, posZ);
	Camera::worldUp = glm::vec3(upX, upY, upZ);
	Camera::yaw = yaw;
	Camera::pitch = pitch;

	updateCameraVectors();
}

void Camera::processKeyboard(Camera::MOVEMENT direction, float deltaTime) {
	float velocity = movementSpeed * deltaTime;
	if (direction == FORWARD)
		position += front * velocity;
	if (direction == BACKWARD)
		position -= front * velocity;
	if (direction == LEFT)
		position -= right * velocity;
	if (direction == RIGHT)
		position += right * velocity;
}

void Camera::processMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch) {
	xOffset *= mouseSensitivity;
	yOffset *= mouseSensitivity;

	yaw   += xOffset;
	pitch += yOffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch)
	{
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
	}

	updateCameraVectors();
}

void Camera::processMouseScroll(float yOffset) {
	zoom -= (float)yOffset;
	if (zoom < 1.0f)
		zoom = 1.0f;
	if (zoom > 45.0f)
		zoom = 45.0f;
}

void Camera::updateCameraVectors() {
	glm::vec3 newFront;
	newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	newFront.y = sin(glm::radians(pitch));
	newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	Camera::front = glm::normalize(newFront);

	right = glm::normalize(glm::cross(front, worldUp));
	up    = glm::normalize(glm::cross(right, front));
}

glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(position, position + front, up);
}

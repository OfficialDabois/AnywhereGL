#include "Camera.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 eye, glm::vec3 center, float fov) {
    view = glm::lookAt(eye, center, glm::vec3(0, 1, 0));
    perspective = glm::perspective(fov, (float)1920/(float)1080, 0.1f, 100.0f);
}
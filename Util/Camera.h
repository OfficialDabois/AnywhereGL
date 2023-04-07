#ifndef AGL_CAMERA_H
#define AGL_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Camera {
public:
    //fov in radians
    Camera(glm::vec3 eye, glm::vec3 center, float fov);

    glm::mat4 view, perspective;
    glm::vec3 pos;
    glm::vec3 cameraTarget;
    glm::vec3 cameraDirection = glm::normalize(pos - cameraTarget);
};


#endif
#ifndef AGL_OBJECT_H
#define AGL_OBJECT_H

#include <glm/gtc/matrix_transform.hpp>

class Object {
    virtual void SetCamera(glm::mat4 camUpdate) = 0;
    virtual void SetPerspective(glm::mat4 persUpdate) = 0;
    virtual void Render() = 0;
};

#endif

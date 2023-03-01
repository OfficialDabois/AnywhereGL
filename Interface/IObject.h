#ifndef AGL_IOBJECT_H
#define AGL_IOBJECT_H

#include <glm/gtc/matrix_transform.hpp>

class IObject {
    virtual void SetCamera(glm::mat4 camUpdate) = 0;
    virtual void SetPerspective(glm::mat4 persUpdate) = 0;
    virtual void Render() = 0;
};

#endif

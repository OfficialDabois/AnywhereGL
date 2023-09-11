#ifndef AGL_MAINSCENE_H
#define AGL_MAINSCENE_H

#include <vector>
#include <GLFW/glfw3.h>
#include "../Interface/IObject.h"
#include "../Util/Camera.h"


class MainScene {
public:
    explicit MainScene(Camera* camera);
    ~MainScene() = default;

    void Add(IObject* object);
    void Remove(IObject* object);
    void Render();

    GLFWwindow* window;

    std::vector<IObject*> objects;

    glm::mat4 camPers = glm::mat4(1.0f);
    glm::mat4 camView = glm::mat4(1.0f);
};


#endif

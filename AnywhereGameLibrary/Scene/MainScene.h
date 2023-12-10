#ifndef AGL_MAINSCENE_H
#define AGL_MAINSCENE_H

#include <vector>
#include <GLFW/glfw3.h>
#include "../AGL.h"


class MainScene {
    std::vector<IObject*> objects;
    std::vector<Object*> rigidBodies;

    void UpdateLighting(IObject* object);

public:
    explicit MainScene(Camera* camera);
    ~MainScene() = default;

    void Add(IObject* object);
    void Remove(IObject* object);
    void Render();
    void PhysUpdate(float dt);

    glm::mat4 camPers = glm::mat4(1.0f);
    glm::mat4 camView = glm::mat4(1.0f);
};


#endif

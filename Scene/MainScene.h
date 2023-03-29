#ifndef AGL_MAINSCENE_H
#define AGL_MAINSCENE_H

#include <vector>
#include <GLFW/glfw3.h>
#include "../Interface/IObject.h"
#include "../Interface/IScene.h"


class MainScene : public IScene{
public:
    MainScene();
    ~MainScene() = default;

    void Add(IObject* object) override;
    void Remove(IObject* object) override;
    void Render() override;

    GLFWwindow* window;

    std::vector<IObject*> objects;

    glm::mat4 camPers = glm::mat4(1.0f);
    glm::mat4 camView = glm::mat4(1.0f);
};


#endif

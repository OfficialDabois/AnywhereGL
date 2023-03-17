#include "MainScene.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

MainScene::MainScene() {
    camPers = glm::perspective(40.0f, (float)16/(float)9, 0.1f, 100.0f);
    camView = glm::lookAt(glm::vec3(0, 3, -4), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
}

void MainScene::Add(IObject* object) {
    MainScene::objects.push_back(object);
    objects.back()->SetPerspective(camPers);
    objects.back()->SetCamera(camView);
}

void MainScene::Remove(IObject* object) {
    for (int i = 0; i < objects.size(); i++) {
        if (objects[i] == object) {
            objects.erase(objects.begin() + i);
        }
    }
}

void MainScene::Render() {
    for (auto & object : objects) {
        object->Render();
    }
}

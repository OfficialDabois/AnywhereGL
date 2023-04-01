#include <glad/glad.h>
#include "MainScene.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

MainScene::MainScene() {
    //changes the camera view
    camPers = glm::perspective(glm::radians(45.0f), (float)1920/(float)1080, 0.1f, 100.0f);
    camView = glm::lookAt(glm::vec3(0, 5, -10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
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

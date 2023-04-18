#include "MainScene.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../Util/Camera.h"

MainScene::MainScene(Camera* camera) {
    camView = camera->view;
    camPers = camera->perspective;
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

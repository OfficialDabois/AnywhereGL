#include "MainScene.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void MainScene::Add(IObject* object) {
    MainScene::objects.push_back(object);
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

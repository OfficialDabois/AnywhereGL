#include "MainScene.h"
#include "../Objects/3D/Cube/Cube.h"
#include <iostream>

MainScene::MainScene(Camera* camera) {
    camView = camera->view;
    camPers = camera->perspective;
}

void MainScene::UpdateLighting(IObject* object) {
    if (object->isLight) {
        for (int j = 0; j < objects.size(); j++) {
            if (!objects[j]->isLight) {
                Cube* temp = dynamic_cast<Cube*>(objects[j]);
                Light* tempLight = dynamic_cast<Light*>(object);

                temp->SetLight(tempLight);
            }
        }
    }
}

void MainScene::Add(IObject* object) {
    MainScene::objects.push_back(object);
    objects.back()->SetPerspective(camPers);
    objects.back()->SetCamera(camView);
    UpdateLighting(object);
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

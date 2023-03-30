#include <iostream>
#include <glad/glad.h>
#include "Scene/MainScene.h"
#include "Objects/3D/Cube.h"
#include "Util/Window.h"

int main() {
    MainScene mainScene;
    Window window = Init("Hello world", 1920, 1080);

    Cube cube(glm::vec3(0, 0, 0));
    Cube cubeT(glm::vec3(5, 1, 5));
    Cube cubeD(glm::vec3(2, 2, 4));
    Cube cubeF(glm::vec3(1, 3, 7));
    Cube cubeG(glm::vec3(3, -1, 7));
    Cube cubeV(glm::vec3(2, -1, 6));

    cube.SetTexture("../Objects/3D/container.jpg");
    cubeT.SetTexture("../Objects/3D/teams.jpg");
    cubeF.SetTexture("../Objects/3D/container.jpg");

    cube.Rotate(45.0f, glm::vec3(1.0f, 0.0f, 0.0f));

    mainScene.Add(&cube);
    mainScene.Add(&cubeT);
    mainScene.Add(&cubeD);
    mainScene.Add(&cubeF);
    mainScene.Add(&cubeG);
    mainScene.Add(&cubeV);

    glEnable(GL_DEPTH_TEST);

    while(!ShouldWindowClose(window)) {
        glClearColor(0.5f, 0.1f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        cubeT.Rotate(0.5f, glm::vec3(1.0f, 0.0f, 0.0f));

        mainScene.Render();

        SwapBuffers(window);
        PollEvents();
    }
}

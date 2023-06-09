#include <glad/glad.h>
#include <vector>
#include "Scene/MainScene.h"
#include "Objects/3D/Cube/Cube.h"
#include "Objects/3D/Light/Light.h"
#include "Util/Window.h"
#include "Util/Camera.h"

int main() {
    Window window = Init("Hello world", 1920, 1080);

    glm::vec3 lightCol = glm::vec3(1.0f, 0.0f, 0.0f);
    std::vector<Light*> lighting;

    Light lightd(glm::vec3(0, 0, -1), glm::vec3(0.0f, 1.0f, 0.0f));
    Light light(glm::vec3(2, 0, -1), glm::vec3(0.0f, 0.0f, 1.0f));
    Light lightT(glm::vec3(-2, 0, -1), glm::vec3(1.0f, 0.0f, 0.0f));

    lighting.insert(lighting.cend(), &light);
    lighting.insert(lighting.cend(), &lightT);
    lighting.insert(lighting.cend(), &lightd);

    Cube cube(glm::vec3(0, 0, 3), lighting);
    Cube cubeT(glm::vec3(5, 1, 5), lighting);
    Cube cubeD(glm::vec3(2, 2, 4), lighting);
    Cube cubeF(glm::vec3(1, 3, 7), lighting);
    Cube cubeG(glm::vec3(3, -1, 7), lighting);
    Cube cubeV(glm::vec3(2, -1, 6), lighting);

    cube.SetTexture("../Objects/3D/Cube/container.jpg");
    cubeD.SetTexture("../Objects/3D/Cube/container.jpg");
    cubeV.SetTexture("../Objects/3D/Cube/container.jpg");
    cubeT.SetTexture("../Objects/3D/Cube/teams.jpg");
    cubeG.SetTexture("../Objects/3D/Cube/teams.jpg");
    cubeF.SetTexture("../Objects/3D/Cube/teams.jpg");

    cube.Rotate(45.0f, glm::vec3(1.0f, 0.0f, 0.0f));

    Camera camera(glm::vec3(0, 5, -10), glm::vec3(0, 0, 0), glm::radians(45.0f));
    MainScene mainScene(&camera);
    
    mainScene.Add(&cube);
    mainScene.Add(&cubeD);
    mainScene.Add(&cubeV);
    mainScene.Add(&cubeT);
    mainScene.Add(&cubeG);
    mainScene.Add(&cubeF);
    mainScene.Add(&lightd);
    mainScene.Add(&light);
    mainScene.Add(&lightT);

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

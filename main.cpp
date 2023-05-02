#include <glad/glad.h>
#include "Scene/MainScene.h"
#include "Objects/3D/Cube/Cube.h"
#include "Objects/3D/Light/Light.h"
#include "Util/Window.h"
#include "Util/Camera.h"
#include <vector>

int main() {
    Window window = Init("Hello world", 1920, 1080);

    glm::vec3 lightCol = glm::vec3(1.0f, 0.0f, 0.0f);
    std::vector<Light> lights;

    Light light(glm::vec3(4, 0, 1), lightCol);
    Light lightT(glm::vec3(-4, 0, 5), lightCol);

    lights.push_back(light);
    lights.push_back(lightT);

    Cube cube(glm::vec3(0, 0, 0), lights);
    Cube cubeT(glm::vec3(5, 1, 5), lights);
    Cube cubeD(glm::vec3(2, 2, 4), lights);
    Cube cubeF(glm::vec3(1, 3, 7), lights);
    Cube cubeG(glm::vec3(3, -1, 7), lights);
    Cube cubeV(glm::vec3(2, -1, 6), lights);

    cube.SetTexture("../Objects/3D/Cube/container.jpg");
    cubeT.SetTexture("../Objects/3D/Cube/teams.jpg");
    cubeF.SetTexture("../Objects/3D/Cube/container.jpg");

    cube.Rotate(45.0f, glm::vec3(1.0f, 0.0f, 0.0f));

    Camera camera(glm::vec3(0, 5, -10), glm::vec3(0, 0, 0), glm::radians(45.0f));
    MainScene mainScene(&camera);
    
    mainScene.Add(&cube);
    mainScene.Add(&cubeT);
    mainScene.Add(&cubeD);
    mainScene.Add(&cubeF);
    mainScene.Add(&cubeG);
    mainScene.Add(&cubeV);
    mainScene.Add(&light);

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

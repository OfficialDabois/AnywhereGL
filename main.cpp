#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Scene/MainScene.h"
#include "Objects/3D/Cube.h"

void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Setup", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create glfw window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, Framebuffer_Size_Callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    MainScene mainScene;
    Cube cube(glm::vec3(0, 0, 0));
    Cube cubeT(glm::vec3(5, 1, 5));
    Cube cubeD(glm::vec3(2, 2, 4));
    Cube cubeF(glm::vec3(1, 3, 7));
    Cube cubeG(glm::vec3(3, -1, 7));
    Cube cubeV(glm::vec3(2, -1, 6));

    cube.SetTexture("../Objects/3D/teams.jpg");
    cubeT.SetTexture("../Objects/3D/teams.jpg");
    cubeD.SetTexture("../Objects/3D/teams.jpg");
    cubeF.SetTexture("../Objects/3D/teams.jpg");
    cubeV.SetTexture("../Objects/3D/teams.jpg");
    cubeG.SetTexture("../Objects/3D/teams.jpg");

    mainScene.Add(&cube);
    mainScene.Add(&cubeT);
    mainScene.Add(&cubeD);
    mainScene.Add(&cubeF);
    mainScene.Add(&cubeG);
    mainScene.Add(&cubeV);

    glEnable(GL_DEPTH_TEST);

    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.5f, 0.1f, 0.9f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mainScene.Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

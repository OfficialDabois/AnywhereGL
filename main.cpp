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
    Cube cube;

    mainScene.Add(&cube);

    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.5f, 0.1f, 0.9f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        mainScene.Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

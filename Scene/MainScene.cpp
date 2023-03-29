#include <glad/glad.h>
#include "MainScene.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

MainScene::MainScene() {
    int width, height;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Setup", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create glfw window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, Framebuffer_Size_Callback);
    MainScene::window = window;

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glfwGetWindowSize(window, &width, &height);

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

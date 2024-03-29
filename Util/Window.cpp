#include <glad/glad.h>
#include "Window.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

Window Init(const char* title, int width, int height) {
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

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    return window;
}

bool ShouldWindowClose(Window window) {
    if (glfwWindowShouldClose(window))
        return true;
    return false;
}

void SwapBuffers(Window window) {
    glfwSwapBuffers(window);
}

void PollEvents() {
    glfwPollEvents();
}

void SetColour(glm::vec3 colour) {
    glClearColor(colour.x, colour.y, colour.z, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

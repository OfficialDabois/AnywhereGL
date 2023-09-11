#ifndef AGL_WINDOW_H
#define AGL_WINDOW_H
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>

typedef GLFWwindow* Window;

Window Init(const char* title, int width, int height);

void SetColour(glm::vec3 colour);

bool ShouldWindowClose(Window window);
void PollEvents();
void SwapBuffers(Window window);

#endif

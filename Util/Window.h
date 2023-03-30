#ifndef AGL_WINDOW_H
#define AGL_WINDOW_H
#include <GLFW/glfw3.h>
#include <iostream>

typedef GLFWwindow* Window;

Window Init(const char* title, int width, int height);

bool ShouldWindowClose(Window window);
void PollEvents();
void SwapBuffers(Window window);

#endif

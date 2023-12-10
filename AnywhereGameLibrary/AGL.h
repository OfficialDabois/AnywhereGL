#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <chrono>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>
#include "Scene/MainScene.h"
#include "Objects/3D/Cube/Cube.h"
#include "Objects/3D/Light/Light.h"
#include "Util/Window.h"
#include "Util/Camera.h"
#include "Physics/AGLPhys.h"
#include "Shader/Shader.h"
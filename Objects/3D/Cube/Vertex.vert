#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

uniform mat4 mvp;

out vec3 myCol;
out vec3 myNormal;

void main() {
    gl_Position =  mvp * vec4(aPos, 1.0f);
    myNormal = aNormal;
    myCol = vec3(0.7059, 0, 0.7059);
}
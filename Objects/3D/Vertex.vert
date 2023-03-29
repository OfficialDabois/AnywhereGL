#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;

uniform mat4 mvp;

out vec2 myTex;
out vec3 myCol;

void main() {
    gl_Position =  mvp * vec4(aPos, 1.0f);
    myTex = aTex;
    myCol = vec3(0.7059, 0, 0.7059);
}
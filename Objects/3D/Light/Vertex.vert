#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

uniform mat4 mvp;

uniform vec3 lCol;

out vec3 aCol;
out vec3 myNormal;

void main() {
    myNormal = aNormal;
    aCol = lCol;
    gl_Position = mvp * vec4(aPos, 1.0);
}

#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTex;

uniform vec3 lightColour;
uniform mat4 vp;
uniform mat4 model;

out vec3 myNormal;
out vec2 texCoord;
out vec3 crntPos;

void main() {
    crntPos = vec3(model * vec4(aPos, 1.0));
    myNormal = mat3(transpose(inverse(model))) * aNormal;
    texCoord = aTex;
    gl_Position = vp * model * vec4(aPos, 1.0f);
}
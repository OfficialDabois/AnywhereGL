#version 330 core

in vec2 myTex;
in vec3 myCol;
out vec4 FragColor;

uniform sampler2D myTexture;

void main() {
    FragColor = texture(myTexture, myTex);
}
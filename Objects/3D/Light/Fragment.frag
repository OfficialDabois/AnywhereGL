#version 330 core

in vec3 aCol;
out vec4 FragColour;

void main() {
    FragColour = vec4(aCol, 1.0);
}

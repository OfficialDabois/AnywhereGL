#version 330 core

float ambientConst = 0.1;

in vec3 myNormal;
in vec3 myCol;
out vec4 FragColor;

uniform sampler2D myTexture;

uniform vec3 lightColour;
uniform vec3 objectColour;

void main() {
    vec3 ambient = ambientConst * lightColour;

    vec3 result = ambient * objectColour;
    FragColor = vec4(result, 1.0);
}
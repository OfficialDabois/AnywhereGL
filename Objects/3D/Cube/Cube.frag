#version 330 core

float ambientConst = 0.2;

in vec3 myNormal;
in vec3 crntPos;
in vec2 texCoord;

out vec4 FragColor;

vec3 lightCol = vec3(1.0, 1.0, 1.0);

uniform vec3 objectColour;
uniform vec3 lightPos;
uniform sampler2D textureLook;

void main() {
    vec3 norm = normalize(myNormal);
    vec3 lightDir = normalize(lightPos - crntPos);
    float diff = max(dot(norm, lightDir), 0.0);

    vec3 result = (ambientConst + vec3(diff * lightCol)) * objectColour;

    FragColor =  texture(textureLook, texCoord) * vec4(result, 1.0);
}
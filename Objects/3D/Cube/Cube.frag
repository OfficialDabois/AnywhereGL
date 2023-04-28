#version 330 core

float ambientConst = 0.2;

in vec3 myNormal;
in vec3 crntPos;
in vec2 texCoord;

out vec4 FragColor;

uniform vec3 lightCol;
uniform vec3 objectColour;
uniform vec3 lightPos;
uniform sampler2D textureLook;

vec3 LightCalc() {
    vec3 norm = normalize(myNormal);
    vec3 lightDir = normalize(lightPos - crntPos);
    float diff = max(dot(norm, lightDir), 0.0);

    vec3 result = (ambientConst + vec3(diff * lightCol)) * objectColour;

    return result;
}

void main() {
    vec3 calc = LightCalc();



    FragColor =  texture(textureLook, texCoord) * vec4(calc, 1.0);
}
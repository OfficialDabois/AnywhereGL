#version 330 core

float ambientConst = 0.1;

in vec3 myNormal;
in vec3 crntPos;
in vec2 texCoord;

out vec4 FragColor;

struct Light {
    vec3 Pos;
    vec3 Color;
};

uniform vec3 objectColour;
uniform sampler2D textureLook;
uniform Light lights[10];

vec3 LightCalc() {
    vec3 norm = normalize(myNormal);


    vec3 result;

    for (int i = 0; i < 10; i++)
    {
        vec3 lightDir = normalize(lights[i].Pos - crntPos);
        float diff = max(dot(norm, lightDir), 0.0);
        result += (ambientConst + vec3(diff * lights[i].Color)) * objectColour;
    }

    return result;
}

void main() {
    vec3 calc = LightCalc();

    FragColor =  texture(textureLook, texCoord) * vec4(calc, 1.0);
}
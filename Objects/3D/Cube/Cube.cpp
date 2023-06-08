#include "glad/glad.h"
#include "Cube.h"
#include <utility>
#include <string>
#include "glm/gtc/matrix_transform.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Cube::Cube(glm::vec3 pos, std::vector<Light> lights) : shader("../Objects/3D/Cube/Cube.vert", "../Objects/3D/Cube/Cube.frag") {
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);

    quModel = glm::translate(quModel, pos);
    Cube::lights = std::move(lights);
}

Cube::~Cube() {
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shader.ID);
}

void Cube::SetCamera(glm::mat4 camUpdate) {
    quCamUpdate = camUpdate;
}

void Cube::SetPerspective(glm::mat4 persUpdate) {
    quPersUpdate = persUpdate;
}

//If you don't want to scale a value set it to 1
void Cube::Scale(glm::vec3 scale) {
    quModel = glm::scale(quModel, scale);
}

//Normalize axis
void Cube::Rotate(float angle, glm::vec3 axis) {
    quModel = glm::rotate(quModel, glm::radians(angle), axis);
}

void Cube::SetTexture(const char* fileLoc) {
    unsigned int texture;

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(fileLoc, &width, &height, &nrChannels, 0);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        textureG = texture;
    }

    stbi_image_free(data);
}

void Cube::Render() {
    glBindVertexArray(VAO);

    shader.Use();
    shader.Vec3Uniform("objectColour", glm::vec3(0.3f, 0.3f, 0.3f));

    glBindTexture(GL_TEXTURE_2D, textureG);
    glm::mat4 vp = quPersUpdate * quCamUpdate;

    for (int i = 0; i < Cube::lights.size(); i++) {
        std::string valueCol = "lights[" + std::to_string(i) + "].Color";
        std::string valuePos = "lights[" + std::to_string(i) + "].Pos";

        shader.Vec3Uniform(valueCol.c_str(), Cube::lights[i].colour);
        shader.Vec3Uniform(valuePos.c_str(), Cube::lights[i].pos);
    }

    shader.Mat4Uniform("vp", vp);
    shader.Mat4Uniform("model", quModel);

    glDrawArrays(GL_TRIANGLES, 0, 36);
}
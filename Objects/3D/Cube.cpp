#include "Cube.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <optional>
#define STB_IMAGE_IMPLEMENTATION
#include "../../include/stb_image.h"

Cube::Cube(glm::vec3 pos) {
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    quModel = glm::translate(quModel, pos);
}

Cube::~Cube() {
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
}

void Cube::SetCamera(glm::mat4 camUpdate) {
    quCamUpdate = camUpdate;
}

void Cube::SetPerspective(glm::mat4 persUpdate) {
    quPersUpdate = persUpdate;
}

void Cube::SetTexture(const char* fileLoc) {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;

    unsigned char* data = stbi_load(fileLoc, &width, &height, &nrChannels, 0);

    if (data) {
        unsigned int texture;
        glGenTextures(1, &texture);

        glBindTexture(GL_TEXTURE_2D, texture);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, texture);
    }

    stbi_image_free(data);
}

Shader Cube::shader() {
    return {"../Objects/3D/Vertex.vert", "../Objects/3D/Fragment.frag"};
}

void Cube::Render() {
    shader().Use();
    quModel = glm::rotate(quModel, glm::radians(0.5f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 mvp = quPersUpdate * quCamUpdate * quModel;
    shader().Mat4Uniform("mvp", mvp);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
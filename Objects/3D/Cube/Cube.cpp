#include "glad/glad.h"
#include "Cube.h"
#include "glm/gtc/matrix_transform.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Cube::Cube(glm::vec3 pos) : shader("../Objects/3D/Cube/Vertex.vert", "../Objects/3D/Cube/Fragment.frag") {
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    quModel = glm::translate(quModel, pos);
    lightColour = glm::vec3(1.0f, 1.0f, 1.0f);
    objectColour = glm::vec3(1.0f, 0.5f, 0.31f);
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

//If you do\n't want to scale a value set it to 1
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

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_MIRRORED_REPEAT);
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
    shader.Use();
    shader.Vec3Uniform("lightColour", glm::vec3(1.0f, 1.0f, 1.0f));
    shader.Vec3Uniform("objectColour", glm::vec3(1.0f, 0.5f, 0.31f));

    glBindTexture(GL_TEXTURE_2D, textureG);
    glm::mat4 mvp = quPersUpdate * quCamUpdate * quModel;
    shader.Mat4Uniform("mvp", mvp);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}
#include "Cube.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>


Cube::Cube() {
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
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

Shader Cube::shader() {
    return {"../Objects/3D/Vertex.vert", "../Objects/3D/Fragment.frag"};
}

void Cube::Render() {
    shader().Use();
    quModel = glm::rotate(quModel, glm::radians(0.5f), glm::vec3(0, 1, 0));
    glm::mat4 mvp = quPersUpdate * quCamUpdate * quModel;
    shader().Mat4Uniform("mvp", mvp);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
#include <glad/glad.h>
#include "Light.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

Light::Light(glm::vec3 pos)  : shader("../Objects/3D/Light/Vertex.vert", "../Objects/3D/Light/Fragment.frag"){
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

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    quModel = glm::translate(quModel, pos);
    Light::pos = pos;
}

Light::~Light() {
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shader.ID);
}

void Light::SetCamera(glm::mat4 camUpdate) {
    quCamUpdate = camUpdate;
}

void Light::SetPerspective(glm::mat4 persUpdate) {
    quPersUpdate = persUpdate;
}

void Light::Render() {
    shader.Use();
    glm::mat4 mvp = quPersUpdate * quCamUpdate * quModel;
    shader.Mat4Uniform("mvp", mvp);

    glDrawArrays(GL_TRIANGLES, 0, 36);
}
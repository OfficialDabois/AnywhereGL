#ifndef AGL_CUBE_H
#define AGL_CUBE_H

#include "../Interface/IObject.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Include/Shader/Shader.h"

class Cube : public IObject {
public:
    void SetCamera(glm::mat4 quCamUpdate) override;
    void SetPerspective(glm::mat4 quPersUpdate) override;
    void Render() override;
private:
    static constexpr float cubeVertices[] = {
        -1.0f, 1.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
         0.0f, 0.0f, 0.0f,
         0.0f, 1.0f, 0.0f,

            -1.0f, 1.0f, 1.0f,
            -1.0f, 0.0f, 1.0f,

            0.0f, 1.0f, 1.0f,
            0.0f, 0.0f, 1.0f
    };

    static constexpr unsigned int indices[] = {
        0, 1, 2,
        0, 3, 2,

        0, 1, 5,
        4, 5, 0,

        2, 3, 7,
        7, 6, 3,

        4, 5, 7,
        7, 6, 4,

        4, 6, 3,
        3, 0, 4,

        1, 2, 5,
        5, 7, 1

    };

    void Init() {
        unsigned int VAO, VBO, EBO;

        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        glGenVertexArrays(1, &VAO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);


    }
};

#endif

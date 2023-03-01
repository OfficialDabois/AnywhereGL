#ifndef AGL_CUBE_H
#define AGL_CUBE_H
#include <../Interface/IObject.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

class Cube : public IObject {
public:
    void SetCamera(glm::mat4 camUpdate) override;
    void SetPerspective(glm::mat4 persUpdate) override;
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
};

#endif

#ifndef SGL_SHADER_H
#define SGL_SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);

    void Use();

    void FloatUniform(const char* name, GLfloat value);
    void IntUniform(const char* name, GLint value);
    void UIntUniform(const char* name, GLuint value);
    void Mat4Uniform(const char* name, glm::mat4 value);
    void CleanUp();
};

#endif

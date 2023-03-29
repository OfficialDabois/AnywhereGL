#ifndef SGL_SHADER_H
#define SGL_SHADER_H

#include <glm/glm.hpp>

class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);

    void Use();

    void FloatUniform(const char* name, float value);
    void IntUniform(const char* name, int value);
    void UIntUniform(const char* name, unsigned int value);
    void Mat4Uniform(const char* name, const glm::mat4& value)const;
    void CleanUp();
};

#endif

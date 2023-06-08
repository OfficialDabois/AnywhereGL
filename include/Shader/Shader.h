#ifndef SGL_SHADER_H
#define SGL_SHADER_H

#include <glm/glm.hpp>

class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);

    void Use();

    void Vec3Uniform(const char* name, glm::vec3 value) const;
    void Mat4Uniform(const char* name, const glm::mat4& value)const;
    void CleanUp();
};

#endif

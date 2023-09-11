#include "Shader.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const char* vertexPath, const char* fragmentPath) {
    std::string sVertSource, sFragSource;
    std::ifstream vFile, fFile;

    //Checks ifstream error checking
    vFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);

    try {
        std::stringstream streamVertSource, streamFragSource;

        vFile.open(vertexPath);
        fFile.open(fragmentPath);

        streamVertSource << vFile.rdbuf();
        streamFragSource << fFile.rdbuf();

        sVertSource = streamVertSource.str();
        sFragSource = streamFragSource.str();

        vFile.close();
        fFile.close();
    }
    catch(std::ifstream::failure e) {
        std::cerr << "Failed to read shader file\n" << std::endl;
    }

    const char* vertSource = sVertSource.c_str();
    const char* fragSource = sFragSource.c_str();

    unsigned int vertShader, fragShader;

    vertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShader, 1, &vertSource, NULL);
    glCompileShader(vertShader);

    int success;
    char infoLog[512];

    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILURE\n" << infoLog << std::endl;
    }

    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragSource, NULL);
    glCompileShader(fragShader);

    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILURE\n" << infoLog << std::endl;
    }

    ID = glCreateProgram();
    glAttachShader(ID, vertShader);
    glAttachShader(ID, fragShader);
    glLinkProgram(ID);

    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::PROGRAM::LINK_FAILURE\n" << infoLog << std::endl;
    }

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
}

void Shader::Use() {
    glUseProgram(ID);
}

void Shader::Vec3Uniform(const char* name, glm::vec3 value) const {
    int loc = glGetUniformLocation(ID, name);
    glUniform3f(loc, value.x, value.y, value.z);
}

void Shader::Mat4Uniform(const char* name, const glm::mat4& value) const{
    int loc = glGetUniformLocation(ID, name);
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::CleanUp() {
    glDeleteProgram(ID);
}
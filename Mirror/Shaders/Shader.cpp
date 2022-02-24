#include "Shader.hpp"
#include <fstream>
#include <sstream>

namespace Mirror
{
    Shader::Shader(const char* vertName, const char* fragName)
    {
        this->program = glCreateProgram();
        DLOG("created program");
        unsigned int vert = compileShader(vertName, GL_VERTEX_SHADER);
        unsigned int frag = compileShader(fragName, GL_FRAGMENT_SHADER);
        DLOG("shaders created");
        glAttachShader(program, vert);
        glAttachShader(program, frag);
        DLOG("shaders attached");
        glLinkProgram(program);
        DLOG("shaders linked");
        glDeleteShader(vert);
        glDeleteShader(frag);
    }

    Shader::~Shader()
    {
        glDeleteProgram(this->program);
        DLOG("deleted program");
    }

    void Shader::use()
    {
        glUseProgram(program);
    }

    void Shader::setInt(const char* name, int val)
    {
        glUniform1i(glGetUniformLocation(program, name), val);
    }

    void Shader::setFloat(const char* name, float val)
    {
        glUniform1f(glGetUniformLocation(program, name), val);
    }

    void Shader::setBool(const char* name, bool val)
    {
        glUniform1i(glGetUniformLocation(program, name), val);
    }

    void Shader::setMat4F(const char* name, glm::mat4 val)
    {
        glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, glm::value_ptr(val));
    }

    unsigned int Shader::compileShader(const char* path, GLenum type)
    {
        unsigned int shader;
        std::ifstream file;
        std::stringstream stream;
        std::string str;

        file.open(path);
        stream << file.rdbuf();
        file.close();
        str = stream.str();
        const char* src = str.c_str();
        
        shader = glCreateShader(type);
        glShaderSource(shader, 1, &src, NULL);
        glCompileShader(shader);
        char buf[512];
        glGetShaderInfoLog(shader, 512, NULL, buf);
        DLOG(buf);

        return shader;
    }
}
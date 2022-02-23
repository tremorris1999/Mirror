#pragma once
#include "MirrorCore.hpp"

namespace Mirror
{
    class Shader
    {
        public:

        Shader(const char* vertName, const char* fragName);
        ~Shader();
        unsigned int compileShader(const char* path, GLenum type);
        void use();
        void setInt(const char* name, int val);
        void setFloat(const char* name, float val);
        void setBool(const char* name, bool val);
        void setMat4F(const char* name, glm::mat4 val);

        private:
        
        unsigned int program;
    };
}

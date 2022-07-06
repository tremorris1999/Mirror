#pragma once
#include "mirror_core.h"

namespace mirror
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
        void setVec3F(const char* name, float f1, float f2, float f3);

        private:
        
        unsigned int program;
    };
}

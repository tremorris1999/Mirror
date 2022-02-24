#pragma once
#include "MirrorCore.hpp"
#include "Shaders/Shader.hpp"
#include "Renderable/IRenderable.hpp"
#include <stb/stb_image.h>

namespace Mirror
{
    class RenderManager
    {
        public:
        RenderManager();
        ~RenderManager();
        void Render();
        void CreateRendObj(float* position, float* vertices, int numVerts, int* indices, int numInd, float* textureCoords, int numTC);
        unsigned int getCurrentShader();

        private:
        Shader* shader;
        unsigned int VAO;
        unsigned int* VBO;
        unsigned int EBO;
    };
}
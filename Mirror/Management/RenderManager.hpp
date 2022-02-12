#pragma once
#include "../Mirror/MirrorCore.hpp"
#include "../Mirror/Shaders/Shader.hpp"
#include "../Mirror/Renderable/IRenderable.hpp"
#include "../Mirror/Renderable/Model.hpp"

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
#pragma once
#include "IRenderable.hpp"

namespace Mirror
{
    class StaticObject : public IRenderable
    {
        public:
        StaticObject(unsigned int VAO, unsigned int* VBO, unsigned int EBO, float* position, float* vertices, int numVerts, int* indices, int numInd, float* textureCoords, int numTC);
        void render(Shader &shader) override;

        private:
        float* verts;
        int numVerts;
        int* indices;
        int numInd;
        float* textureCoords;
        int numTC;
    };
}
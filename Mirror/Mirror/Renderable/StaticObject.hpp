#pragma once
#include "RenderableObject.hpp"

namespace Mirror
{
    class StaticObject : public RenderableObject
    {
        public:
        StaticObject(float* position);
        StaticObject(float* position, float* vertices, int numVerts);
        void render() override;

        private:
        float* verts;
        int numVerts;
    };
}
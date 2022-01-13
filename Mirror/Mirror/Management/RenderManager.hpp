#pragma once
#include "../Mirror/MirrorCore.hpp"
#include "../Mirror/Util/IO.hpp"
#include "../Mirror/Renderable/RenderableObject.hpp"
#include "../Mirror/Renderable/StaticObject.hpp"

namespace Mirror
{
    class RenderManager
    {
        public:
        RenderManager();
        ~RenderManager();
        void Render();
        void CreateRendObj(float* position, float* vertices, int numVerts);
        RenderableObject* object = NULL;

        private:
        unsigned int VBO;
        unsigned int program;
        unsigned int v_shader;
        unsigned int f_shader;
    };
}
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
        void AddModel(std::string path);
        Shader getShader();

        private:
        Shader* shader;
        std::vector<IRenderable*> items;
    };
}
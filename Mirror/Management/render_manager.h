#pragma once
#include "MirrorCore.hpp"
#include "Shaders/Shader.hpp"
#include "Renderable/renderable.h"
#include <stb/stb_image.h>

namespace mirror
{
    class RenderManager
    {
        public:
        RenderManager();
        ~RenderManager();
        void render();
        void addModel(std::string path);
        Shader getShader();

        private:
        Shader* m_shader;
        std::vector<Renderable> m_items;
    };
}
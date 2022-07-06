#pragma once
#include "mirror_core.h"
#include "Shaders/shader.h"
#include "Renderable/renderable.h"
#include <vector>
#include <memory>

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
        std::vector<std::unique_ptr<Renderable>> m_items;
    };
}
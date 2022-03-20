#include "RenderManager.hpp"
#include "Renderable/StaticObject.hpp"
#include "Renderable/Model.hpp"

namespace Mirror
{
    IRenderable* item;

    RenderManager::RenderManager()
    {
        shader = new Shader("C:\\dev\\Mirror\\Mirror\\Shaders\\vert.glsl", "C:\\dev\\Mirror\\Mirror\\Shaders\\frag.glsl");
        shader->use();
        shader->setMat4F("view", glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -10.0f)));
        shader->setMat4F("projection", glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f));
        DLOG("render manager created");
    }

    RenderManager::~RenderManager()
    {   
        delete shader;
        DLOG("render manager deleted");
    }

    void RenderManager::AddModel(std::string path)
    {
        items.push_back(new Model(path));
    }

    void RenderManager::Render()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader->use();
        shader->setMat4F("model", glm::rotate(glm::mat4(1.0f), 3 * (float)glfwGetTime() * glm::radians(25.0f), glm::vec3(0, 1.0f, 0)));
        shader->setVec3F("light_position", 5, 1, 10);
        shader->setVec3F("view_position", 0, 1, 3.0);

        for (IRenderable* item : items)
            if (item)
                item->render(*shader);
    }

    Shader RenderManager::getShader()
    {
        return *shader;
    }
}
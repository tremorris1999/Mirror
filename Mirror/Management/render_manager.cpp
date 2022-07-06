#include "render_manager.h"
#include "Renderable/model.h"

namespace mirror
{
    RenderManager::RenderManager()
    {
        m_shader = new Shader("C:\\dev\\Mirror\\Mirror\\Shaders\\vert.glsl", "C:\\dev\\Mirror\\Mirror\\Shaders\\frag.glsl");
        m_shader->use();
        m_shader->setMat4F("view", glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -10.0f)));
        m_shader->setMat4F("projection", glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f));
        DLOG("render manager created");
    }

    RenderManager::~RenderManager()
    {   
        delete m_shader;
        DLOG("render manager deleted");
    }

    void RenderManager::addModel(std::string path)
    {
        Model* model = new Model(path);
        m_items.push_back(std::unique_ptr<Renderable>(model));
    }

    void RenderManager::render()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_shader->use();
        m_shader->setMat4F("model", glm::rotate(glm::mat4(1.0f), 3 * (float)glfwGetTime() * glm::radians(25.0f), glm::vec3(0, 1.0f, 0)));
        m_shader->setVec3F("light_position", 5, 1, 10);
        m_shader->setVec3F("view_position", 0, 1, 3.0);

        for(int i = 0; i < m_items.size(); i++)
            m_items[i]->render(*m_shader);
    }

    Shader RenderManager::getShader()
    {
        return *m_shader;
    }
}
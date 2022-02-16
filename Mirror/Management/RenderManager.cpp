#include "RenderManager.hpp"
#include "../Renderable/StaticObject.hpp"

namespace Mirror
{
    IRenderable* object = NULL;

    RenderManager::RenderManager()
    {
        shader = new Shader("../Mirror/Shaders/vert.glsl", "../Mirror/Shaders/frag.glsl");
        shader->use();
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        VBO = (unsigned int*)malloc(sizeof(int));
        glGenBuffers(2, VBO);
        glGenBuffers(1, &EBO);
        //shader->setMat4F("view", glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f)));
        shader->setMat4F("projection", glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f));
    }

    RenderManager::~RenderManager()
    {   
        delete shader;
    }

    void RenderManager::CreateRendObj(float* position, float* vertices, int numVerts, int* indices, int numInd, float* textureCoords, int numTC)
    {
        object = new StaticObject(VAO, VBO, EBO, position, vertices, numVerts, indices, numInd, textureCoords, numTC);
        //object = new Mirror::Model("C:/dev/Mirror/res/grass.obj"); 
    }

    void RenderManager::Render()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader->use();
        //shader->setMat4F("model", glm::rotate(glm::mat4(1.0f), 3 * (float)glfwGetTime() * glm::radians(25.0f), glm::vec3(-0.25f, 1.0f, 0.5f)));
        //shader->setMat4F("view", glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, (float)glm::sin(glfwGetTime() * -3.0f) - 3.0f)));
        shader->setMat4F("model", glm::mat4(1.0f));
        shader->setMat4F("view", glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -3.0)));
        glBindVertexArray(VAO);
        if(object != nullptr)
        {
            object->render(*shader);
        }
    }
}
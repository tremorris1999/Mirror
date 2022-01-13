#include "RenderManager.hpp"

namespace Mirror
{
    

    unsigned int VBO;
    unsigned int VAO;
    unsigned int v_shader;
    unsigned int f_shader;
    unsigned int program;

    RenderManager::RenderManager()
    {
        v_shader = glCreateShader(GL_VERTEX_SHADER);
        const char* v_src = readFile("../Mirror/Shaders/vertex.glsl");
        glShaderSource(v_shader, 1, &v_src, NULL);
        free((void*)v_src);
        glCompileShader(v_shader);


        f_shader = glCreateShader(GL_FRAGMENT_SHADER);
        const char* f_src = readFile("../Mirror/Shaders/frag.glsl");
        glShaderSource(f_shader, 1, &f_src, NULL);
        free((void*)f_src);
        glCompileShader(f_shader);

        program = glCreateProgram();
        glAttachShader(program, v_shader);
        glAttachShader(program, f_shader);
        glLinkProgram(program);

        glDeleteShader(v_shader);
        glDeleteShader(f_shader);
        
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
    }

    RenderManager::~RenderManager()
    {

    }

    void RenderManager::CreateRendObj(float* position, float* vertices, int numVerts)
    {
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        object = new StaticObject(position, vertices, numVerts);
    }

    void RenderManager::Render()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);
        glBindVertexArray(VAO);
        if(object != nullptr)
        {
            object->render();
        }
    }
}
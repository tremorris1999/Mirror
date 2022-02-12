#include "WindowManager.hpp"

namespace Mirror
{
    WindowManager::WindowManager(int w, int h, const char* name)
    {
        glfwInit();
        window = glfwCreateWindow(w, h, name, NULL, NULL);
        if(window == NULL)
        {
            printf("Failed to create window.\r\n");
            glfwTerminate();
            exit(-1);
        }

        glfwMakeContextCurrent(window);
        glViewport(0, 0, w, h);
        glfwSetFramebufferSizeCallback(window, resize);
        glewInit();

        glEnable(GL_DEPTH_TEST);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    WindowManager::~WindowManager()
    {
        glfwTerminate();
    }

    GLFWwindow* WindowManager::getWindow()
    {
        return window;
    }

    void resize(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

}
#include "WindowManager.hpp"

namespace Mirror
{
    WindowManager::WindowManager(int w, int h, const char* name)
    {
        glfwInit();
        DLOG("glfw initialized");
        window = glfwCreateWindow(w, h, name, NULL, NULL);
        if(window == NULL)
        {
            ELOG("Failed to create window.\r\n");
            glfwTerminate();
            exit(-1);
        }
        DLOG("window created");

        glfwMakeContextCurrent(window);
        glViewport(0, 0, w, h);
        glfwSetFramebufferSizeCallback(window, resize);
        glewInit();
        DLOG("glew initialized");

        glEnable(GL_DEPTH_TEST);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    WindowManager::~WindowManager()
    {
        glfwTerminate();
        DLOG("glfw terminated");
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
#include "window_manager.h"

namespace mirror
{
    WindowManager::WindowManager(int w, int h, const char* name)
    {
        glfwInit();
        DLOG("glfw initialized");
        m_window = glfwCreateWindow(w, h, name, NULL, NULL);
        if(m_window == NULL)
        {
            ELOG("Failed to create window.\r\n");
            glfwTerminate();
            exit(-1);
        }
        DLOG("window created");

        glfwMakeContextCurrent(m_window);
        glViewport(0, 0, w, h);
        glfwSetFramebufferSizeCallback(m_window, resize);
        glewInit();
        DLOG("glew initialized");

        glEnable(GL_DEPTH_TEST);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    WindowManager::~WindowManager()
    {
        DLOG("window deleted");
        glfwTerminate();
        DLOG("glfw terminated");
    }

    GLFWwindow* WindowManager::getWindow()
    {
        return m_window;
    }

    void resize(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

}
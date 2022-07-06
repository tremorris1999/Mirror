#include "mirror_core.h"
#include "Management/window_manager.h"
#include "Management/render_manager.h"
#include <mirrorlog/MirrorLog.hpp>
#include "Shaders/shader.h"

int main()
{
    MirrorLog::ConsoleLogger consoleLogger;
    consoleLogger.Log(MirrorLog::LogType::Debug, "Console logger created");

    MirrorLog::SetLogger(consoleLogger);
    DLOG("Set global logger");

    mirror::WindowManager wm(1280, 720, "Test Window");
    mirror::RenderManager rm;
    mirror::Shader shader = rm.getShader();

    rm.addModel("C:\\dev\\Mirror\\res\\backpack.obj");
    rm.addModel("C:\\dev\\Mirror\\res\\bunny.obj");

    while(!glfwWindowShouldClose(wm.getWindow()))
    {
        glClearColor(0, 1, 1, 1);
        rm.render();
        glfwSwapBuffers(wm.getWindow());
        glfwPollEvents();
    }
}

#include "MirrorCore.hpp"
#include "Management/WindowManager.hpp"
#include "Management/RenderManager.hpp"
#include <mirrorlog/MirrorLog.hpp>
#include "Shaders/Shader.hpp"

int main()
{
    MirrorLog::ConsoleLogger consoleLogger;
    consoleLogger.Log(MirrorLog::LogType::Debug, "Console logger created");

    MirrorLog::SetLogger(consoleLogger);
    DLOG("Set global logger");

    Mirror::WindowManager wm(1280, 720, "Test Window");
    Mirror::RenderManager rm;
    Mirror::Shader shader = rm.getShader();

    rm.AddModel("C:\\dev\\Mirror\\res\\backpack.obj");
    rm.AddModel("C:\\dev\\Mirror\\res\\bunny.obj");

    while(!glfwWindowShouldClose(wm.getWindow()))
    {
        glClearColor(0, 1, 1, 1);
        rm.Render();
        glfwSwapBuffers(wm.getWindow());
        glfwPollEvents();
    }
}

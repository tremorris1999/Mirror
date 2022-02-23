#include "MirrorCore.hpp"
#include "Management/WindowManager.hpp"
#include "Management/RenderManager.hpp"
#include <mirrorlog/MirrorLog.hpp>

int main()
{
    MirrorLog::ConsoleLogger consoleLogger;
    consoleLogger.Log(MirrorLog::LogType::Debug, "Console logger created");

    MirrorLog::SetLogger(consoleLogger);
    MirrorLog::LogDebug("Set global logger");

    Mirror::WindowManager wm(1280, 720, "Test Window");
    MirrorLog::LogDebug("Created window manager");
    Mirror::RenderManager rm;

    //temp
    float pos[]
    {
        0.0, 0.0, 0.0
    };

    float verts[]
    {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
    };

    int inds[]
    {
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
    };

    float texC[]
    {
        1, 1,
        1, 0,
        0, 0,
        0, 1
    };

    rm.CreateRendObj(pos, verts, 12, inds, 6, texC, 8);

    while(!glfwWindowShouldClose(wm.getWindow()))
    {
        glClearColor(0, 1, 1, 1);
        rm.Render();
        glfwSwapBuffers(wm.getWindow());
        glfwPollEvents();
    }
}

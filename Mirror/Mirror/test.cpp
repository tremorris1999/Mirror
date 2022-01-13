#include "../Mirror/MirrorCore.hpp"
#include "../Mirror/Management/WindowManager.hpp"
#include "../Mirror/Management/RenderManager.hpp"
#include "../Mirror/Renderable/StaticObject.hpp"

int main()
{
    Mirror::WindowManager wm(600, 600, "Test Window");
    Mirror::RenderManager rm;

    //temp
    float pos[]{
        0.0, 0.0, 0.0
    };

    float verts[] = {
        -0.5, -0.5, 0.0,
        0.5, -0.5, 0.0,
        0.0, 0.5, 0.0
    };

    rm.CreateRendObj(pos, verts, 9);

    while(!glfwWindowShouldClose(wm.getWindow()))
    {
        rm.Render();
        glfwSwapBuffers(wm.getWindow());
        glfwPollEvents();
    }
}

#include "../Mirror/MirrorCore.hpp"
#include <iostream>

namespace Mirror
{
    class WindowManager
    {
        public:
        WindowManager(int w, int h, const char* name);
        ~WindowManager();
        GLFWwindow* getWindow();

        private:
        GLFWwindow* window;

    };

    void resize(GLFWwindow* window, int width, int height);
}
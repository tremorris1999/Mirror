#include "../MirrorCore.hpp"
#include <mirrorlog/MirrorLog.hpp>

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
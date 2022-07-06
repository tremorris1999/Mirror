#include "mirror_core.h"

namespace mirror
{
    class WindowManager
    {
        public:
        WindowManager(int w, int h, const char* name);
        ~WindowManager();
        GLFWwindow* getWindow();

        private:
        GLFWwindow* m_window;

    };

    void resize(GLFWwindow* window, int width, int height);
}
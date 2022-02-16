#include <GL/glew.h>
#include <GL/GL.h>
#include <GLFW/glfw3.h>

int main(void)
{
	glfwInit();
	glfwCreateWindow(1280, 720, "Test", NULL, NULL);
	return 0;
}
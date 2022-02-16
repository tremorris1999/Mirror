#include "MirrorCore.hpp"
#include "Management/WindowManager.hpp"


int main(void)
{
	Mirror::WindowManager* wm = new Mirror::WindowManager(1280, 720, "Test Window");
	return 0;
}
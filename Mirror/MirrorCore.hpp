#pragma once
#include<GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <mirrorlog/MirrorLog.hpp>

#define DLOG MirrorLog::LogDebug
#define ELOG MirrorLog::LogError
#define ILOG MirrorLog::LogInfo
#define WLOG MirrorLog::LogWarning
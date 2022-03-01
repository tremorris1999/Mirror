cmake_minimum_required ( VERSION 3.8 )

include_directories( BEFORE ${CMAKE_CURRENT_LIST_DIR}/include )
include_directories( ${CMAKE_CURRENT_LIST_DIR}/Mirror )

project ( Mirror )

include( FetchContent )

## glfw
FetchContent_Declare ( glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
)

## glew
FetchContent_Declare ( glew
    GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
)

## mirrorlog
FetchContent_Declare ( mirrorlog 
    GIT_REPOSITORY https://github.com/tremorris1999/MirrorLog.git
)

FetchContent_Declare ( tinyobjloader
    GIT_REPOSITORY https://github.com/tinyobjloader/tinyobjloader.git
)

FetchContent_MakeAvailable( 
    glew
    glfw
    mirrorlog
    tinyobjloader
)

add_executable ( Mirror 
"Mirror/test.cpp"
"Mirror/Management/WindowManager.cpp"
"Mirror/Management/RenderManager.cpp"
"Mirror/Shaders/Shader.cpp"
"Mirror/Renderable/StaticObject.cpp"
"Mirror/Management/stb_implementation.cpp"
"Mirror/Renderable/Mesh.cpp"
"Mirror/Renderable/Model.cpp"
)


find_package( OpenGL REQUIRED )

target_link_libraries ( Mirror
		${OPENGL_LIBRARIES}
		libglew_static
		glfw
        	mirrorlog
)
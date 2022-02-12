set(CMAKE_BUILD_TYPE Debug)
cmake_minimum_required(VERSION 3.10)
include_directories(${CMAKE_SOURCE_DIR}/include)

project(Mirror)

add_executable( main 
    Mirror/test.cpp
    Mirror/Management/WindowManager.cpp
    Mirror/Management/RenderManager.cpp
    Mirror/Shaders/Shader.cpp
    Mirror/Renderable/StaticObject.cpp
    Mirror/IO/ImageLoader.cpp
    Mirror/Renderable/Mesh.cpp
    Mirror/Renderable/Model.cpp
    )

find_package(OpenGL REQUIRED)

target_link_libraries(main
${CMAKE_SOURCE_DIR}/lib/libglew32.a
${CMAKE_SOURCE_DIR}/lib/libglfw3.a
${OPENGL_LIBRARIES}
${CMAKE_SOURCE_DIR}/lib/libassimp.a
${CMAKE_SOURCE_DIR}/lib/libzlib.a
)
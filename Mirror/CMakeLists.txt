set(CMAKE_BUILD_TYPE Debug)
cmake_minimum_required(VERSION 3.10)
include_directories(${CMAKE_SOURCE_DIR}/include)

project(Mirror)

add_executable( main 
    Mirror/test.cpp
    Mirror/Management/WindowManager.cpp
    Mirror/Management/RenderManager.cpp
    Mirror/Util/IO.cpp
    Mirror/Renderable/StaticObject.cpp
    )

find_package(OpenGL REQUIRED)

target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/libglew32.a)
target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/libglfw3.a)
target_link_libraries(main ${OPENGL_LIBRARIES})
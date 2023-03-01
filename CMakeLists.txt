cmake_minimum_required( VERSION 3.1 )

project(AGL)

find_package( OpenGL REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory( glfw )

set(AGL_src
        main.cpp
        glad.c
        include/Shader/Shader.cpp
        include/stb_image.h
        Interface/IObject.h
        Objects/3D/Cube.h
        Scene/MainScene.h
        Objects/3D/Cube.cpp
        Scene/MainScene.cpp)

add_executable( AGLex WIN32 ${AGL_src} )
target_link_libraries( AGLex ${OPENGL_LIBRARIES} glfw )
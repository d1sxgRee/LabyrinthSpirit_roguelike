cmake_minimum_required(VERSION 3.0)

project(LabitinthSpirit)

set(OpenGL_GL_PREFERENCE GLVND)
# There's usualy no modern OpenGL on non-x86-64 machines
IF(NOT CMAKE_SYSTEM_PROCESSOR STREQUAL "ia64")
  set(GRAPHICS GRAPHICS_API_OPENGL_21)
ENDIF(NOT CMAKE_SYSTEM_PROCESSOR STREQUAL "ia64")
add_subdirectory(raylib)


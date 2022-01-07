cmake_minimum_required(VERSION 3.0)

project(LabyrinthSpirit)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(deps REQUIRED IMPORTED_TARGET guile-3.0)

add_executable(${PROJECT_NAME}
  character.c
  engine.c
  interface.c
  level.c
  position.c
  main.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_SOURCE_DIR}/deps/raygui/src/
  ${CMAKE_SOURCE_DIR}/deps/raygui/styles/lavanda
  )

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)

target_link_libraries(${PROJECT_NAME}
  raylib
  PkgConfig::deps
  )

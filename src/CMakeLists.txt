cmake_minimum_required(VERSION 3.0)

project(LabyrinthSpirit)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME}
  engine.c
  interface.c
  main.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_SOURCE_DIR}/deps/raygui/src/
  ${CMAKE_SOURCE_DIR}/deps/raygui/styles/lavanda
  )

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)

target_link_libraries(${PROJECT_NAME}
  raylib
  )

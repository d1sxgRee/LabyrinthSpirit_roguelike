cmake_minimum_required(VERSION 3.0)

project(LabitinthSpirit)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME}
  interface.c
  main.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_SOURCE_DIR}/deps/raygui/src/
  )

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)

target_link_libraries(${PROJECT_NAME}
  raylib
  )

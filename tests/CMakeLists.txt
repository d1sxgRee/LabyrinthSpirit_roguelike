cmake_minimum_required(VERSION 3.0)

project(PointGame)

set(CMAKE_C_STANDARD 11)

include_directories("${CMAKE_SOURCE_DIR}/src")

add_test(NAME dummy COMMAND ls)

cmake_minimum_required(VERSION 3.10)

project(Pong)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SOURCE_FILES main.cpp player.cpp ball.cpp)

add_executable(Pong ${SOURCE_FILES})

add_subdirectory(/usr/local/lib/raylib /usr/local/lib/raylib/src)
target_link_libraries(Pong raylib)

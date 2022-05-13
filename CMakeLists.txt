cmake_minimum_required(VERSION 3.10)

project(astar)

include_directories(include)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/node.cpp
    src/maze.cpp
    src/astar.cpp
)
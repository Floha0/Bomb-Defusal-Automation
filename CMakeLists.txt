cmake_minimum_required(VERSION 3.29)
project(BombManual)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(BombManual
        src/main.cpp
        src/basicWire.cpp
        src/maze.cpp
        src/button.cpp
        src/keypad.cpp
        src/simonSays.cpp
        src/whosFirst.cpp)

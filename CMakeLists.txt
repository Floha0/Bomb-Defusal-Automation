cmake_minimum_required(VERSION 3.29)
project(BombManual)

set(CMAKE_CXX_STANDARD 20)

add_executable(BombManual main.cpp
        basicWire.cpp
        maze.cpp
        basicWire.h
        button.h
        button.cpp
        keypad.cpp
        keypad.h
        simonSays.cpp
        simonSays.h
        whosFirst.h
        whosFirst.cpp)

cmake_minimum_required(VERSION 3.30)
project(Graphs)

set(CMAKE_CXX_STANDARD 20)

add_executable(Graphs main.cpp
        cmake-build-debug/h.cpp
        cmake-build-debug/h.h
        Course_Schedule.cpp
        Course_Schedule.h
        Course_Schedule_II.cpp
        Course_Schedule_II.h
)

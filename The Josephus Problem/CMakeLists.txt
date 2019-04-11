cmake_minimum_required(VERSION 3.13)
project(The_Josephus_Problem)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(The_Josephus_Problem
        JosephusProblem.cpp
        JosephusProblem.h
        main.cpp
        names.txt)

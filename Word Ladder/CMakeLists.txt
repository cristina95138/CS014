cmake_minimum_required(VERSION 3.13)
project(Word_Ladder)

set(CMAKE_CXX_STANDARD 14)

add_executable(Word_Ladder main.cpp WordLadder.cpp WordLadder.h dictionary.txt)
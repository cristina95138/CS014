cmake_minimum_required(VERSION 3.13)
project(Playlist_Linked_List)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Playlist_Linked_List
        main.cpp
        Playlist.cpp
        Playlist.h)

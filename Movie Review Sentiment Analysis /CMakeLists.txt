cmake_minimum_required(VERSION 3.13)
project(Movie_Review_Sentiment_Analysis)

set(CMAKE_CXX_STANDARD 14)

add_executable(Movie_Review_Sentiment_Analysis main.cpp WordEntry.cpp WordEntry.h HashTable.cpp HashTable.h)
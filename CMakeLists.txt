cmake_minimum_required(VERSION 3.28)
project(DMProject2025)

set(CMAKE_CXX_STANDARD 20)

add_executable(AdjMatrix src/GraphAdjMexec.cpp
        src/GraphStructures/GraphAdjM/GraphAdjM.h
        src/GraphStructures/GraphAdjM/GraphAdjM.cpp)

add_executable(AdjList src/GraphAdjLexec.cpp
        src/GraphStructures/GraphAdjL/GraphAdjL.h
        src/GraphStructures/GraphAdjL/GraphAdjL.cpp)
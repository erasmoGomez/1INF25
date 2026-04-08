cmake_minimum_required(VERSION 3.31)
project(MemoriaIncrementos)

set(CMAKE_CXX_STANDARD 20)

add_executable(MemoriaIncrementos main.cpp
        src/MemoriaIncrementos.cpp
        src/MemoriaIncrementos.hpp
        src/Utils.hpp)

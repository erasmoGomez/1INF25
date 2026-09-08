cmake_minimum_required(VERSION 3.31)
project(MemoriaExacta)

set(CMAKE_CXX_STANDARD 20)

add_executable(MemoriaExacta main.cpp
        src/MemoriaExacta.cpp
        src/MemoriaExacta.hpp
        src/Utils.hpp)

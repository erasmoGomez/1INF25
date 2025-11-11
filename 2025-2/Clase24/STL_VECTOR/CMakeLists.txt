cmake_minimum_required(VERSION 3.31)
project(STL_VECTOR)

set(CMAKE_CXX_STANDARD 20)

add_executable(STL_VECTOR main.cpp
        src/Persona.cpp
        src/Persona.hpp
        src/Utils.hpp)

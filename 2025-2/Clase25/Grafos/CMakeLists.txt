cmake_minimum_required(VERSION 3.31)
project(Grafos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Grafos main.cpp
        src/Persona.cpp
        src/Persona.hpp
        src/RedSocial.cpp
        src/RedSocial.hpp)

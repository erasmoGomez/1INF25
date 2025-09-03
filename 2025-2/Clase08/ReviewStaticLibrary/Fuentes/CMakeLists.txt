cmake_minimum_required(VERSION 3.31)
project(Fuentes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fuentes main.cpp
        src/SobrecargasPersona.cpp
        src/SobrecargasPersona.hpp
        src/Utils.hpp
        src/Persona.hpp)

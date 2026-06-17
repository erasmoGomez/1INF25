cmake_minimum_required(VERSION 3.31)
project(Plantillas)

set(CMAKE_CXX_STANDARD 20)

add_executable(Plantillas main.cpp
        src/Persona.cpp
        src/Persona.hpp
        src/Utils.hpp
        src/Plantilla.hpp)

cmake_minimum_required(VERSION 4.0)
project(JuegoUndertale)

set(CMAKE_CXX_STANDARD 20)

add_executable(JuegoUndertale main.cpp
        Fuentes/Heroe.cpp
        Fuentes/Heroe.hpp
        Fuentes/Utils.hpp)

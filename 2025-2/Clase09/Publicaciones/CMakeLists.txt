cmake_minimum_required(VERSION 3.31)
project(Publicaciones)

set(CMAKE_CXX_STANDARD 20)

add_executable(Publicaciones main.cpp
        src/Utils.hpp
        src/FuncionesAuxiliares.cpp
        src/FuncionesAuxiliares.hpp
        src/Publicaciones.cpp
        src/Publicaciones.hpp)

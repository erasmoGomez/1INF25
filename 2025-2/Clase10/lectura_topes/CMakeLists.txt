cmake_minimum_required(VERSION 3.31)
project(lectura_topes)

set(CMAKE_CXX_STANDARD 20)

add_executable(lectura_topes main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)

cmake_minimum_required(VERSION 3.30)
project(Clase01)

set(CMAKE_CXX_STANDARD 20)

add_executable(Clase01 main.cpp
        Librerias/Utils.hpp
        Librerias/Funciones.cpp
        Librerias/Funciones.hpp)

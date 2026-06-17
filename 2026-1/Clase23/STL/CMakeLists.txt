cmake_minimum_required(VERSION 4.0)
project(STL)

set(CMAKE_CXX_STANDARD 20)

add_executable(STL main.cpp
        Librerias/Util/Utils.hpp
        Librerias/Modelo/Alumno.hpp
        Librerias/Modelo/Alumno.cpp
        Librerias/Controlador/Demo.cpp
        Librerias/Controlador/Demo.hpp)

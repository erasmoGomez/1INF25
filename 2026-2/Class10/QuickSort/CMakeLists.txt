cmake_minimum_required(VERSION 4.0)
project(QuickSort)

set(CMAKE_CXX_STANDARD 20)

add_executable(QuickSort main.cpp
        Librerias/Utils.hpp
        Librerias/funciones.cpp
        Librerias/funciones.hpp)

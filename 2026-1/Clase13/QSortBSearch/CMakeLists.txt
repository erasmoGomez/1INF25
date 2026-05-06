cmake_minimum_required(VERSION 4.0)
project(QSort)

set(CMAKE_CXX_STANDARD 20)

add_executable(QSort main.cpp
        Librerias/Utils.hpp
        Librerias/Structs.hpp
        Librerias/AuxiliaryFunctions.cpp
        Librerias/AuxiliaryFunctions.hpp)

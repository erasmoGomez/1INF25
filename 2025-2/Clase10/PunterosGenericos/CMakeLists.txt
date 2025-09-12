cmake_minimum_required(VERSION 3.31)
project(PunterosGenericos)

set(CMAKE_CXX_STANDARD 20)

add_executable(PunterosGenericos main.cpp
        src/Alumnos.cpp
        src/Alumnos.hpp
        src/Utils.hpp)

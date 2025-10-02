cmake_minimum_required(VERSION 3.31)
project(Herencia)

set(CMAKE_CXX_STANDARD 20)

add_executable(Herencia main.cpp
        src/Circulo.cpp
        src/Circulo.hpp
        src/Cilindro.cpp
        src/Cilindro.hpp)

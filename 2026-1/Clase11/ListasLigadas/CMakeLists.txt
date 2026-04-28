cmake_minimum_required(VERSION 3.31)
project(ListasLigadas)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListasLigadas main.cpp
        src/ListaEmpleados.cpp
        src/ListaGenerica.cpp)

cmake_minimum_required(VERSION 3.31)
project(ListasLigadas)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListasLigadas main.cpp
        src/Controller/ListaEmpleados.cpp
        src/Model/ListaGenerica.cpp
        src/Utils/Helpers.cpp
        src/Utils/Helpers.hpp)

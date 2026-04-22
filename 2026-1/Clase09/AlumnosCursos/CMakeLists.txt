cmake_minimum_required(VERSION 3.31)
project(PunterosVoidAlumnosCursos)

set(CMAKE_CXX_STANDARD 20)

add_executable(PunterosVoidAlumnosCursos main.cpp
        Bibliotecas/funciones_genericas.cpp
        Bibliotecas/funciones_genericas.hpp
        Bibliotecas/Utils.hpp)

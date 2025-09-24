cmake_minimum_required(VERSION 3.31)
project(PunterosVoidAlumnosCursos)

set(CMAKE_CXX_STANDARD 20)

add_executable(PunterosVoidAlumnosCursos main.cpp
        srx/funciones_genericas.cpp
        srx/funciones_genericas.hpp
        srx/Utils.hpp)

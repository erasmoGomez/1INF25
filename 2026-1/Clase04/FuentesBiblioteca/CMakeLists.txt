cmake_minimum_required(VERSION 4.0)
project(FuentesBiblioteca)

set(CMAKE_CXX_STANDARD 20)

add_executable(FuentesBiblioteca main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Review.hpp
        Bibliotecas/Reviews.hpp
        Bibliotecas/AuxiliaryFunctions.cpp
        Bibliotecas/AuxiliaryFunctions.hpp
        Bibliotecas/Sobrecargas.cpp
        Bibliotecas/Sobrecargas.hpp)

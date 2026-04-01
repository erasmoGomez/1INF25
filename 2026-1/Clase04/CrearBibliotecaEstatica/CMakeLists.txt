cmake_minimum_required(VERSION 4.1)

project(CrearBibliotecaEstatica)

set(CMAKE_CXX_STANDARD 20)

add_library(MiLibreriaEstatica STATIC MisBibliotecas/Sobrecargas.cpp)

add_executable(CrearBibliotecaEstatica main.cpp
        MisBibliotecas/Sobrecargas.hpp)

target_link_libraries(CrearBibliotecaEstatica MiLibreriaEstatica)

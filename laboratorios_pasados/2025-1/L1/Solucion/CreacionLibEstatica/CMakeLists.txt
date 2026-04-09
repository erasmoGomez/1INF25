cmake_minimum_required(VERSION 4.1)
project(CreacionLibEstatica)

set(CMAKE_CXX_STANDARD 20)

add_library(Sobrecargas STATIC Bibliotecas/Sobrecargas.cpp)

add_executable(CreacionLibEstatica main.cpp)

target_link_libraries(CreacionLibEstatica Sobrecargas)

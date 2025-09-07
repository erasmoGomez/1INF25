cmake_minimum_required(VERSION 3.31)

project(CreacionLibreria)

set(CMAKE_CXX_STANDARD 20)

add_library(Sobrecargas STATIC src/Sobrecargas.cpp)

add_executable(CreacionLibreria main.cpp)

target_link_libraries(CreacionLibreria Sobrecargas)
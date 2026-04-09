cmake_minimum_required(VERSION 4.1)
project(LibreriaAperturaArchivos)

set(CMAKE_CXX_STANDARD 20)

add_library(AperturaArchivos STATIC Librerias/AperturaArchivos.cpp)

add_executable(LibreriaAperturaArchivos main.cpp
        Librerias/AperturaArchivos.cpp
        Librerias/AperturaArchivos.hpp
        Librerias/Utils.hpp)

target_link_libraries(LibreriaAperturaArchivos AperturaArchivos)
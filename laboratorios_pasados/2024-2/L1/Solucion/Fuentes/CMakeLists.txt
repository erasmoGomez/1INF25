cmake_minimum_required(VERSION 3.31)
project(Fuentes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fuentes main.cpp
        src/Sobrecargas.cpp
        src/Sobrecargas.hpp
        src/Utils.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(Fuentes PRIVATE AperturaDeArchivos)
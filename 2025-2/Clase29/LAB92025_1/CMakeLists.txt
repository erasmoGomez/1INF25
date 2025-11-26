cmake_minimum_required(VERSION 3.31)
project(LAB92025_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB92025_1 main.cpp
        src/Utils.hpp
        src/Infraccion.cpp
        src/Infraccion.hpp
        src/Vehiculo.cpp
        src/Vehiculo.hpp
        src/Multa.cpp
        src/Multa.hpp
        src/Empresa.cpp
        src/Empresa.hpp
        src/MinisterioTransporte.cpp
        src/MinisterioTransporte.hpp)

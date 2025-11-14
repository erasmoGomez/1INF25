cmake_minimum_required(VERSION 4.0)
project(Solucion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Solucion main.cpp
        GestorStreamers.cpp
        GestorStreamers.h
        StreamerGratuito.cpp
        StreamerGratuito.h
        StreamerPago.cpp
        StreamerPago.h
        Streamer.cpp
        Streamer.h
        Utils.cpp
        Utils.h
        MetricaBasica.cpp
        MetricaBasica.h
        MetricaEngagement.cpp
        MetricaEngagement.h
        MetricaCalidad.cpp
        MetricaCalidad.h
        Metrica.cpp
        Metrica.h)

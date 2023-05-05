/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on May 2, 2023, 7:43 AM
 */


#include "memoria_exacta.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    char **arr_uuid_artista;
    char **arr_nombre_artista, **arr_nombre_canciones, ***arr_generos_canciones;
    int **arr_duracion_canciones;
    double **arr_danceability_canciones;
    cargar_artistas(arr_uuid_artista, arr_nombre_artista);
    //probar_lectura_artistas(arr_uuid_artista, arr_nombre_artista);
    cargar_canciones(arr_uuid_artista, arr_nombre_canciones, 
                     arr_duracion_canciones, arr_danceability_canciones,
                     arr_generos_canciones);
    //cout<<arr_duracion_canciones[0]<<endl;
    return 0;
}


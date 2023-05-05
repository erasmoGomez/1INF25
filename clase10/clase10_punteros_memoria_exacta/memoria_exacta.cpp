/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "memoria_exacta.hpp"

char * memoria_exacta_cadena(char *buffer_uuid_artista){
    char *ptr_cadena;
    //reservar memoria
    ptr_cadena = new char[strlen(buffer_uuid_artista)+1];
    //almacenamiento de datos
    strcpy(ptr_cadena,buffer_uuid_artista);
    return ptr_cadena;
}

void cargar_artistas(char **& arr_uuid_artista, char **& arr_nombre_artista){
    ifstream arch_input("artists.csv",ios::in);
    char buffer_uuid_artista[50], buffer_nombre_artista[100];
    char *aux_arr_uuid_artista[900], *aux_arr_nombre_artista[900];
    int cant_artista = 0;
    while(true){
        //Si el primer elemento es cadena
        arch_input.getline(buffer_uuid_artista,50,',');
        //si el primer elemento no es cadena
        //arch_input>>buffer_entero;
        //arch_input.get();
        if(arch_input.eof()) break;
        arch_input.getline(buffer_nombre_artista,50,'\n');
        
        aux_arr_uuid_artista[cant_artista] = memoria_exacta_cadena(buffer_uuid_artista);
        aux_arr_nombre_artista[cant_artista] = memoria_exacta_cadena(buffer_nombre_artista);
        cant_artista++;       
    }
    //Asignar topes
    aux_arr_uuid_artista[cant_artista] = nullptr;
    aux_arr_nombre_artista[cant_artista] = nullptr;
    //aux_dni_artista[cant_artista] = 0;
    //aux_saldo_artista[cant_artista] = -99999999
    
    //reserva de memoria exacta para los arreglos
    arr_uuid_artista = new char *[cant_artista+1];
    arr_nombre_artista = new char *[cant_artista+1]; 
    // Grave error de concepto :v
//    arr_uuid_artista = aux_arr_uuid_artista;
//    arr_nombre_artista = aux_arr_nombre_artista;
    for(int i=0;i<cant_artista+1;i++){
        arr_uuid_artista[i] = aux_arr_uuid_artista[i];
        arr_nombre_artista[i] = aux_arr_nombre_artista[i];
        //strcpy(arr_nombre_artista[i], (const char*)aux_arr_nombre_artista[i]); // no funciona
        //arr_dni_artista[i] = aux_arr_dni_artista[i];
    }
}

void probar_lectura_artistas(char ** arr_uuid_artista, char ** arr_nombre_artista){
    cout<<setw(20)<<"UUID"<<setw(40)<<"Artista"<<endl;
    for( int i = 0; arr_uuid_artista[i]!= nullptr; i++){
        cout<<setw(20)<<arr_uuid_artista[i]<<setw(40)<<arr_nombre_artista[i]<<endl;
    }
}

int repetidoQ(char * uuid, char**arr_uuid,int n){
    for(int i=0;i<n;i++)
        if(!strcmp(uuid,arr_uuid[i]))
            return i;
    return -1;
}
//
//void cargar_canciones(char ** arr_uuid_artista, char **& arr_nombre_canciones, 
//                      int **& arr_duracion_canciones, double **& arr_danceability_canciones,
//                      char ***& arr_generos_canciones){
//    int cant_artistas = 0;
//    char buffer_uuid_artista[50], buffer_nombre_artista[50], coma;
//    char *aux_arr_uuid_artista[900];
//    int aux_arr_duracion_canciones[900];
//    double aux_arr_danceability_canciones[900];
//    
//    ifstream arch_input("songs.csv",ios::in);
//    int repetido = 0;
//    while(true){
//        arch_input.getline(buffer_uuid_artista, 60, ',');
//        if(arch_input.eof()) break;
//        repetido = repetidoQ(buffer_uuid_artista, aux_arr_uuid_artista, cant_artistas);
//        
//        arch_input.getline(buffer_nombre_artista, 60, ',');
//        arch_input>>aux_arr_duracion_canciones[cant_artistas]>>coma;
//        arch_input>>aux_arr_danceability_canciones[cant_artistas]>>coma;
//        
//        if(repetido == -1){
//            
//        }
//    }
//}

void cargar_canciones(char **arr_uuid_artista, char **&arr_nombre_canciones, 
                      int **&arr_duracion_canciones, double **&arr_danceability_canciones, 
                      char ***&arr_generos_canciones){
    ifstream arch_input("songs.csv",ios::in);
    char *aux_uuid_artistas[850];
    int cant_artistas;
    int numero_artista=0;
    int numero_cancion=0;
    int aux_duracion_cancion[850][2000] = {0,0};
    double aux_danceability_cancion[][2000] = {};
    char *aux_arr_nombre_canciones[2000];
    char *aux_arr_generos_canciones_artistas[2000];
    char buffer_uuid_artista[50];
    char buffer_nombre_cancion[50];
    char buffer_genero_cancion[50];
    char coma;
    int numero_canciones_totales = 0;
    int indice_artista = 0;
    int arr_indices_canciones_artista[850] = {};
    int arr_indices_generos_artista[850];
    int duracion;
    double extra, danceability;
    while(true){
        //lectura uuid
        arch_input.getline(buffer_uuid_artista,50,',');
        if(arch_input.eof())break;
        //lectura nombre cancion
        arch_input.getline(buffer_nombre_cancion,50,',');
        //lectura duracion cancion+
        arch_input>>duracion>>coma;
        //lectura generos cancion
        //intentar leer danceability
        while(true){
            arch_input>>danceability;
            if(arch_input.fail()){
                if(arch_input.eof())break;
                arch_input.clear();
                arch_input.getline(buffer_genero_cancion, 30,',');
                if(strcmp(buffer_genero_cancion,"")){
                    aux_arr_generos_canciones_artistas[arr_indices_generos_artista[numero_cancion]] = memoria_exacta_cadena(buffer_genero_cancion);
                    arr_indices_generos_artista[numero_cancion]++;
                }
            }
            else break;
        }
        indice_artista = repetidoQ(buffer_uuid_artista, aux_uuid_artistas, cant_artistas);
        //cout<<indice_artista<<endl;
        if(indice_artista == -1){
            //Agregar a la lista
            aux_arr_nombre_canciones[arr_indices_canciones_artista[cant_artistas]] = memoria_exacta_cadena(buffer_nombre_cancion);
            arr_indices_canciones_artista[cant_artistas]++;
            numero_artista++;
            numero_cancion++;
        }
        else {
            //Actualizar punteros
            aux_arr_nombre_canciones[indice_artista] = memoria_exacta_cadena(buffer_nombre_cancion);
            aux_duracion_cancion[indice_artista][arr_indices_canciones_artista[indice_artista]] = duracion;
            aux_danceability_cancion[indice_artista][arr_indices_canciones_artista[indice_artista]] = danceability;
            arr_indices_canciones_artista[indice_artista]++;
            numero_cancion++;
        }
        numero_canciones_totales++;
    }
    //Memoria Exacta para los punteros a retornar
    arr_nombre_canciones = new char *[cant_artistas+1];
    arr_duracion_canciones = new int *[cant_artistas+1];
    arr_danceability_canciones = new double *[cant_artistas+1];
    arr_generos_canciones = new char **[cant_artistas+1];
    
    //Pasar estaticos a dinamicos
    for(int i=0;i<cant_artistas+1;i++){
        arr_nombre_canciones[i] = aux_arr_nombre_canciones[i];
        arr_duracion_canciones[i] = aux_duracion_cancion[i];
        arr_danceability_canciones[i]= aux_danceability_cancion[i];
        arr_generos_canciones[i] = aux_arr_generos_canciones_artistas;
    }
    
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funciones.hpp"
void leer_telefonos(ifstream& input, struct Telefono *telefonos){ //Trabajo directamente en el arreglo
    int cantidad_telefonos_leidos = 0;
    while(input>>telefonos[cantidad_telefonos_leidos]){ //Sobrecarga
        cantidad_telefonos_leidos++;
    }
    struct Telefono dummy;
    dummy.numero_telefonico = 0;
    strcpy(dummy.marca, "dummy");
    telefonos[cantidad_telefonos_leidos] = dummy;
}

void imprimir_telefonos(ofstream& output, struct Telefono *telefonos){
    
    int i = 0;
//    while(telefonos[i].numero_telefonico != 0){
//        output<<telefonos[i];
//        i++;
//    }
    while(strcmp(telefonos[i].marca, "dummy")!=0){
        output<<telefonos[i]; //Sobrecarga
        i++;
    }
}

void incrementar_precios(struct Telefono *telefonos){
    // telefono += 25
    int i = 0;
    while(strcmp(telefonos[i].marca, "dummy")!=0){
        telefonos[i]*=INCREMENTO; //Sobrecarga
        i++;
    }
}
//
// Created by Erasmo on 11/09/25.
//

#include "Funciones.hpp"

char *read_str(ifstream &archivo, char separador) {
    char buffer[1024];
    archivo.getline(buffer, 1024, separador);
    char *cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);

    return cadena;
}

bool leer_apodo(ifstream &archivo, char *&apodo) { //Solo lee 1 apodo
    char buffer[20];
    int num = 0;

    // si siguiente es '>', no hay más menciones
    if (archivo.peek() == '>') {
        archivo.get(); // consumir '>'
        return false;
    }

    while (archivo.peek() != ' ' and archivo.peek() != '>') {
        buffer[num++] = archivo.get();
    }

    buffer[num] = '\0'; //Fin de cadena zipperino\n

    apodo = new char[num + 1];
    strcpy(apodo, buffer);

    // consumir espacio
    if (archivo.peek() == ' ')
        archivo.get();

    return true;
}

void cargar_apodos(ifstream &input, char **&apodos) {
    char *buffer[10];
    int num = 0;
    char *apodo;

    while (leer_apodo(input, apodo)) {
        buffer[num] = apodo;
        num++;
    }

    apodos = new char *[num + 1]{};
    for (int i = 0; i < num; i++) {
        apodos[i] = buffer[i];
    }
}

void leer_datos(ifstream &input, char **&apodos) {
    char *texto;
    while (true) {
        char *texto_1 = read_str(input, '<');
        if (input.eof())break;
        cargar_apodos(input, apodos);
        if (input.peek() != '\n') {
            char *texto_2 = read_str(input, '\n');
            int size = strlen(texto_1) + strlen(texto_2) + 1;

            char *textoCompleto = new char[size];
            strcpy(textoCompleto, texto_1);
            strcat(textoCompleto, texto_2);

            delete[] texto_1;
            delete[] texto_2;

            texto = textoCompleto;
        }
        cout << texto << endl;
        for (int i = 0; apodos[i]; i++)
            cout << apodos[i] << endl;
    }
}
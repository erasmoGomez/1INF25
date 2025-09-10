//
// Created by Erasmo on 9/09/25.
//

#include "Publicaciones.hpp"

void leer_usuario(ifstream &input, char **&usuario) {

    char *cuenta = read_str(input, ',');
    if (input.eof())return;
    char *nombre = read_str(input, ',');
    char *correo = read_str(input, ',');
    char *facultad = read_str(input, ',');

    usuario = new char *[4]{};
    usuario[CUENTA] = cuenta;
    usuario[NOMBRE] = nombre;
    usuario[CORREO] = correo;
    usuario[FACULTAD] = facultad;

}

void leer_fecha_edad(ifstream &input, int *&fecha_edad) {
    int anho, mes, dia, edad;
    char c;
    //2020-12-12,22
    input >> anho >> c >> mes >> c >> dia;
    input.get();
    input >> edad;
    input.get();

    int fecha = anho * 10000 + mes * 100 + dia;
    fecha_edad = new int[2]{};
    fecha_edad[FECHA] = fecha;
    fecha_edad[EDAD] = edad;

}

void carga_usuarios(const char *nombre_archivo, char ***&usuarios, int **&fechas_edades) {
    int n_usuarios = 0, capacidad = 0;
    char **usuario;
    int *fecha_edad;

    usuarios = nullptr;
    fechas_edades = nullptr;

    ifstream input;
    open_file_read(input, nombre_archivo);

    while (true) {
        leer_usuario(input, usuario);
        //usuario = leer_usuario(input); // Puede haber un escape de memoria leak
        if (input.eof())break;
        leer_fecha_edad(input, fecha_edad);
        if (n_usuarios == capacidad) {
            capacidad += INCREMENTO;
            incrementar_usuarios(usuarios, n_usuarios, capacidad);
            incrementar_fechas_edades(fechas_edades, n_usuarios, capacidad);
        }

        insertar_ordenado(usuarios, fechas_edades,
                          usuario, fecha_edad, n_usuarios);
        n_usuarios++;
    }
}

void incrementar_usuarios(char ***&usuarios, int num, int capacidad) {
    if (usuarios == nullptr) {
        usuarios = new char **[capacidad + 1]{};
    } else {
        char ***aux = new char **[capacidad + 1]{};
        for (int i = 0; i < num; i++) {
            aux[i] = usuarios[i];
        }
        delete[] usuarios;
        usuarios = aux;
    }
}

void incrementar_fechas_edades(int **&fechasEdades, int num, int capacidad) {
    if (fechasEdades == nullptr) {
        fechasEdades = new int *[capacidad + 1]{};
    } else {
        int **aux = new int *[capacidad + 1]{};
        for (int i = 0; i < num; i++) {
            aux[i] = fechasEdades[i];
        }
        delete[] fechasEdades;
        fechasEdades = aux;
    }
}

void insertar_ordenado(char ***&usuarios, int **&fechasEdades, char **usuario,
                       int *fechaEdad, int num) {
    int i;
    int *aux;
    for (i = num - 1; i >= 0; i--) {
        aux = fechasEdades[i];
        if (aux[FECHA] <= fechaEdad[FECHA]) break;
        usuarios[i + 1] = usuarios[i];
        fechasEdades[i + 1] = fechasEdades[i];
    }

    usuarios[i + 1] = usuario;
    fechasEdades[i + 1] = fechaEdad;
}

void imprimir_fecha(ofstream &output, int fecha) {
    const int anho = fecha / 10000;
    const int mes = (fecha / 100) % 100;
    const int dia = fecha % 100;

    output << (dia / 10) << (dia % 10) << "-"
           << (mes / 10) << (mes % 10) << "-"
           << (anho / 1000) % 10
           << (anho / 100) % 10
           << (anho / 10) % 10
           << anho % 10;
}

void imprimir_usuario(ofstream &output, char **usuario, int *fecha_edad) {
    const char *cuenta = usuario[CUENTA];
    const char *nombre = usuario[NOMBRE];
    const char *correo = usuario[CORREO];
    const char *facultad = usuario[FACULTAD];
    const int fecha = fecha_edad[FECHA];
    const int edad = fecha_edad[EDAD];

    output << setfill('=') << setw(40) << "" << setfill(' ') << endl;
    output << "REPORTE DE USUARIO" << endl;
    output << setfill('=') << setw(40) << "" << setfill(' ') << endl;

    output << left
           << setw(10) << "Cuenta:" << setw(15) << cuenta << endl
           << setw(10) << "Nombre:" << setw(20) << nombre << endl
           << setw(10) << "Correo:" << setw(25) << correo << endl
           << setw(10) << "Facultad:" << setw(15) << facultad << endl
           << setw(10) << "Fecha: ";
    imprimir_fecha(output, fecha);
    output << endl;
    output << setw(10) << "Edad:" << setw(3) << edad
           << endl;
}

void imprimir_reporte(const char *nombreArchivo, char ***usuarios, int **fechasEdades) {
    ofstream output;
    open_file_write(output, nombreArchivo);

    for (int i = 0; usuarios[i]; i++) {
        char **registro_usuario = usuarios[i];
        int *registro_fechasEdad = fechasEdades[i];

        imprimir_usuario(output, registro_usuario, registro_fechasEdad);
    }
}

void leerIdFecha(ifstream &archivo, int *&idFecha) {
    int id;
    archivo >> id;
    archivo.get();

    int anho, mes, dia;
    char c;
    archivo >> anho >> c >> mes >> c >> dia;
    archivo.get();

    int fecha = anho * 10000 + mes * 100 + dia;
    idFecha = new int[2]{};
    idFecha[ID] = id;
    idFecha[FECHA_PUB] = fecha;
}

void leerPublicacion(ifstream &archivo, char **&publicacion, char **&mencionesPub) {
    char *cuenta = read_str(archivo, ',');
    if (archivo.eof())return;

    // si aún hay datos y se puede seguir leyendo
    archivo.get(); // ignorar el [
    cargarMenciones(archivo, mencionesPub);
    archivo.get(); // ignorar el espacio
    char *texto = read_str(archivo, '\n');

    publicacion = new char *[2]{};
    publicacion[CUENTA_PUB] = cuenta;
    publicacion[TEXTO] = texto;

}

bool leerMencion(ifstream &archivo, char *&mencion) {
    char buffer[20];
    int num = 0;

    // si siguiente es ']', no hay más menciones
    if (archivo.peek() == ']') {
        archivo.get(); // consumir ']'
        return false;
    }

    while (archivo.peek() != ' ' && archivo.peek() != ']') {
        buffer[num++] = archivo.get();
    }

    buffer[num] = '\0';

    mencion = new char[num + 1];
    strcpy(mencion, buffer);

    // consumir espacio
    if (archivo.peek() == ' ')
        archivo.get();
    return true;
}

void insertarOrdenado(int **&idsFecha, char ***&publicaciones, char ***&menciones,
                      int *idFecha, char **publicacion, char **mencionesPub,
                      int num) {
    int i;
    int *aux;
    for (i = num - 1; i >= 0; i--) {
        aux = idsFecha[i];
        if (aux[FECHA_PUB] <= idFecha[FECHA_PUB])break;
        publicaciones[i + 1] = publicaciones[i];
        idsFecha[i + 1] = idsFecha[i];
        menciones[i + 1] = menciones[i];
    }

    publicaciones[i + 1] = publicacion;
    idsFecha[i + 1] = idFecha;
    menciones[i + 1] = mencionesPub;
}

void cargar_publicaciones(const char *nombreArchivo, int **&idsFechas,
                          char ***&publicaciones, char ***&menciones) {
    int num = 0, capacidad = 0;

    idsFechas = nullptr;
    publicaciones = nullptr;
    menciones = nullptr;

    int *idFecha; //Registro IDFECHA
    char **publicacion; //Registro Publicacion
    char **mencionesPub; //Registro Menciones

    ifstream archivo(nombreArchivo, ios::in);
    while (true) {
        leerIdFecha(archivo, idFecha); //Lee el registro IDFECHA
        if (archivo.eof())break;
        leerPublicacion(archivo, publicacion, mencionesPub);
        if (num == capacidad) {
            capacidad += 5;
            incrementarIdsFechas(idsFechas, num, capacidad);
            incrementarPublicaciones(publicaciones, num, capacidad);
            incrementarMenciones(menciones, num, capacidad);
        }

        insertarOrdenado(idsFechas, publicaciones, menciones,
                         idFecha, publicacion, mencionesPub, num);
        num++;
    }
}

// Cargar menciones de forma exacta
void cargarMenciones(ifstream &archivo, char **&menciones) {
    char *buffer[10]; // máximo 10 menciones por publicación
    int num = 0;
    char *mencion;
    //Aplicamos memoria exacta propiamente dicha
    while (true) {
        if (!leerMencion(archivo, mencion)) break;
        buffer[num++] = mencion;
    }

    menciones = new char *[num + 1]{};
    for (int i = 0; i < num; i++) {
        menciones[i] = buffer[i];
    }
}

void incrementarIdsFechas(int **&idsFechas, int num, int capacidad) {
    if (idsFechas == nullptr) {
        idsFechas = new int *[capacidad + 1]{};
    } else {
        int **aux = new int *[capacidad + 1]{};
        for (int i = 0; i < num; i++) {
            aux[i] = idsFechas[i];
        }
        delete[] idsFechas;
        idsFechas = aux;
    }
}

void incrementarPublicaciones(char ***&publicaciones, int num, int capacidad) {
    if (publicaciones == nullptr) {
        publicaciones = new char **[capacidad + 1]{};
    } else {
        char ***aux = new char **[capacidad + 1]{};
        for (int i = 0; i < num; i++) {
            aux[i] = publicaciones[i];
        }
        delete[] publicaciones;
        publicaciones = aux;
    }
}

void incrementarMenciones(char ***&menciones, int num, int capacidad) {
    if (menciones == nullptr) {
        menciones = new char **[capacidad + 1]{};
    } else {
        char ***aux = new char **[capacidad + 1]{};
        for (int i = 0; i < num; i++) {
            aux[i] = menciones[i];
        }
        delete[] menciones;
        menciones = aux;
    }
}

void imprimirPubUsuario(ofstream &archivo, char **publicacion, int *idFecha) {
    int fecha = idFecha[FECHA_PUB];
    char *texto = publicacion[TEXTO];

    archivo << "[";
    imprimir_fecha(archivo, fecha);
    archivo << "]" << " " << texto << endl;
}

bool mencionadoEnPublicacion(char *cuentaUsuario, char **mencionesPub) {
    for (int i = 0; mencionesPub[i]; i++) {
        char *cuenta = mencionesPub[i];

        if (strcmp(cuenta, cuentaUsuario) == 0) {
            return true;
        }
    }
    return false;
}

void imprimirMencion(ofstream &archivo, int *idFecha, char **publicacion, char *cuentaUsuario) {
    int fecha = idFecha[1];
    const char *cuentaPublicacion = publicacion[CUENTA_PUB];
    const char *textoPublicacion = publicacion[TEXTO];

    archivo << "En [";
    imprimir_fecha(archivo, fecha);
    archivo << "], " << cuentaPublicacion << " publicó \"" << textoPublicacion << "\"";
    archivo << " y mencionó a " << cuentaUsuario << endl;
}

void imprimir_menciones_usuario(ofstream &archivo, char *cuentaUsuario, int **idsFechas,
                                char ***publicaciones, char ***menciones) {
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    archivo << "PUBLICACIONES DONDE FUE MENCIONADO" << endl;
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    for (int i = 0; publicaciones[i]; i++) {
        char **mencionesPub = menciones[i];
        if (mencionadoEnPublicacion(cuentaUsuario, mencionesPub)) {
            int *idFecha = idsFechas[i];
            char **publicacion = publicaciones[i];
            imprimirMencion(archivo, idFecha, publicacion, cuentaUsuario);
        }
    }
}


void imprimir_publicaciones_usuario(ofstream &archivo, char *cuentaUsuario,
                                    int **idsFechas,
                                    char ***publicaciones) {
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    archivo << "PUBLICACIONES REALIZADAS" << endl;
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    for (int i = 0; idsFechas[i]; i++) {
        char **publicacion = publicaciones[i];
        char *cuenta = publicacion[CUENTA_PUB];

        if (strcmp(cuenta, cuentaUsuario) == 0) {
            int *idFecha = idsFechas[i];
            imprimirPubUsuario(archivo, publicacion, idFecha);
        }
    }
}

void imprimir_reporte(const char *nombreArchivo, char ***usuarios,
                      int **fechasEdades,
                      int **idsFechas, char ***publicaciones,
                      char ***menciones) {
    ofstream archivo(nombreArchivo, ios::out);

    for (int i = 0; usuarios[i]; i++) {
        char **usuario = usuarios[i];
        int *fechasEdad = fechasEdades[i];
        char *cuentaUsuario = usuario[CUENTA];

        imprimir_usuario(archivo, usuario, fechasEdad);
        imprimir_publicaciones_usuario(archivo, cuentaUsuario, idsFechas, publicaciones);
        imprimir_menciones_usuario(archivo, cuentaUsuario, idsFechas, publicaciones, menciones);
        archivo << endl << endl;
    }
}
#include <cstring>
#include <iostream>
#include <fstream>
#include "GestorCanales.h"
#include "Comunes.h"

using namespace std;

GestorCanales::GestorCanales() {
    this->cantidad_categorias = 0;
    this->cantidad_etiquetas = 0;
    this->cantidad_canales = 0;
    this->cargar_categorias();
    this->cargar_etiquetas();
    this->cargar_canales();
}

void GestorCanales::operator!() {
    for (int i = 0; i < this->cantidad_canales; i++) {
        Canal canal = this->vector_canales[i];
        char *codigo = canal.get_categoria();
        char *nombre = this->buscar_nombre_categoria(codigo);
        canal.set_categoria(nombre);
        this->vector_canales[i] = canal;
        liberar_cadena(codigo);
        liberar_cadena(nombre);
    }
}

void GestorCanales::operator*() {
    for (int i = 0; i < this->cantidad_canales; i++) {
        Canal canal = this->vector_canales[i];
        char *etiquetas = canal.get_etiquetas();
        char etiquetas_buffer[30];
        strcpy(etiquetas_buffer, etiquetas);

        char *token = strtok(etiquetas, "-");
        while (token != nullptr) {
            char *etiqueta = this->buscar_nombre_etiqueta(token);
            canal.agregar_etiqueta(etiqueta);
            token = strtok(nullptr, "-");
        }
        this->vector_canales[i] = canal;
        liberar_cadena(etiquetas);
    }
}

void GestorCanales::cargar_categorias() {
    ifstream archivo_de_categorias;
    archivo_de_categorias.open(NOMBRE_CSV_CATEGORIA, ios::in);
    if (not archivo_de_categorias.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << NOMBRE_CSV_CATEGORIA << endl;
        exit(10);
    }

    this->cantidad_categorias = 0;
    Categoria categoria;
    while (archivo_de_categorias >> categoria) {
        this->cantidad_categorias++;
        this->vector_categorias[this->cantidad_categorias - 1] = categoria;
    }
    archivo_de_categorias.close();
}

void GestorCanales::cargar_etiquetas() {
    ifstream archivo_de_etiquetas;
    archivo_de_etiquetas.open(NOMBRE_CSV_ETIQUETA, ios::in);
    if (not archivo_de_etiquetas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << NOMBRE_CSV_ETIQUETA << endl;
        exit(10);
    }

    this->cantidad_etiquetas = 0;
    Etiqueta etiqueta;
    while (archivo_de_etiquetas >> etiqueta) {
        this->cantidad_etiquetas++;
        this->vector_etiquetas[this->cantidad_etiquetas - 1] = etiqueta;
    }
    archivo_de_etiquetas.close();
}

void GestorCanales::cargar_canales() {
    ifstream archivo_de_canales;
    archivo_de_canales.open(NOMBRE_CSV_CANAL, ios::in);
    if (not archivo_de_canales.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << NOMBRE_CSV_ETIQUETA << endl;
        exit(10);
    }

    this->cantidad_canales = 0;
    bool acabo_lectura = false;
    do {
        Canal canal = this->lee_canal(archivo_de_canales);
        if (canal.get_seguidores() == CANAL_NO_LEIDO)
            acabo_lectura = true;
        else {
            this->cantidad_canales++;
            this->vector_canales[this->cantidad_canales - 1] = canal;
        }
    } while (not acabo_lectura);
    archivo_de_canales.close();
}

char *GestorCanales::buscar_nombre_categoria(char *codigo) {
    for (int i = 0; i < cantidad_categorias; i++) {
        char buff_codigo[7];
        vector_categorias[i].get_codigo(buff_codigo);
        if (strcmp(codigo, buff_codigo) == 0) {
            return vector_categorias[i].get_nombre();
        }
    }
    return nullptr;
}

char *GestorCanales::buscar_nombre_etiqueta(char *codigo) {
    for (int i = 0; i < cantidad_etiquetas; i++) {
        char buff_codigo[7];
        vector_etiquetas[i].get_codigo(buff_codigo);
        if (strcmp(codigo, buff_codigo) == 0) {
            return vector_etiquetas[i].get_nombre();
        }
    }
    return nullptr;
}

Canal GestorCanales::lee_canal(istream &archivo_de_canales) {
    char nombre_buffer[30];
    int seguidores_buffer;
    char categoria_buffer[7];
    char etiquetas_buffer[30];

    Canal canal_local;
    archivo_de_canales.getline(nombre_buffer, 30, ',');
    if (archivo_de_canales.eof())
        return canal_local;
    archivo_de_canales >> seguidores_buffer;
    archivo_de_canales.get();;
    archivo_de_canales.getline(categoria_buffer, 7, ',');
    archivo_de_canales.getline(etiquetas_buffer, 30, '\n');

    canal_local.set_nombre(nombre_buffer);
    canal_local.set_categoria(categoria_buffer);
    canal_local.set_etiquetas(etiquetas_buffer);
    canal_local.set_seguidores(seguidores_buffer);
    return canal_local;
}

ostream &GestorCanales::lista_categorias(ostream &out) {
    out << "Lista de categorias:" << endl;
    for (int i = 0; i < this->cantidad_categorias; i++) {
        out << this->vector_categorias[i] << endl;
    }
    return out;
}

ostream &GestorCanales::lista_etiquetas(ostream &out) {
    out << "Lista de etiquetas:" << endl;
    for (int i = 0; i < this->cantidad_etiquetas; i++) {
        out << this->vector_etiquetas[i] << endl;
    }
    return out;
}

ostream &GestorCanales::lista_canales(ostream &out) {
    out << "Lista de canales:" << endl;
    for (int i = 0; i < this->cantidad_canales; i++) {
        out << this->vector_canales[i] << endl;
    }
    return out;
}

//para usar con el quicksort
int ascendente(const void *a, const void *b) {
    Canal canalA = *(Canal *) a;
    Canal canalB = *(Canal *) b;
    if (canalA.get_seguidores() < canalB.get_seguidores()) return -1;
    if (canalA.get_seguidores() > canalB.get_seguidores()) return 1;
    return 0;
}

//para usar con el quicksort
int descendente(const void *a, const void *b) {
    Canal canalA = *(Canal *) a;
    Canal canalB = *(Canal *) b;
    if (canalA.get_seguidores() > canalB.get_seguidores()) return -1;
    if (canalA.get_seguidores() < canalB.get_seguidores()) return 1;
    return 0;
}

ostream &operator<<(ostream &out, const GestorCanales &gestorCanales) {
    int cantidad_canales = gestorCanales.cantidad_canales;
    Canal *vector_canales_copia = new Canal[cantidad_canales];
    for (int i = 0; i < cantidad_canales; i++) {
        vector_canales_copia[i] = gestorCanales.vector_canales[i];
    }
    static bool ascending = true;
    if (ascending) {
        qsort(vector_canales_copia, cantidad_canales, sizeof(Canal), ascendente);
    } else {
        qsort(vector_canales_copia, cantidad_canales, sizeof(Canal), descendente);
    }
    for (int i = 0; i < 10; ++i) {
        out << i << ": " << vector_canales_copia[i] << endl;
    }
    ascending = !ascending;
    return out;
}

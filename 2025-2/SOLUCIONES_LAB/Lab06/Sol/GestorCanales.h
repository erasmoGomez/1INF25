#ifndef CODIGO_DEV_GESTORCANALES_H
#define CODIGO_DEV_GESTORCANALES_H
#include "Canal.h"
#include "Categoria.h"
#include "Etiqueta.h"
#define NOMBRE_CSV_CATEGORIA "categorias.csv"
#define NOMBRE_CSV_ETIQUETA "etiquetas.csv"
#define NOMBRE_CSV_CANAL "canales.csv"
#define MAX_CATEGORIAS 100
#define MAX_ETIQUETAS 100
#define MAX_CANALES 1000

class GestorCanales {
private:
    int cantidad_categorias;
    int cantidad_etiquetas;
    int cantidad_canales;
    Categoria vector_categorias[MAX_CATEGORIAS];
    Etiqueta vector_etiquetas[MAX_ETIQUETAS];
    Canal vector_canales[MAX_CANALES];

public:
    GestorCanales();

    void operator!();

    void operator*();

    ostream &lista_categorias(ostream &out);

    ostream &lista_etiquetas(ostream &out);

    ostream &lista_canales(ostream &out);

private:
    void cargar_categorias();

    void cargar_etiquetas();

    void cargar_canales();

    char *buscar_nombre_categoria(char *categoria);

    char *buscar_nombre_etiqueta(char *etiqueta);

    Canal lee_canal(istream &archivo_de_canales);

    friend ostream &operator<<(ostream &out, const GestorCanales &gestorCanales);
};

#endif //CODIGO_DEV_GESTORCANALES_H

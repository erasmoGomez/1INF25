#ifndef CODIGO_DEV_CANAL_H
#define CODIGO_DEV_CANAL_H
#include <iostream>
#define CANAL_NO_LEIDO -1
#define MAX_VECTOR_ETIQUETAS 5

using namespace std;

class Canal {
private:
    char *nombre;
    char *categoria;
    char *etiquetas;
    int cantidad_etiquetas;
    char *vector_etiquetas[MAX_VECTOR_ETIQUETAS];
    int seguidores;

public:
    Canal();

    ~Canal();

    Canal(const Canal &other);

    Canal &operator=(const Canal &other);

    char *get_nombre() const;

    void set_nombre(const char *cstr);

    char *get_categoria() const;

    void set_categoria(const char *cstr);

    char *get_etiquetas() const;

    void set_etiquetas(const char *cstr);

    int get_seguidores() const;

    void set_seguidores(int x);

    void agregar_etiqueta(char *etiqueta);

    friend ostream &operator<<(ostream &out, Canal &canal);
};


#endif //CODIGO_DEV_CANAL_H

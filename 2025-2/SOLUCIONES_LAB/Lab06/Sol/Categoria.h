#ifndef CODIGO_DEV_CATEGORIA_H
#define CODIGO_DEV_CATEGORIA_H
#include <iostream>

using namespace std;

class Categoria {
private:
    char codigo[7];
    char *nombre;
    char *descripcion;

public:
    Categoria();

    ~Categoria();

    Categoria(const Categoria &other);

    Categoria &operator=(const Categoria &);

    void get_codigo(char *buffer) const;

    void set_codigo(const char *cstr);

    char *get_nombre() const;

    void set_nombre(const char *cstr);

    char *get_descripcion() const;

    void set_descripcion(const char *cstr);

    friend ostream &operator<<(ostream &out, Categoria &categoria);

    friend bool operator>>(istream &in, Categoria &categoria);
};


#endif //CODIGO_DEV_CATEGORIA_H

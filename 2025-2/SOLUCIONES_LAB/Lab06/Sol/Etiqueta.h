#ifndef CODIGO_DEV_ETIQUETA_H
#define CODIGO_DEV_ETIQUETA_H
#include <iostream>

using namespace std;

class Etiqueta {
private:
    char codigo[7];
    char *nombre;

public:
    Etiqueta();

    Etiqueta(const char *codigo, const char *nombre);

    ~Etiqueta();

    Etiqueta(const Etiqueta &etiqueta);

    Etiqueta &operator=(const Etiqueta &etiqueta);

    void get_codigo(char *buffer);

    void set_codigo(const char *cstr);

    char *get_nombre() const;

    void set_nombre(const char *cstr);

    friend bool operator>>(istream &archivo_de_etiquetas, Etiqueta &etiqueta);

    friend ostream &operator<<(ostream &out, Etiqueta &etiqueta);
};


#endif //CODIGO_DEV_ETIQUETA_H

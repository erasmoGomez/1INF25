//
// Created by erasmo on 5/6/26.
//

#include "BibliotecaInfracciones.hpp"

void *buscalistainfraccion(void *lista, void *dato) {
    int *licencia, *lic;
    void **reg = (void **) dato;
    void **llista = (void **) lista;
    void **aux = (void **) llista[INICIO];
    void **cond;
    lic = (int *) reg[LICENCIA];
    while (aux) {
        cond = (void **) aux[DATO];
        licencia = (int *) cond[LICENCIA];
        if (*licencia == *lic) break;
        aux = (void **) aux[SIGUIENTE];
    }
    return cond[LISTA];
}

/*
26522329,U5W-825,22/11/2019,101
47844324,X7J-719,14/09/2019,101
81485316,J5T-691,24/12/2020,128
 */
void *leeinfracciones(ifstream &arch) {
    int *pcodigo, *ptipo, *fecha, dd, mm, aa;
    char cad[10], c, *placa;
    void **aux;

    pcodigo = new int;
    arch >> *pcodigo;
    if (arch.eof())return NULL;
    arch.get();
    arch.getline(cad, 10, ',');
    placa = new char[strlen(cad) + 1];
    strcpy(placa, cad);
    ptipo = new int;
    arch >> dd >> c >> mm >> c >> aa >> c >> *ptipo;
    fecha = new int;
    *fecha = aa * 10000 + mm * 100 + dd;

    aux = new void *[4];
    aux[0] = pcodigo;
    aux[1] = placa;
    aux[2] = fecha;
    aux[3] = ptipo;

    return aux;
}

int cmpinfracciones(void *a, void *b) {
    int *ca, *cb;
    void **pa = (void **) a;
    void **pb = (void **) b;
    ca = (int *) pa[2];
    cb = (int *) pb[2];
    return *ca - *cb;
}


int cmpplacas(void *a, void *b) {
    char *ca, *cb;
    void **pa = (void **) a;
    void **pb = (void **) b;
    ca = (char *) pa[0];
    cb = (char *) pb[0];
    return strcmp(ca, cb);
}


void imprimeinfracciones(ofstream &arch, void *dato) {
    void **aux = (void **) dato;
    int *pfecha, *ptipo;
    char *placa;

    placa = (char *) aux[1];
    pfecha = (int *) aux[2];
    ptipo = (int *) aux[3];

    arch << setw(10) << *pfecha << setw(10) << placa << setw(10) << *ptipo << endl;
}

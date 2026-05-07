//
// Created by erasmo on 5/6/26.
//

#include "BibliotecaConductores.hpp"

/*
12270502,CUEVA FUENTES CINTHIA DELIA
12443643,LEE SERRANO ROSARIO
 */

void *leeconductores(ifstream &arch) {
    int *pcodigo;
    char cad[100], c, *nombre;
    void **aux;

    pcodigo = new int;
    arch >> *pcodigo;
    if (arch.eof())return nullptr;
    arch.get();
    arch.getline(cad, 100, '\n');
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
    cout<<nombre<<endl;
    aux = new void *[4];
    aux[LICENCIA] = pcodigo;
    aux[NOMBRE] = nombre;
    aux[PLACAS] = nullptr;
    generaLista(aux[LISTA]);

    return aux;
}

int cmpconductores(void *a, void *b) {
    int *na, *nb;
    void **pa = (void **) a;
    void **pb = (void **) b;
    na = (int *) pa[LICENCIA];
    nb = (int *) pb[LICENCIA];
    return (*na - *nb);
}

void imprimeconductores(ofstream &arch, void *dato) {
    void **aux = (void **) dato;
    int *pcodigo;
    char *nombre;

    pcodigo = (int *) aux[0];
    nombre = (char *) aux[1];
    arch << setw(10) << left << *pcodigo << left << setw(50) << nombre << endl;
    if (aux[2] != nullptr) {
        void **lplacas = (void **) aux[2];
        for (int i = 0; lplacas[i] != nullptr; i++) {
            char *placa = (char *) lplacas[i];
            arch << placa << " ";
        }
        arch << endl;
    }
    if (aux[3] != nullptr) {
        imprimelistaint(aux[3], imprimeinfracciones, arch);
        arch << endl << endl << endl;
    }
}


/*
12270502,P7T-999
12270502,O1C-880
 */
void cargaUnidades(void *&lista, const char *nombre) {
    int *licencia;
    char *placa, cad[10];
    void **reg, **ptr;

    ifstream arch(nombre, ios::in);
    if (!arch) {
        cout << "No se puede abrir el archivo " << nombre;
        exit(1);
    }
    while (1) {
        licencia = new int;
        arch >> *licencia;
        if (arch.eof()) break;
        arch.get();
        arch.getline(cad, 10);
        placa = new char[strlen(cad) + 1];
        strcpy(placa, cad);
        reg = (void **) buscaconductor(lista, *licencia);
        cargaplaca(reg[PLACAS], placa);
    }
    void **llista = (void **) lista;
    ptr = (void **) llista[INICIO];
    while (ptr) {
        void **reg = (void **) ptr[0];
        ordenacorta(reg[PLACAS]);
        ptr = (void **) ptr[SIGUIENTE];
    }
}

void ordenacorta(void *&placas) {
    int n;
    void **llista;
    void **lista = (void **) placas;
    for (n = 0; lista[n] != nullptr; n++);
    llista = new void *[n + 1];
    for (int i = 0; i <= n; i++)
        llista[i] = lista[i];
    delete lista;
    qsort(llista, n, sizeof(void *), compara);
    placas = llista;
}

int compara(const void *a, const void *b) {
    void **pa, **pb;
    char *ca, *cb;

    pa = (void **) a;
    pb = (void **) b;
    ca = (char *) pa[0];
    cb = (char *) pb[0];

    return strcmp(ca, cb);
}

void cargaplaca(void *&placas, char *placa) {
    int i;
    void **lplacas = (void **) placas;
    if (lplacas == nullptr)
        lplacas = new void *[100]{};
    for (i = 0; lplacas[i] != nullptr; i++);
    lplacas[i] = placa;
    lplacas[i + 1] = nullptr;
    placas = lplacas;
}


void *buscaconductor(void *lista, int licencia) {
    int *lic;
    void **llista = (void **) lista;
    void **ptr = (void **) llista[0];
    while (ptr) {
        void **reg = (void **) ptr[0];
        lic = (int *) reg[0];
        if (*lic == licencia)break;
        ptr = (void **) ptr[1];
    }
    return ptr[0];
}

void *buscalistaconductores(void *lista, void *dato) {
    return lista;
}

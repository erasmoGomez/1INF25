#include "src/MemoriaIncrementos.hpp"

int main() {
    int *codigos, n_datos = 0;
    leer_datos(codigos, n_datos);
    for(int i=0; i<n_datos;i++)
        cout<<"Codigo "<<i+1<<": "<<codigos[i]<<endl;
    return 0;
}

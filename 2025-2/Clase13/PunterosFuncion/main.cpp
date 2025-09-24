#include <iostream>
using namespace std;

double multiplica(int x, int y){
    return x*y;
}

double suma(int x, int y){
    return x+y;
}

int suma_2(int x, int y){
   return x+y;
}

double calcular_promedio(int x, int y){
    return (double)(x+y)/2;
}

double operacion_generica(int x, int y, double(*funcion_generica)(int, int)){
    return funcion_generica(x, y);
}

int main() {
    int x = 6, y = 10;
    //cout<<suma(x,y)<<endl;

    //Declaro un puntero a funcion
    int (*ptr_funcion) (int, int);

    ptr_funcion = suma_2;

    cout<< ptr_funcion(x, y)<<endl;

    double(*arr_ptr_funcion[2])(int, int);
    arr_ptr_funcion[0] = multiplica;
    arr_ptr_funcion[1] = calcular_promedio;

    for(int i = 0; i<2; i++)
        cout<<arr_ptr_funcion[i](x, y)<<endl;

    //Llamar a operacion generica
    cout<< "Funcion Generica con la SUMA: "<< operacion_generica(x, y, suma)<<endl;
    cout<< "Funcion Generica con la CalcularPromedio: "<< operacion_generica(x, y, calcular_promedio)<<endl;
    cout<< "Funcion Generica con la Multiplica : "<< operacion_generica(x, y, multiplica)<<endl;


    return 0;
}

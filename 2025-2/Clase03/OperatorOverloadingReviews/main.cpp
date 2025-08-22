#include "src/Overloads.hpp"

int main() {
    struct Reviews reviews{};
    reviews.n_reviews = 0;
    //LLenar/Leer la estructura reviews
    "Data/reviews.csv"<<reviews; //Realizar una sobrecarga
    //reviews<<"Data/reviews.csv";
    //Operador Binario
    //tipo_dato_resultante operator (operando 1, operando 2);
    //void operator << ("Data/reviews.csv", reviews)
    //void operator <<(const char* file_name, struct Reviews & reviews);
    //leer_reviews(reviews, "Data/reviews.csv");
    cout<<reviews.n_reviews<<endl;
    reviews<<"Reports/reporte_reviews.txt";
//    void operator <<(const char* file_name, struct Reviews & reviews);
//    "hola"<<reviews
//    void operator <<(struct Reviews & reviews, const char* file_name);
//    reviews<<"hola"
    //# Positivos 0.6 a 1.0
    //# Negativos 0.0 a 0.4
    //# Neutrales 0.4 a 0.5
    //Sacar estadisticas
    int estadisticas[3]{};
    reviews += estadisticas;
    cout<<"Cantidad Negativas: "<< estadisticas[0]<<endl;
    cout<<"Cantidad Neutrales: "<< estadisticas[1]<<endl;
    cout<<"Cantidad Positivas: "<< estadisticas[2]<<endl;

    return 0;
}

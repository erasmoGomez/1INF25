#include "src/Overloads.hpp"

int main() {
    struct Reviews reviews{};
    reviews.n_reviews = 0;
    //LLenar/Leer la estructura reviews
    "Data/reviews.csv"<<reviews; //Realizar una sobrecarga

    cout<<reviews.n_reviews<<endl;
    reviews<<"Reports/reporte_reviews.txt";
    //Aumentar rating
    reviews *= 0.08; //Aumentar 0.08 porciento a los ratings
    //Llenar estadisticas
    reviews.n_negatives = 0;
    reviews.n_neutrals = 0;
    reviews.n_positives = 0;
    !reviews;
    cout<<"Cantidad Negativas: "<< reviews.n_negatives<<endl;
    cout<<"Cantidad Neutrales: "<< reviews.n_neutrals<<endl;
    cout<<"Cantidad Positivas: "<< reviews.n_positives<<endl;
    //Ordenar
    ++reviews;
    reviews<<"Reports/reporte_reviews_ordenado.txt";
    return 0;
}

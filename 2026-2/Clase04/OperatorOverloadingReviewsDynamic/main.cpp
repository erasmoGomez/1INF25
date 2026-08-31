#include "Libraries/Controller/ReviewController.hpp"

int main() {
    struct Review* reviews{}; //Sin memoria
    int n_reviews = 0;
    int stats[3]{}; //0 -> negativos 1-> neutrales 2-> positivos
    load_reviews("Data/reviews.csv", reviews, n_reviews);
    print_reviews("Reports/reviews_report.txt", reviews, n_reviews);
    fill_stats(reviews, n_reviews, stats);
    print_stats(stats, n_reviews);


    /*
     *
     *struct Reviews reviews; //Nuevo tipo de dato construido por nosotros
    "Data/reviews.csv"<<reviews; // Las sobrecargas por lo menos deben estar asociadas a un tipo de dato creado por el usuario
    *
    *struct Review* reviews; // Esto es un arreglo dinamico o un puntero a Review
    * // Esto cpp ya no lo considera como un NUEVO TIPO DE DATO
    * "Data/reviews.csv"<<reviews; // const char* << struct Review* // Punteros NO SON nuevos tipo de datos
    * //C++ no va a permitir esa sobrecarga
    * //La solucion es crear una funcion
    * load_reviews("Data/reviews.csv", reviews, n_reviews);
     */
    return 0;
}

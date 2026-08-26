#include "Libraries/Overloads.hpp"

int main() {
    struct Reviews reviews{};
    // What If?
    /*
     *Struct Review review;
     *Struct Review reviews[MAX];
     *pasar como parametro reviews
     *void funcion_estatico(struct Review* reviews);
     *Struct Review* reviews;
     *void funcion_dinamico(struct Review*& reviews);
     */
    //reviews.n_reviews = 0; ya no es necesario
    cout<<reviews.n_reviews<<endl;
    "Data/reviews.csv"<<reviews;
    reviews << "Reports/reviews_report.txt";

    int estadisticas[3]{}; //0 -> negativos 1-> neutrales 2-> positivos
    reviews+=estadisticas;
    cout<<"Cantidad de Reviews NEGATIVOS "<<estadisticas[0]<<endl;
    cout<<"Cantidad de Reviews NEUTRALES "<<estadisticas[1]<<endl;
    cout<<"Cantidad de Reviews POSITIVOS "<<estadisticas[2]<<endl;
    return 0;
}

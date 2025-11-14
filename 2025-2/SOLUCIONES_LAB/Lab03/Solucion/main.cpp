#include "PunterosGenericos.h"

#include <iostream>

void teststreamers(void **streamers) {
    for (int i = 0; streamers[i] != nullptr; i += 1) {
        void **streamer = (void **) streamers[i];
        char *cuenta = (char *) streamer[0];
        std::cout << cuenta << std::endl;
    }
}

void testcomentarios(void **comentarios) {
    for (int i = 0; comentarios[i] != nullptr; i += 1) {
        void **comentario = (void **) comentarios[i];
        char *codigo = (char *) comentario[0];
        char *emisor = (char *) comentario[1];
        char *receptor = (char *) comentario[2];
        char *texto = (char *) comentario[3];
        std::cout << codigo << ',' << emisor << ',' << receptor << ',' << texto << std::endl;
    }
}

int main() {
    void *streamers, *comentarios;

    cargastreamers(streamers);
    //teststreamers((void **) streamers);

    cargacomentarios(comentarios);
    //testcomentarios((void **) comentarios);

    actualizacomentarios(streamers, comentarios);
    imprimestreamers(streamers);

    return 0;
}

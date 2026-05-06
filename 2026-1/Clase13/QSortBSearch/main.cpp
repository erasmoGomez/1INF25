#include "Librerias/AuxiliaryFunctions.hpp"
/*
    IMPORTANTE:

    Este programa es únicamente un DEMO EDUCATIVO.

    El objetivo es mostrar cómo funcionan las funciones qsort y bsearch
    de la librería <cstdlib>, especialmente en escenarios donde se trabaja
    con arreglos de punteros genéricos (void*).

    ⚠️ Este código NO representa una solución completa de laboratorio.

    En los labs del curso se espera:
    - Uso de void* y los casteos necesarios de forma correcta
    - Lectura de datos desde archivos (no datos hardcodeados)
    - Separación adecuada en funciones
    - Mayor control sobre la gestión de memoria
    - Diseño más estructurado y alineado al enunciado del problema

    Aquí se simplifican varios aspectos (como la carga de datos)
    para enfocarnos únicamente en el uso de:
        - qsort
        - bsearch

    👉 En resumen: este código es para entender cómo funcionan estas
       funciones, no como referencia directa de implementación para labs.
*/
int main() {
    /*
    qsort recibe la dirección de dos elementos del arreglo.

    Como el arreglo es void**, cada elemento es un void*.
    Entonces:
    - a es la dirección de un elemento del arreglo
    - ese elemento es un void*
    - por eso primero convertimos a void**
    - luego accedemos al registro Alumno*
    */
    int n = 5;

    void **arr_alumnos = new void *[n];

    arr_alumnos[0] = new Alumno{20231234, "Lucia", 15.5};
    arr_alumnos[1] = new Alumno{20224567, "Marco", 18.0};
    arr_alumnos[2] = new Alumno{20237890, "Ana", 12.5};
    arr_alumnos[3] = new Alumno{20220111, "Diego", 16.8};
    arr_alumnos[4] = new Alumno{20235678, "Sofia", 19.2};

    cout << "ARREGLO ORIGINAL" << endl;
    imprimir_reporte(arr_alumnos, n);

    qsort(arr_alumnos, n, sizeof(void *), comparar_por_nota_desc);

    cout << endl << "ORDENADO POR NOTA DESCENDENTE" << endl;
    imprimir_reporte(arr_alumnos, n);

    qsort(arr_alumnos, n, sizeof(void *), comparar_por_nombre_alfambeticamente);

    cout << endl << "ORDENADO POR NOMBRE ASCENDENTEMENTE" << endl;
    imprimir_reporte(arr_alumnos, n);

    qsort(arr_alumnos, n, sizeof(void *), comparar_por_codigo);

    cout << endl << "ORDENADO POR CODIGO" << endl;
    imprimir_reporte(arr_alumnos, n);

    /*
    En bsearch:
    - key apunta a la clave buscada, en este caso un int
    - element apunta a un elemento del arreglo
    - como el arreglo es void**, el element debe tratarse como void**
    */

    int codigo_buscadp = 20231234;
    int *ptr_codigo = &codigo_buscadp;
    void *resultado = bsearch(
        ptr_codigo,
        arr_alumnos,
        n,
        sizeof(void *),
        comparar_codigo_bsearch
    );

    if (resultado != nullptr) {
        Alumno *alumno_encontrado = (Alumno *) (*(void **) resultado);

        cout << endl << "Alumno encontrado:" << endl;
        imprimir_alumno(*alumno_encontrado);
    } else {
        cout << endl << "No se encontro un alumno con ese codigo." << endl;
    }

    for (int i = 0; i < n; i++) {
        delete (Alumno *) arr_alumnos[i];
    }

    delete[] arr_alumnos;
    return 0;
}

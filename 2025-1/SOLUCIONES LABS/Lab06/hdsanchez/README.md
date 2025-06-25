# Laboratorio 06

## Compilación del Proyecto

Este proyecto en C++ se compila con el siguiente comando:

```bash
g++ -Wall -std=c++14 -fsanitize=address -g ./*.cpp -o main
```

### Explicación de los flags del compilador:

-   `-Wall`: Habilita todas las advertencias estándar del compilador
-   `-std=c++14`: Usa el estándar de lenguaje C++14
-   `-fsanitize=address`: Habilita AddressSanitizer para detectar errores de memoria en tiempo de ejecución
-   `-g`: Genera información de depuración para usar con GDB u otros depuradores
-   `./*.cpp`: Compila todos los archivos .cpp en el directorio actual
-   `-o main`: Genera el ejecutable como "main"

Nota: Se ha probado en MacOSX-ARM64:

```bash
$ uname -rsm
Darwin 24.2.0 arm64
```

## Ejecución del Programa

Después de compilar, ejecuta el programa con:

```bash
./main
```

## Requisitos

-   Compilador g++
-   Biblioteca estándar compatible con C++14

Nota: AddressSanitizer ayuda a detectar problemas de memoria como fugas, desbordamientos de buffer, etc. durante la ejecución.

## Comentarios

Ojo, la solución presentada no sigue necesariamente las indicaciones de estilo del enunciado.
Pueden que hayan funciones con más de 20 líneas, código implementado en .hpp, código en un solo archivo en vez de varios, etc.

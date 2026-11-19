# Minecraft Survival STL — CLion

Proyecto C++17 con estructura `model/` y `view/`, `main.cpp` en la raíz y controlador principal `GestorJuego`.

## Abrir
Descomprimir, abrir la carpeta en CLion y ejecutar el target `MinecraftSurvivalSTL`.

## Arquitectura
- `main.cpp`: únicamente crea `GestorJuego`, carga CSV y ejecuta el menú.
- `model/GestorJuego.*`: coordinación y reglas de juego.
- `model/Utils.*`: imports habituales, `using namespace std`, apertura de archivos, validación y lectura de entrada.
- `model/DataLoader.*`: carga de CSV mediante `Utils::open_read_file`.
- `model/MiningStack.*`: pila LIFO con `vector`.
- `model/VillagerQueue.*`: cola FIFO con `list`.
- `model/Region.*`: clase abstracta, herencia, polimorfismo, destructores virtuales y operadores de comparación.
- `model/WorldGraph.*`: grafo no dirigido, BFS con `list` y DFS con `vector`.
- `view/GameView.*`: menú, mensajes y presentación del inventario de recursos.
- `data/*.csv`: datos iniciales.

El programa conserva el estado solo en memoria; los CSV no se sobrescriben.

## Notas
- Los archivos usan `using namespace std;` para evitar el prefijo `std::`.
- `open_write_file` queda disponible para implementar exportación de reportes.
- Las clases de pila, cola y grafo conservan sus métodos de impresión originales; se pueden trasladar a `GameView` como ejercicio de separación estricta de responsabilidades.

## Patron de lectura de archivos
Cada registro implementa `bool read(ifstream& input)`. `DataLoader` solo abre, omite cabecera, crea objeto, llama `read`, inserta y cuenta. Los registros son `BlockRecord`, `VillagerRequest`, `RegionRecord`, `PathRecord` y `ResourceRecord`. No se usa `stringstream`. El valor de retorno de `read` distingue la lectura correcta de EOF; los registros mal formados activan `failbit` y detienen la carga.

Tested on MacOSX-ARM64.

To build:
```
$ g++ -std=c++11 -stdlib=libc++ -g -fsanitize=address ./*.cpp -o ./main
```

To run:
```
$ ./main
[WARNING] cargareserva: no hay mas stock para el pedido (DEK2757, 86898639).
[WARNING] cargareserva: no hay mas stock para el pedido (JZC7527, 20610190).
```

Output files:
```
$ ls Reporte*.txt
ReporteClientes.txt  ReporteFinal.txt     ReporteReserva.txt
```

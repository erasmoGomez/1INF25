import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

class Alumno {

    private int codigo;
    private String nombre;

    //Metodo polimorfico
    public void leerDatos(Scanner arch) {
        //20160658 Arca/Amezquita/Edric-Ronald
        codigo = arch.nextInt();
        nombre = arch.next();
    }

    // Metodo polimorfico
    public void imprimeDatos(FileWriter output) throws IOException {
        imprimeLinea(output, '=', 53);
        output.write("Codigo del alumno: " + codigo + "\n");
        output.write("Nombre del alumno: " + nombre + "\n");
    }

    public void imprimeLinea(FileWriter output, char c, int n) throws IOException {
        for (int i = 0; i < n; i++) {
            output.write(c);
        }
        output.write("\n");
    }
}
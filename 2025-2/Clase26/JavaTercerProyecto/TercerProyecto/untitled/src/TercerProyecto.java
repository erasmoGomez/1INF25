import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class TercerProyecto {
    public static void main(String[] args) throws IOException {
        Scanner input = crearScannerEntrada("personal.txt");
        FileWriter output = crearFileWriterSalida("reporte.txt");
        int dni;
        String nombre;
        String buffer;
        char sexo;
        double sueldo;
        //20082060 M ERASMO_GOMEZ 23455.60
        while (input.hasNext()) {
            dni = input.nextInt();
            buffer = input.next();
            sexo = buffer.charAt(0);
            nombre = input.next();
            sueldo = input.nextDouble();
            //System.out.println(dni + " " + nombre + " " + sexo + " " + sueldo);
            escribir_reporte(output, dni, nombre, sueldo, sexo);
        }
        output.close();
    }

    public static Scanner crearScannerEntrada(String nombre) throws IOException {
        File file = new File(nombre);
        if (!file.exists()) {
            throw new IOException("Archivo no encontrado: " + nombre);
        }
        return new Scanner(file);
    }

    public static FileWriter crearFileWriterSalida(String nombre) throws IOException {
        File file = new File(nombre);
        if (!file.exists()) file.createNewFile();
        return new FileWriter(file);
    }

    public static void escribir_reporte(FileWriter output,
                                        int dni,
                                        String nombre,
                                        double sueldo,
                                        char sexo) throws IOException {
        //System.out.println(dni + " " + nombre + " " + sexo + " " + sueldo);
        output.write(dni + "_" + nombre+ "_ "+sueldo+" "+ sexo + System.lineSeparator());
        //output.write(dni + " " + nombre + " " + sexo + " " + sueldo);
    }
}

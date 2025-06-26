package tercerprograma;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class TercerPrograma {

    public static void main(String[] args) {
        try {
            Scanner input = crearScannerEntrada("personal.txt");
            FileWriter output = crearFileWriterSalida("reporte.txt");

            int dni;
            String nombre;
            String buffer;
            char sexo;
            double sueldo;

            // Ejemplo de línea: 37870823  M SAENZ_ARANDA_WILMER  23455.60
            while (input.hasNext()) {
                dni = input.nextInt();
                buffer = input.next(); 
                sexo = buffer.charAt(0);
                nombre = input.next();
                sueldo = input.nextDouble();

                escribirReporte(output, dni, nombre, sueldo, sexo);
            }

            input.close();
            output.close();
        } catch (IOException e) {
            System.err.println("Error al procesar archivos: " + e.getMessage());
        }
    }

    public static Scanner crearScannerEntrada(String nombreArchivo) throws IOException {
        File archivo = new File(nombreArchivo);
        if (!archivo.exists()) {
            throw new IOException("Archivo no encontrado: " + nombreArchivo);
        }
        return new Scanner(archivo);
    }

    public static FileWriter crearFileWriterSalida(String nombreArchivo) throws IOException {
        File archivo = new File(nombreArchivo);
        if (!archivo.exists()) {
            archivo.createNewFile();
        }
        return new FileWriter(archivo);
    }

    public static void escribirReporte(FileWriter output, int dni, String nombre, double sueldo, char sexo) throws IOException {
        output.write(dni + " - " + nombre + " - " + sueldo + " - " + sexo + System.lineSeparator());
    }
}

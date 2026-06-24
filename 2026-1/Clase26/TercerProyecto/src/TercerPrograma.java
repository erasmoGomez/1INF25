import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class TercerPrograma {
    public static void main(String[] args) throws IOException {
        Scanner input = crear_scanner_entrada("personal.txt");
        FileWriter output = crear_filewriter_salida("reporte.txt");
        //20082060 M ERASMO_GOMEZ 33
        int codigo;
        char sexo;
        String nombre;
        int edad;
        String buffer;
        while(input.hasNext()){
            codigo = input.nextInt();
            buffer = input.next();
            sexo = buffer.charAt(0);
            nombre = input.next();
            edad = input.nextInt();
            escribir_reporte(output, codigo, sexo, nombre, edad);
        }
        input.close();
        output.close();
    }

    public static void escribir_reporte(FileWriter output,
                                        int codigo,
                                        char sexo,
                                        String nombre,
                                        int edad) throws IOException {
        output.write(codigo + " " + nombre + " " + sexo + " " + edad + System.lineSeparator());
    }

    public static FileWriter crear_filewriter_salida(String file_name) throws IOException {
        File file = new File(file_name);
        if (!file.exists()) file.createNewFile();
        return new FileWriter(file);
    }

    public static Scanner crear_scanner_entrada(String file_name) throws IOException {
        File file = new File(file_name);
        if(!file.exists()){
            throw new IOException("Archivo no encontrado: " + file_name);
        }
        return new Scanner(file);
    }
}

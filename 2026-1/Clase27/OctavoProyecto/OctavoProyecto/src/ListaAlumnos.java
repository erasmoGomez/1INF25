import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Erasmo G. Montoya
 */
class ListaDeAlumnos {

    private ArrayList<Alumno> alumnos;

    public ListaDeAlumnos() {
        alumnos = new ArrayList<Alumno>();
    }

    public void leer_alumnos() throws IOException {
        Scanner input = crearScannerEntrada("Alumnos.txt");
        String tipoAlumno;
        Alumno alumno;
        while (input.hasNext()) {
            tipoAlumno = input.next(); //"R" o "I"
            if (tipoAlumno.compareTo("R") == 0) {
                alumno = new AlumnoRegular();
            } else {
                alumno = new AlumnoIntercambio();
            }
            alumno.leerDatos(input);
            alumnos.add(alumno);
        }
    }

    public void imprimir_alumnos() throws IOException{
        FileWriter output = crearFileWriterSalida("reporte.txt");
        for(Alumno a: alumnos){
            a.imprimeDatos(output);
        }
        output.close();
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
}
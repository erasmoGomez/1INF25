import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Erasmo G. Montoya
 */
public class AlumnoRegular extends Alumno {

    private String especialidad;
    private String facultad;

    public AlumnoRegular() {
    }

    @Override
    public void leerDatos(Scanner arch) {
        super.leerDatos(arch);
        especialidad = arch.next();
        facultad = arch.next();
    }

    @Override
    public void imprimeDatos(FileWriter output) throws IOException {
        super.imprimeDatos(output); //Llama a la clase Padre
        output.write("Alumno Regular\n");
        output.write("Especialidad: " + especialidad+"\n");
        output.write("Facultad:   " + facultad+"\n");
    }
}
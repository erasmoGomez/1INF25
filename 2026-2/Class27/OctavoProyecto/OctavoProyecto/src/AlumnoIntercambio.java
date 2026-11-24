import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Erasmo G. Montoya
 */
public class AlumnoIntercambio extends Alumno {

    private String paisDeOrigen;
    private ArrayList<String> idiomas;
    private int numeroDeSemestres;

    //Japon Japones Italiano France 2
    public AlumnoIntercambio() {
        idiomas = new ArrayList<String>();
    }

    @Override
    public void leerDatos(Scanner arch) {
        super.leerDatos(arch);
        String idioma;
        paisDeOrigen = arch.next();
        //Aleman Ingles Castellano Frances Italiano 1
        while (!arch.hasNextInt()) { //Mientras no venga un entero en el siguiente valor
            idioma = arch.next();
            idiomas.add(idioma);
        }
        numeroDeSemestres = arch.nextInt();
    }

    @Override
    public void imprimeDatos(FileWriter output) throws IOException {
        super.imprimeDatos(output);
        output.write("Alumno de Intercambio\n");
        output.write("Pais:    " + paisDeOrigen + "\n");
        output.write("Idiomas:");
        output.write(String.valueOf(idiomas.size()));
        //output.write(idiomas.size()+"");

        for (String id : idiomas) {
            output.write(" " + id);
        }
        output.write(System.lineSeparator());
        output.write("Permanecera: " + numeroDeSemestres + " Semestres\n");
    }
}
import java.io.FileNotFoundException;
import java.io.IOException;

/**
 *
 * @author Erasmo G. Montoya
 */
public class OctavoProyecto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        ListaDeAlumnos lista_alumnos = new ListaDeAlumnos();
        lista_alumnos.leer_alumnos();
        lista_alumnos.imprimir_alumnos();
    }
}
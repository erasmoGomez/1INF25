import java.io.IOException;

public class CuartoProyecto {
    public static void main(String[] args) throws IOException {
        // Fundamental reservar memoria.
        ListaPersonas personas = new ListaPersonas();
        personas.leer();
        personas.imprimir();
    }
}

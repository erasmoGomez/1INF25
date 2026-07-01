import java.io.FileNotFoundException;


public class Principal {
    public static void main(String[] args) throws FileNotFoundException {
        PlataformaStreaming plataforma = new PlataformaStreaming("datos.txt");
        plataforma.cargarDatos();
        plataforma.imprimirReporte();
    }
}
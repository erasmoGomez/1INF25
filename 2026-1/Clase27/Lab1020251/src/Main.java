import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        AutoridadTransporte atu = new AutoridadTransporte("datos.txt");
        atu.cargarDatos(); // 5 puntos
        atu.procesarCapturas(); // 10 puntos
        atu.imprimirInfracciones(); // 5 puntos
    }
}
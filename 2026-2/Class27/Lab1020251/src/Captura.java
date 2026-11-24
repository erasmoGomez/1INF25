
import java.util.Scanner;

public class Captura extends Registro {
    private String placa;
    private double velocidad;
    private Carril carril;
    private double latitud;
    private double longitud;
    private String region;
    private String provincia;
    private int km;
    private String fecha;
    private String hora;
    private String codigoCamara;

    public String getPlaca() {
        return placa;
    }

    public double getVelocidad() {
        return velocidad;
    }

    public Carril getCarril() {
        return carril;
    }

    public double getLatitud() {
        return latitud;
    }

    public double getLongitud() {
        return longitud;
    }

    public String getRegion() {
        return region;
    }

    public String getProvincia() {
        return provincia;
    }

    public int getKm() {
        return km;
    }

    public String getFecha() {
        return fecha;
    }

    public String getHora() {
        return hora;
    }

    public String getCodigoCamara() {
        return codigoCamara;
    }

    @Override
    public boolean cargarDatos(Scanner scanner) {
        this.placa = scanner.next();
        this.velocidad = scanner.nextDouble();
        this.carril = getCarril(scanner.nextInt());
        this.latitud = scanner.nextDouble();
        this.longitud = scanner.nextDouble();
        this.region = scanner.next();
        this.provincia = scanner.next();
        this.km = scanner.nextInt();
        this.fecha = scanner.next();
        this.hora = scanner.next();
        this.codigoCamara = scanner.next();

        return true;
    }

    @Override
    public String toString() {
        String resultado = "";
        resultado += String.format("║ Placa: %-43s ║\n", placa);
        String velStr = String.format("%.2f km/h", velocidad);
        resultado += String.format("║ Velocidad: %-39s ║\n", velStr);
        resultado += String.format("║ Carril: %-42s ║\n", carril.getTipo());
        resultado += String.format("║ Ubicación: Lat %.6f, Lon %.6f          ║\n", latitud, longitud);
        resultado += String.format("║ Región: %-42s ║\n", region);
        resultado += String.format("║ Provincia: %-39s ║\n", provincia);
        resultado += String.format("║ Kilómetro: %-39d ║\n", km);
        resultado += String.format("║ Fecha: %-43s ║\n", fecha);
        resultado += String.format("║ Hora: %-44s ║\n", hora);
        resultado += String.format("║ Código Cámara: %-35s ║\n", codigoCamara);

        return resultado;
    }

    @Override
    public void imprimir() {
        System.out.println(this);
    }

    private Carril getCarril(int nroCarril) {
        return switch (nroCarril) {
            case 1 -> new CarrilEmergencia();
            case 2 -> new CarrilLento();
            case 5 -> new CarrilRapido();
            default -> new CarrilEstandard();
        };
    }
}
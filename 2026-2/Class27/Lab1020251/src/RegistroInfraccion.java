
public class RegistroInfraccion {
    private String codigoInfraccion;
    private double monto;
    private int puntos;
    private Captura captura;
    private Vehiculo vehiculo;

    public RegistroInfraccion() {
    }

    public RegistroInfraccion(final String codigoInfraccion, final double monto,
                              final int puntos, final Captura captura, final Vehiculo vehiculo) {

        this.codigoInfraccion = codigoInfraccion;
        this.monto = monto;
        this.puntos = puntos;
        this.captura = captura;
        this.vehiculo = vehiculo;
    }

    public String getCodigoInfraccion() {
        return codigoInfraccion;
    }

    public double getMonto() {
        return monto;
    }

    public int getPuntos() {
        return puntos;
    }

    public Captura getCaptura() {
        return captura;
    }

    public Vehiculo getVehiculo() {
        return vehiculo;
    }

    @Override
    public String toString() {
        String resultado = "";
        resultado += "╔════════════════════════════════════════════════════╗\n";
        resultado += String.format("║         REGISTRO DE INFRACCIÓN DE TRÁNSITO         ║\n");
        resultado += "╠════════════════════════════════════════════════════╣\n";
        resultado += String.format("║ Código de Infracción: %-28s ║\n", codigoInfraccion);
        resultado += String.format("║ Monto de la Multa: S/ %-28.2f ║\n", monto);
        resultado += String.format("║ Puntos en Licencia: %-30d ║\n", puntos);
        resultado += "╠════════════════════════════════════════════════════╣\n";
        resultado += String.format("║ DESTINATARIO DE LA INFRACCIÓN:                     ║\n");
        resultado += "╠════════════════════════════════════════════════════╣\n";
        resultado += vehiculo.getPropietario().toString();
        resultado += "╠════════════════════════════════════════════════════╣\n";
        resultado += String.format("║ DATOS DEL VEHÍCULO:                                ║\n");
        resultado += "╠════════════════════════════════════════════════════╣\n";
        resultado += vehiculo.toString();
        resultado += "╠════════════════════════════════════════════════════╣\n";
        resultado += String.format("║ DATOS DE LA CAPTURA ELECTRÓNICA:                   ║\n");
        resultado += "╠════════════════════════════════════════════════════╣\n";
        resultado += captura.toString();
        resultado += "╚════════════════════════════════════════════════════╝\n";

        return resultado;
    }
}
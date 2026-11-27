/**
 *
 * @author e.gomez
 */
public class SuscripcionVIP extends Suscripcion {
    @Override
    public String getTipo() {
        return "VIP";
    }

    @Override
    public double calcularPrecio() {
        return 100.00;
    }
}
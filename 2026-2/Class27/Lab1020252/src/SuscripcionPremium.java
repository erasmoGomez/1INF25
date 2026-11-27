/**
 *
 * @author e.gomez
 */
public class SuscripcionPremium extends Suscripcion {
    @Override
    public String getTipo() {
        return "PREMIUM";
    }

    @Override
    public double calcularPrecio() {
        return 80.00;
    }

}
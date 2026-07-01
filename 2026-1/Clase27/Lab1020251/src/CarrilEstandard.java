
public class CarrilEstandard extends Carril {
    @Override
    public String getTipo() {
        return "Estándar";
    }

    @Override
    public double velocidadMaxima(int km) {
        if (km <= 100) {
            return 80.00;
        } else if (km <= 200) {
            return 120.00;
        } else {
            return 100.00;
        }
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return
                categoria.equals("Motocicleta") ||
                        categoria.equals("Coupe") ||
                        categoria.equals("SUV") ||
                        categoria.equals("Sedan") ||
                        categoria.equals("Camioneta") ||
                        categoria.equals("Ambulancia");
    }
}
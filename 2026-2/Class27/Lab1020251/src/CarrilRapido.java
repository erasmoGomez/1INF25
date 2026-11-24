public class CarrilRapido extends Carril {
    @Override
    public String getTipo() {
        return "Rápido";
    }

    @Override
    public double velocidadMaxima(int km) {
        if (km <= 100) {
            return 120.00;
        } else if (km <= 200) {
            return 160.00;
        } else {
            return 140.00;
        }
    }

    public double velocidadMinima(int km) {
        if (km <= 100) {
            return 80.00;
        } else if (km <= 200) {
            return 100.00;
        } else {
            return 90.00;
        }
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return
                categoria.equals("Coupe") ||
                        categoria.equals("Sedan") ||
                        categoria.equals("SUV") ||
                        categoria.equals("Camioneta");
    }

    @Override
    public boolean velocidadPemitida(int km, double velocidad) {
        return velocidad >= velocidadMinima(km)
                && velocidad <= velocidadMaxima(km);
    }
}
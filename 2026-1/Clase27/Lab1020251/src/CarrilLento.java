
public class CarrilLento extends Carril {
    @Override
    public String getTipo() {
        return "Lento";
    }

    @Override
    public double velocidadMaxima(int km) {
        return 60.00;
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return
                categoria.equals("Camion") ||
                        categoria.equals("Tractor") ||
                        categoria.equals("Trailer");
    }
}
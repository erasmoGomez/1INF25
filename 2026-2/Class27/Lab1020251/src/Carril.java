
public abstract class Carril {
    public abstract String getTipo();
    public abstract double velocidadMaxima(int km);
    public abstract boolean vehiculoPermitido(String categoria);

    public boolean velocidadPemitida(int km, double velocidad) {
        return velocidad <= velocidadMaxima(km);
    }
}
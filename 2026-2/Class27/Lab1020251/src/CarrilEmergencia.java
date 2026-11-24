
public class CarrilEmergencia extends Carril {
    @Override
    public String getTipo() {
        return "Emergencia";
    }

    @Override
    public double velocidadMaxima(int km) {
        return 80.00;
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return
                categoria.equals("Ambulancia") ||
                        categoria.equals("Grua");
    }
}
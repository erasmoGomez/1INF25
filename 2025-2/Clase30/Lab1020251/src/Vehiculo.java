import java.util.Scanner;

public class Vehiculo extends Registro {
    private String placa;
    private String marca;
    private String modelo;
    private int anhoFab;
    private String categoria;
    private Propietario propietario;

    public Propietario getPropietario() {
        return this.propietario;
    }

    public void setPropietario(final Propietario propietario) {
        this.propietario = propietario;
    }

    public String getPlaca() {
        return placa;
    }

    public String getCategoria() {
        return categoria;
    }

    @Override
    public boolean cargarDatos(Scanner scanner) {
        String lPlaca = scanner.next();
        if (!lPlaca.equals("FIN")) {
            this.placa = lPlaca;
            this.marca = scanner.next();
            this.modelo = scanner.next();
            this.anhoFab = scanner.nextInt();
            this.categoria = scanner.next();

            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        String resultado = "";
        resultado += String.format("║ Placa: %-43s ║\n", placa);
        resultado += String.format("║ Marca: %-43s ║\n", marca);
        resultado += String.format("║ Modelo: %-42s ║\n", modelo);
        resultado += String.format("║ Año de Fabricación: %-30d ║\n", anhoFab);
        resultado += String.format("║ Categoría: %-39s ║\n", categoria);
        return resultado;
    }

    @Override
    public void imprimir() {
        System.out.println(this);
    }
}
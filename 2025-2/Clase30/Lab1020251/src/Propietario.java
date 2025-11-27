import java.util.Scanner;

public class Propietario extends Registro {
    private int dni;
    private String nombres;
    private String apellidos;
    private String direccion;

    public int getDni() {
        return dni;
    }

    @Override
    public boolean cargarDatos(Scanner scanner) {
        if (scanner.hasNextInt()) {
            this.dni = scanner.nextInt();
            this.nombres = scanner.next();
            this.apellidos = scanner.next();
            this.direccion = scanner.next();

            return true;
        }
        scanner.next();
        return false;
    }

    @Override
    public String toString() {
        String resultado = "";
        resultado += String.format("║ DNI: %-45d ║\n", dni);
        resultado += String.format("║ Nombres: %-41s ║\n", nombres);
        resultado += String.format("║ Apellidos: %-39s ║\n", apellidos);
        resultado += String.format("║ Dirección: %-39s ║\n", direccion);
        return resultado;
    }

    @Override
    public void imprimir() {
        System.out.println(this);
    }
}
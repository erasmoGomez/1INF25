import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AutoridadTransporte {
    private List<Propietario> propietarios;
    private List<Vehiculo> vehiculos;
    private List<Captura> capturas;
    private List<RegistroInfraccion> registroInfracciones;
    private final Scanner archivo;

    public AutoridadTransporte() {
        this.propietarios = new ArrayList<>();
        this.vehiculos = new ArrayList<>();
        this.capturas = new ArrayList<>();
        this.registroInfracciones = new ArrayList<>();

        this.archivo = new Scanner(System.in);
    }

    public AutoridadTransporte(final String nombreArchivo) throws FileNotFoundException {
        this.propietarios = new ArrayList<>();
        this.vehiculos = new ArrayList<>();
        this.capturas = new ArrayList<>();
        this.registroInfracciones = new ArrayList<>();

        this.archivo = new Scanner(new File(nombreArchivo));
    }

    public void cargarDatos() {
        this.cargarPropietarios();
        this.cargarVehiculos();
        this.cargarCapturas();
    }

    private void cargarPropietarios() {
        while (archivo.hasNext()) {
            Propietario propietario = new Propietario();
            if (!propietario.cargarDatos(archivo)) {
                break;
            }

            propietarios.add(propietario);
        }
    }

    private void cargarVehiculos() {
        while (archivo.hasNext()) {
            Vehiculo vehiculo = new Vehiculo();
            if (!vehiculo.cargarDatos(archivo)) {
                break;
            }

            int dniPropietario = archivo.nextInt();
            vehiculo.setPropietario(buscarPropietario(dniPropietario));
            vehiculos.add(vehiculo);
        }
    }

    public void cargarCapturas() {
        while (archivo.hasNext()) {
            Captura captura = new Captura();
            if (captura.cargarDatos(archivo)) {
                capturas.add(captura);
            }
        }
    }

    public void procesarCapturas() {
        for (Captura captura : capturas) {
            procesarCaptura(captura);
        }
    }

    public void imprimirInfracciones() {
        for (RegistroInfraccion infraccion : registroInfracciones) {
            System.out.println(infraccion);
        }
    }

    private void procesarCaptura(final Captura captura) {
        double velocidad = captura.getVelocidad();
        int km = captura.getKm();
        Vehiculo vehiculo = buscarVehiculo(captura.getPlaca());

        Carril carril = captura.getCarril();
        boolean vehiculoEsPermitido =
                carril.vehiculoPermitido(vehiculo.getCategoria());
        boolean velocidadPermitida =
                carril.velocidadPemitida(km, velocidad);

        if (!velocidadPermitida) {
            registroInfracciones.add(new RegistroInfraccion("M20", 963.00, 50,
                    captura, vehiculo));
        }

        if (!vehiculoEsPermitido) {
            registroInfracciones.add(new RegistroInfraccion("G29", 428.00, 50,
                    captura, vehiculo));
        }
    }

    private Propietario buscarPropietario(final int dni) {
        for (Propietario p : this.propietarios) {
            if (p.getDni() == dni) {
                return p;
            }
        }
        return null;
    }

    private Vehiculo buscarVehiculo(final String placa) {
        return this.vehiculos.stream()
                .filter(v -> v.getPlaca().equals(placa)) // Query BD
                .findFirst()
                .get();

//        for (Vehiculo v : this.vehiculos) {
//            if (v.getPlaca().equals(placa)) {
//                return v;
//            }
//        }
//        return null;
    }
}
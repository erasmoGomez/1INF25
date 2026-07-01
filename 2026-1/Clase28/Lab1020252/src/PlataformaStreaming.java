import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author e.gomez
 */
public class PlataformaStreaming {
    private final List<CanalStreaming> canales;
    private final List<Usuario> usuarios;
    private final List<Suscripcion> suscripciones;
    private final Scanner archivo;


    public PlataformaStreaming() {
        this.canales = new ArrayList<>();
        this.usuarios = new ArrayList<>();
        this.suscripciones = new ArrayList<>();

        this.archivo = new Scanner(System.in);
    }

    public PlataformaStreaming(String nombreArchivo) throws FileNotFoundException {
        this.canales = new ArrayList<>();
        this.usuarios = new ArrayList<>();
        this.suscripciones = new ArrayList<>();

        this.archivo = new Scanner(new File(nombreArchivo));
    }

    public void cargarDatos() {
        this.cargarCanales();
        this.cargarUsuarios();
        this.cargarSuscripciones();
    }

    public void imprimirReporte() {
        System.out.println("==============================================================================================================================");
        System.out.println("                                                          REPORTE DE USUARIOS");
        System.out.println("==============================================================================================================================");

        System.out.printf(
                "%-4s %-20s %-10s %-4s %-12s %-12s %-12s %-25s %-20s\n",
                "ID", "Nombre Completo", "DNI", "Edad", "Ciudad",
                "F. Nac", "Teléfono", "Email", "Ocupación"
        );
        System.out.println("------------------------------------------------------------------------------------------------------------------------------");

        for (Usuario u : usuarios) {
            System.out.println(u);
        }

        System.out.println("==============================================================================================================================");
    }


    private void cargarCanales() {
        while (this.archivo.hasNext()) {
            CanalStreaming canal = new CanalStreaming();
            if (!canal.leer(archivo)) {
                archivo.next();
                break;
            }
            this.canales.add(canal);
        }
    }

    private void cargarUsuarios() {
        while (this.archivo.hasNext()) {
            Usuario usuario = new Usuario();
            if (!usuario.leer(archivo)) {
                archivo.next();
                break;
            }
            this.usuarios.add(usuario);
        }
    }

    private void cargarSuscripciones() {
        while (archivo.hasNext()) {
            String tipo = archivo.next();
            if (tipo == null || tipo.isBlank()) break;

            Suscripcion sub = crearSuscripcion(tipo);
            if (!sub.leer(archivo)) break;

            Usuario usuario = buscarUsuario(sub.getIdUsuario());
            sub.setUsuario(usuario);
            sub.setCanal(buscarCanal(sub.getIdCanal()));

            usuario.getSuscripciones().add(sub);

            suscripciones.add(sub);
        }
    }

    private Suscripcion crearSuscripcion(String tipo) {
        return switch (tipo) {
            case "PREMIUM" -> new SuscripcionPremium();
            case "VIP"     -> new SuscripcionVIP();
            default        -> new SuscripcionBasica();
        };
    }

    private Usuario buscarUsuario(int id) {
        for (Usuario usuario : this.usuarios) {
            if (usuario.getId() == id) {
                return usuario;
            }
        }

        return null;
    }

    private CanalStreaming buscarCanal(int id) {
        for (CanalStreaming canal : this.canales) {
            if (canal.getId() == id) {
                return canal;
            }
        }

        return null;
    }
}
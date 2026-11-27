
import java.util.Scanner;

/**
 *
 * @author e.gomez
 */
public class CanalStreaming extends Registro {
    private int id;
    private String nombre;
    private String descripcion;
    private String fechaCreacion;
    private long cantVisualizaciones;
    private String categoria;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public String getFechaCreacion() {
        return fechaCreacion;
    }

    public void setFechaCreacion(String fechaCreacion) {
        this.fechaCreacion = fechaCreacion;
    }

    public long getCantVisualizaciones() {
        return cantVisualizaciones;
    }

    public void setCantVisualizaciones(long cantVisualizaciones) {
        this.cantVisualizaciones = cantVisualizaciones;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    @Override
    public boolean leer(Scanner archivo) {
        if (!archivo.hasNextInt()) {
            return false;
        }

        this.id = archivo.nextInt();
        this.nombre = archivo.next();
        this.descripcion = archivo.next();
        this.fechaCreacion = archivo.next();
        this.cantVisualizaciones = archivo.nextLong();
        this.categoria = archivo.next();

        return true;
    }

    @Override
    public void imprimir() {
        System.out.println(this);
    }

    @Override
    public String toString() {
        return String.format(
                "%-4d %-15s %-30s %-12s %-15d %-15s",
                id,
                nombre,
                descripcion,
                fechaCreacion,
                cantVisualizaciones,
                categoria
        );
    }
}
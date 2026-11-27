public class Persona {
    private int id;
    private String nombreCompleto;
    public Persona(int id, String nombreCompleto) {
        this.id = id;
        this.nombreCompleto = nombreCompleto;
    }
    public int getId() {return id;}
    public void setId(int id) {this.id = id;}
    public String getNombreCompleto() { return nombreCompleto; }
    public void setNombreCompleto(String nombreCompleto) { this.nombreCompleto = nombreCompleto; }
}

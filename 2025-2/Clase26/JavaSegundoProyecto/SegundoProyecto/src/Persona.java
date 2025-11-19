public class Persona {
    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellido() {
        return apellido;
    }

    public void setApellido(String apellido) {
        this.apellido = apellido;
    }

    public double getSueldo() {
        return sueldo;
    }

    public void setSueldo(double sueldo) {
        this.sueldo = sueldo;
    }

    public boolean isEstado() {
        return estado;
    }

    public void setEstado(boolean estado) {
        this.estado = estado;
    }

    public char getSexo() {
        return sexo;
    }

    public void setSexo(char sexo) {
        this.sexo = sexo;
    }

    public Persona() {
        sueldo = 0.0;
        estado = false;
    }

    public Persona(int dni, String nombre, String apellido, double sueldo, boolean estado, char sexo) {
        this.dni = dni;
        this.nombre = nombre;
        this.apellido = apellido;
        this.sueldo = sueldo;
        this.estado = estado;
        this.sexo = sexo;
    }

    public void imprimir(){
        System.out.println("DNI: " + dni);
        System.out.println("Nombre: " + nombre);
        System.out.println("Apellido: " + apellido);
        System.out.println("Sueldo: " + sueldo);
        System.out.println("Estado: " + estado);
        System.out.println("Sexo: " + sexo);
    }

    private int dni;
    private String nombre;
    private String apellido;
    private double sueldo;
    private boolean estado;
    private char sexo;


}

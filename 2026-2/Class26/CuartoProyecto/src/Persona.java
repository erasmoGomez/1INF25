import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Persona {
    private int codigo;
    private String nombre;
    private String apellido;
    private int edad;
    private boolean estado;
    private char sexo;

    public Persona() {
        estado = false;
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

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
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

    public int getCodigo() {return codigo;}

    public void setCodigo(int codigo) {this.codigo = codigo;}

    public Persona(String nombre, String apellido, int edad) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.edad = edad;
    }

    public void imprimir() {
        System.out.println("Nombre: " + this.nombre);
        System.out.println("Apellido: " + this.apellido);
        System.out.println("Edad: " + this.edad);
    }

    public void leer(Scanner input) {
        //20082060 M ERASMO_GOMEZ 33
        String buffer;
        codigo = input.nextInt();
        buffer = input.next();
        sexo = buffer.charAt(0);
        nombre = input.next();
        edad = input.nextInt();
        if(edad>40){
            estado = false;
        }else{
            estado = true;
        }
    }

    public void imprimir_archivo(FileWriter output) throws IOException {
        output.write(codigo + " " + nombre + " " + sexo + " " + edad + System.lineSeparator());
    }
}

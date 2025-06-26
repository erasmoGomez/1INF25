/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package segundoproyecto;

/**
 *
 * @author hecto
 */
public class Persona {
    private int dni;
    private String nombre;
    private double sueldo;
    private boolean estado;
    private char sexo;

    //Constructores
    public Persona(){
        sueldo = 0.0;
        estado = false;
    }
    
    public Persona(int dni, String nombre, double sueldo, boolean estado, char sexo){
        this.dni = dni;
        this.nombre = nombre;
        this.sueldo = sueldo;
        this.estado = estado;
        this.sexo = sexo;
    }
    /**
     * @return the dni
     */
    public int getDni() {
        return dni;
    }

    /**
     * @param dni the dni to set
     */
    public void setDni(int dni) {
        this.dni = dni;
    }

    /**
     * @return the nombre
     */
    public String getNombre() {
        return nombre;
    }

    /**
     * @param nombre the nombre to set
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    /**
     * @return the sueldo
     */
    public double getSueldo() {
        return sueldo;
    }

    /**
     * @param sueldo the sueldo to set
     */
    public void setSueldo(double sueldo) {
        this.sueldo = sueldo;
    }

    /**
     * @return the estado
     */
    public boolean isEstado() {
        return estado;
    }

    /**
     * @param estado the estado to set
     */
    public void setEstado(boolean estado) {
        this.estado = estado;
    }

    /**
     * @return the sexo
     */
    public char getSexo() {
        return sexo;
    }

    /**
     * @param sexo the sexo to set
     */
    public void setSexo(char sexo) {
        this.sexo = sexo;
    }
    
    public void imprimir(){
        System.out.println(dni + " - " + nombre + " - " + sueldo + " - " + sexo + " - " + estado);
        System.out.println();
    }
    
}

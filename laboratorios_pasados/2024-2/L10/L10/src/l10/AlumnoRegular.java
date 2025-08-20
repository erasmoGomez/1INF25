/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package l10;

import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
class AlumnoRegular extends Alumno {
    private String especialidad;
    private String facultad;
    
    public String getEspecialidad() {
        return especialidad;
    }

    public String getFacultad() {
        return facultad;
    }
    
    public void setEspecialidad(String especialidad) {
        this.especialidad = especialidad;
    }

    public void setFacultad(String facultad) {
        this.facultad = facultad;
    }

    @Override
    public String getPaisDeOrigen() {
        return "Perú";
    }
    
    @Override
    public double calcularPrecio(Producto producto, double tipoCambiario) {
        // Estudiantes regulares obtienen un descuento del 3%.
        return (producto.getPrecio() - (producto.getPrecio() * 0.03)) * tipoCambiario;
    }
    
    @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        especialidad = archivo.next();
        facultad = archivo.next();
    }

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.print(String.format("\t%-15s\t%-30s\t%-15s\t%-50s\t%-15s", facultad, especialidad, "N/A", "N/A", "N/A"));
        System.out.println();
    }
}
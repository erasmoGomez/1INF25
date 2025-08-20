/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package l10;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
class AlumnoIntercambio extends Alumno {
    private String paisDeOrigen;
    private List<String> idiomas;
    private int numeroDeSemestres;
    
    public AlumnoIntercambio() {
        super();
        idiomas = new ArrayList<>();
    }
    
    @Override
    public String getPaisDeOrigen() {
        return paisDeOrigen;
    }

    public List<String> getIdiomas() {
        return idiomas;
    }

    public int getNumeroDeSemestres() {
        return numeroDeSemestres;
    }
    
    public void setPaisDeOrigen(String paisDeOrigen) {
        this.paisDeOrigen = paisDeOrigen;
    }

    public void setIdiomas(List<String> idiomas) {
        this.idiomas = idiomas;
    }

    public void setNumeroDeSemestres(int numeroDeSemestres) {
        this.numeroDeSemestres = numeroDeSemestres;
    }
    
    @Override
    public double calcularPrecio(Producto producto, double tipoCambiario) {
        // Estudiante de intercambio obtiene 5% de descuento, y se muestra en su moneda nacional
        return (producto.getPrecio() - (producto.getPrecio() * 0.05)) * tipoCambiario;
    }

    @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        paisDeOrigen = archivo.next();
        while (!archivo.hasNextInt()) {
            idiomas.add(archivo.next());
        }
        numeroDeSemestres = archivo.nextInt();
    }

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.print(String.format("\t%-15s\t%-30s\t%-15s\t%-50s\t%-15s", "N/A", "N/A", paisDeOrigen, idiomas, "Semestres (" + numeroDeSemestres + ")"));
        System.out.println();
    }
}

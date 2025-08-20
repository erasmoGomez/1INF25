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
abstract class Alumno extends Registro {
    private int codigo;
    private String nombre;
    
    public int getCodigo() {
        return codigo;
    }

    public String getNombre() {
        return nombre;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    
    @Override
    public void cargar(Scanner archivo) {
        codigo = archivo.nextInt();
        nombre = archivo.next();
    }

    @Override
    public void imprimir() {
        System.out.print(String.format("%-10s\t%-35s", codigo, nombre));
    }
    
    public abstract String getPaisDeOrigen();
    public abstract double calcularPrecio(Producto producto, double tipoCambiario);
}

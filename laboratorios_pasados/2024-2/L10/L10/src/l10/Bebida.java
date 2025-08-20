/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package l10;

import java.util.Scanner;

/**
 *
 * @author erasmo
 */
class Bebida extends Producto {
    private char tipoBebida;
    
    @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        tipoBebida = archivo.next().charAt(0);
    }

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.println("Tipo: " + (tipoBebida == 'C' ? "Café" : tipoBebida == 'H' ? "Chocolate" : "Infusión"));
        System.out.println("---------------------------------------------------------------------------------");
    }

    @Override
    public void imprimir(Alumno alumno, Pais pais) {
        super.imprimir(alumno, pais); 
        System.out.println("Tipo: " + (tipoBebida == 'C' ? "Café" : tipoBebida == 'H' ? "Chocolate" : "Infusión"));
        System.out.println("----------------------------------------------------------------------------------------------------");
    }
}

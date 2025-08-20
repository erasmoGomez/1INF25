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
class Pais extends Registro {
    private String nombre;
    private String moneda;
    private double tipoCambio;
    private String idioma;
    
    public String getNombre() {
        return nombre;
    }

    public String getMoneda() {
        return moneda;
    }

    public double getTipoCambio() {
        return tipoCambio;
    }

    public String getIdioma() {
        return idioma;
    }
    
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setMoneda(String codigoMoneda) {
        this.moneda = codigoMoneda;
    }

    public void setTipoCambio(double tipoCambio) {
        this.tipoCambio = tipoCambio;
    }

    public void setIdioma(String codigoIdioma) {
        this.idioma = codigoIdioma;
    }
    
    @Override
    public void cargar(Scanner archivo) {
        nombre = archivo.next();
        moneda = archivo.next();
        tipoCambio = archivo.nextDouble();
        idioma = archivo.next();
    }

    @Override
    public void imprimir() {
        System.out.println(String.format("%-15s\t%-10s\t%10.2f\t%-10s", nombre, moneda, tipoCambio, idioma));
    }
}


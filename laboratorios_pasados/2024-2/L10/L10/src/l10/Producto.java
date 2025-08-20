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
 * @author erasmo
 */
abstract class Producto extends Registro {
    private String codigo;
    private List<Traduccion> nombres;
    private List<Traduccion> descripciones;
    private double precio;
    private int stock;
    
    public Producto() {
        nombres = new ArrayList<>();
        descripciones = new ArrayList<>();
    }
    
    public String getCodigo() {
        return codigo;
    }

    public List<Traduccion> getNombres() {
        return nombres;
    }

    public double getPrecio() {
        return precio;
    }

    public int getStock() {
        return stock;
    }
    
    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public void setNombres(List<Traduccion> nombres) {
        this.nombres = nombres;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }
    
    public List<Traduccion> getDescripciones() {
        return descripciones;
    }

    public void setDescripciones(List<Traduccion> descripciones) {
        this.descripciones = descripciones;
    }
    
    public void setStock(int stock) {
        this.stock = stock;
    }
    
    public String obtenerNombre(String lenguaje) {
        for (Traduccion nombre : nombres) {
            if (nombre.getIdioma().equals(lenguaje)) {
                return nombre.getTexto();
            }
        }
        
        return nombres.get(0).getTexto();
    }
    
    public String obtenerDescripcion(String lenguaje) {
        for (Traduccion descripcion : descripciones) {
            if (descripcion.getIdioma().equals(lenguaje)) {
                return descripcion.getTexto();
            }
        }
        
        return descripciones.get(0).getTexto();
    }
    
    @Override
    public void cargar(Scanner archivo) {
        codigo = archivo.next();
        while (!archivo.hasNextDouble()) {
            Traduccion nombre = new Traduccion();
            nombre.setIdioma(archivo.next());
            nombre.setTexto(archivo.next());
            nombres.add(nombre);
        }
        precio = archivo.nextDouble();
        while (!archivo.hasNextInt()) {
            Traduccion descripcion = new Traduccion();
            descripcion.setIdioma(archivo.next());
            descripcion.setTexto(archivo.next());
            descripciones.add(descripcion);
        }
        stock = archivo.nextInt();
    }

    @Override
    public void imprimir() {
        System.out.println(codigo + ": " + obtenerNombre("ES"));
        System.out.println(obtenerDescripcion("ES"));
        System.out.println("Precio: S/ " + String.format("%.2f", precio));
        System.out.println("Disponile: " + (stock > 0 ? "Sí" : "No"));
    }
    
    public void imprimir(Alumno alumno, Pais pais) {
        System.out.println(codigo + ": " + obtenerNombre(pais.getIdioma()));
        System.out.println(obtenerDescripcion(pais.getIdioma()));
        System.out.println("Precio: " + pais.getMoneda() + " " + String.format("%.2f", alumno.calcularPrecio(this, pais.getTipoCambio())));
        System.out.println("Disponile: " + (stock > 0 ? "Sí" : "No"));
    }
}


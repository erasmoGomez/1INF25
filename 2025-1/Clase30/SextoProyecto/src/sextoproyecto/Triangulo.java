/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sextoproyecto;

/**
 *
 * @author hecto
 */
public class Triangulo extends Figura{
    
    public Triangulo(String id, double base, double altura) {
        super(id, base, altura);
    }
    
    @Override
    public void area(){
        System.out.println("Area del Triangulo es: " + (getBase()*getAltura())/2);
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sextoproyecto;

/**
 *
 * @author Erasmo G. Montoya
 */
class Cilindro extends Circulo {

    private double altura;

    public Cilindro(String identificacion, double radio, double altura) {
        //Circulo(identificacion, radio)
        super(identificacion, radio); //Metodo super q llama al cnsructr de la clase base
        this.altura = altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public double getAltura() {
        return this.altura;
    }

    @Override
    public double area() {
        return 2 * super.area() + super.perimetro() * altura;
    }

    public double areaDeLaBase() {
        return super.area();
    }

    public double volumen() {
        return super.area() * altura;
    }
}

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
public class SextoProyecto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Circulo circulo = new Circulo("Circulo A", 56.75);
        System.out.println("Objeto:    " + circulo.getIdentificacion());
        System.out.println("Radio:     " + circulo.getRadio());
        System.out.println("Area:      " + circulo.area());
        System.out.println("Perimetro: " + circulo.perimetro());
        System.out.println();
        Cilindro cilindro = new Cilindro("Cilindro B", 11.90, 25.77);
        System.out.println("Objeto:                " + cilindro.getIdentificacion());
        System.out.println("Radio:                 " + cilindro.getRadio());
        System.out.println("Altura:                " + cilindro.getAltura());
        System.out.println("Volumen:               " + cilindro.volumen());
        System.out.println("Area de la base:       " + cilindro.areaDeLaBase());
        System.out.println("Area de la superficie: " + cilindro.area());
    }

}

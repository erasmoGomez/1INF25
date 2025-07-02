/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package quintoproyecto;

/**
 *
 * @author hecto
 */
public class QuintoProyecto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Circulo circulo = new Circulo("Circulo A", 55.6);
        System.out.println("Perimetro : " + circulo.perimetro());
        Cilindro cilindro = new Cilindro("Cilindro B", 24.6, 32.1);
        System.out.println("Area : " + cilindro.area());
        System.out.println("Volumen : " + cilindro.volumen());
    }

}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package septimoproyecto;

/**
 *
 * @author Erasmo G. Montoya
 */
import java.util.ArrayList;

public class SeptimoProyecto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Cuadrado c1 = new Cuadrado("C01", 45.67, 25.99);
        Cuadrado c2 = new Cuadrado("C02", 10.71, 9.35);
        Cuadrado c3 = new Cuadrado("C03", 5.97, 2.19);
        Triangulo t1 = new Triangulo("T01", 43.23, 27.53);
        Triangulo t2 = new Triangulo("T02", 11.57, 7.47);

        ArrayList<Figura> figuras = new ArrayList<>();
        figuras.add(c3);
        figuras.add(t1);
        figuras.add(c1);
        figuras.add(t2);
        figuras.add(c2);
        
        for (Figura f : figuras) { //For each
            f.calcularArea();
            System.out.println();
        }
    }

}

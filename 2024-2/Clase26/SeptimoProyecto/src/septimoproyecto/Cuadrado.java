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
class Cuadrado extends Figura {

    public Cuadrado(String identificacion, double base, double altura) {
        super(identificacion, base, altura);
    }

    @Override
    public void calcularArea() {
        System.out.println("Figura: Cuadrado (" + getIdentificacion() + ")");
        System.out.println("Formula = Base x Altura");
        System.out.println("Area = " + getBase() * getAltura());
    }
}

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
public class Cilindro extends Circulo{
    private double altura;
    
    public Cilindro(String id, double radio, double altura){
        super(id, radio); //Llama directamente al metodo constructordel padre.
        this.altura = altura;
    }

    /**
     * @return the altura
     */
    public double getAltura() {
        return altura;
    }

    /**
     * @param altura the altura to set
     */
    public void setAltura(double altura) {
        this.altura = altura;
    }
    
    @Override
    public double area(){
        return 2*altura*super.area()*super.perimetro();
    }
    
    public double area_base(){
        return super.area();
    }
    
    public double volumen(){
        return super.area()*altura;
    }
}

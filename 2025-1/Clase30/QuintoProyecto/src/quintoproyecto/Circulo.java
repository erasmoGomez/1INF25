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
public class Circulo {
    private String id;
    private double radio;
    private final double PI= 3.131592;
    
    public Circulo(){
        
    }
    
    public Circulo(String id, double radio){
        this.id = id;
        this.radio = radio;
    }
    
    public Circulo(String id){
        this.id = id;   
    }                                                               

    /**
     * @return the id
     */
    public String getId() {
        return id;
    }

    /**
     * @param id the id to set
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * @return the radio
     */
    public double getRadio() {
        return radio;
    }

    /**
     * @param radio the radio to set
     */
    public void setRadio(double radio) {
        this.radio = radio;
    }
    
    public double area(){
        return PI*radio*radio;
    }
    
    public double perimetro(){
        return 2*PI*radio;
    }
}

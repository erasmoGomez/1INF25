/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package segundoproyecto;

/**
 *
 * @author hecto
 */
public class SegundoProyecto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Persona persona;
        Persona persona1;
        Persona persona2;
        
        //Antes de usar un objeto en java debemos siempre darles memoria
        
        persona = new Persona(2008206, "Erasmo Montoya", 1.5, true, 'M');
        
        System.out.println("Persona:> ");
        persona.imprimir();
        
        persona2 = persona;
        persona2.imprimir();
        persona.setDni(666666666);
        persona2.setDni(1111);
        persona2.imprimir();
        persona.imprimir();
    }
    
}

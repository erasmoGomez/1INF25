/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package primerproyecto;

/**
 *
 * @author hecto
 */
public class PrimerProyecto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int codigo = 20082060;
        double peso = 104.5;
        String nombre;
        nombre = "Erasmo Montoya";
        boolean tienePerro;
        tienePerro = true;
        
        System.out.println("Los datos del profesor son: ");
        System.out.println("El nombre del profesor es: " + nombre);
        System.out.println("Los demasdatos son:");
        System.out.print(codigo);
        System.out.print("      ");
        System.out.println(peso + "kg.");
    }
    
}

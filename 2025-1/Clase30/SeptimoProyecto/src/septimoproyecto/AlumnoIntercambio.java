/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package septimoproyecto;
import java.util.ArrayList;
import java.util.Scanner;
/**
 *
 * @author hecto
 */
public class AlumnoIntercambio extends Alumno {

    private String paisDeOrigen;
    private ArrayList<String> idiomas;
    private int numeroDeSemestres;

    //Japon Japones Italiano France 2
    public AlumnoIntercambio() {
        idiomas = new ArrayList<String>();
    }

    @Override
    public void leerDatos(Scanner arch) {
        super.leerDatos(arch);
        //Austria Aleman Ingles Castellano Frances Italiano 1
        String idioma;
        paisDeOrigen = arch.next();
        while (!arch.hasNextInt()) { //Mientras no venga un entero en el siguiente valor
            idioma = arch.next();
            this.idiomas.add(idioma);
        }
        numeroDeSemestres = arch.nextInt();
    }

    @Override
    public void imprimeDatos() {
        super.imprimeDatos();
        System.out.println("Alumno de Intercambio");
        System.out.println("Pais:    " + paisDeOrigen);
        System.out.print("Idiomas:");
        System.out.print(idiomas.size());

        for (String id : idiomas) {
            System.out.print(" " + id);
        }
        System.out.println();
        System.out.println("Permanecera: " + numeroDeSemestres + " Semestres");
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package octavoproyecto;

import java.io.FileNotFoundException;

/**
 *
 * @author Erasmo G. Montoya
 */
public class OctavoProyecto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        // TODO code application logic here
        ListaDeAlumnos listaAlumnos = new ListaDeAlumnos();
        listaAlumnos.leerAlumnos();
        listaAlumnos.listarAlumnos();
    }

}

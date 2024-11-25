/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package quintoproyecto;

/**
 *
 * @author Erasmo G. Montoya
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class ListaDePersonas {

    private ArrayList<Persona> listaDePersonas;

    public ListaDePersonas() {
        listaDePersonas = new ArrayList<Persona>();
    }

    public void leerPersonas() throws FileNotFoundException {
        File archivo = new File("personal.txt");
        Scanner arch = new Scanner(archivo);

        while (arch.hasNext()) {
            Persona persona = new Persona(); //Reservr memoria
            persona.leeDatos(arch);
            listaDePersonas.add(persona); // Agregar al arraylist
        }
    }

    public void mostrarPersonas() {
        for (Persona per : listaDePersonas) // Foreach
        {
            per.imprimeDatos();
        }
    }
}

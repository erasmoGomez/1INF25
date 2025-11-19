/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;

/**
 *
 * @author hecto
 */
public class CuartoProyecto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        ListaPersonas personas = new ListaPersonas(); //Reserva de Memoria
        personas.leer();
        personas.imprimir();
    }

}
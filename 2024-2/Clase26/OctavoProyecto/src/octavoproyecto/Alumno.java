/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package octavoproyecto;

import java.util.Scanner;

/**
 *
 * @author Erasmo G. Montoya
 */
class Alumno {

    private int codigo;
    private String nombre;

    void leerDatos(Scanner arch) {
        //20160658 Arca/Amezquita/Edric-Ronald
        codigo = arch.nextInt();
        nombre = arch.next();
    }

    // Metodo polimorfico
    public void imprimeDatos() {
        //System.out.println("=====================================================");
        imprimeLinea('=', 53);
        System.out.println("Codigo del alumno: " + codigo);
        System.out.println("Nombre del alumno: " + nombre);
    }

    public void imprimeLinea(char c, int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(c);
        }
        System.out.println();
    }
}

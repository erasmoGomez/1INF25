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
public class AlumnoRegular extends Alumno {

    private String especialidad;
    private String facultad;

    public AlumnoRegular() {
    }

    @Override
    void leerDatos(Scanner arch) {
        super.leerDatos(arch);
        especialidad = arch.next();
        facultad = arch.next();
    }

    @Override
    public void imprimeDatos() {
        super.imprimeDatos(); //Llama a la clase Padre
        System.out.println("Alumno Regular");
        System.out.println("Especialidad: " + especialidad);
        System.out.println("Facultad:   " + facultad);
    }
}

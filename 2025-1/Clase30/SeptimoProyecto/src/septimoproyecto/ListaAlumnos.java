/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package septimoproyecto;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Erasmo G. Montoya
 */
class ListaDeAlumnos {

    private ArrayList<Alumno> listaDeAlumnos;

    public ListaDeAlumnos() {
        listaDeAlumnos = new ArrayList<Alumno>();
    }

    void leerAlumnos() throws FileNotFoundException{
        File archivo = new File("Alumnos.txt");
        Scanner arch = new Scanner(archivo);
        String tipoAlumno;
        Alumno alumno;
        while (arch.hasNext()) {
            tipoAlumno = arch.next(); //"R" o "I"
            if (tipoAlumno.compareTo("R") == 0) {
                alumno = new AlumnoRegular();
            } else {
                alumno = new AlumnoIntercambio();
            }
            alumno.leerDatos(arch);
            //agregaAlumno(alumno);
            listaDeAlumnos.add(alumno);
        }
        arch.close();
    }

    void listarAlumnos() {
        for (Alumno al : listaDeAlumnos) {
            al.imprimeDatos(); //Polimorfismo
        }
    }
}

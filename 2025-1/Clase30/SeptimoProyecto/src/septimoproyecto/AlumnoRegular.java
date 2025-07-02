/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package septimoproyecto;
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
    public void leerDatos(Scanner arch) {
        //R 20160658 Arca/Amezquita/Edric-Ronald Ingenieria_Mecanica FCI
        super.leerDatos(arch);
        setEspecialidad(arch.next());
        setFacultad(arch.next());
    }

    @Override
    public void imprimeDatos() {
        super.imprimeDatos(); //Llama a la clase Padre
        System.out.println("Alumno Regular");
        System.out.println("Especialidad: " + getEspecialidad());
        System.out.println("Facultad:   " + getFacultad());
    }

    /**
     * @return the especialidad
     */
    public String getEspecialidad() {
        return especialidad;
    }

    /**
     * @param especialidad the especialidad to set
     */
    public void setEspecialidad(String especialidad) {
        this.especialidad = especialidad;
    }

    /**
     * @return the facultad
     */
    public String getFacultad() {
        return facultad;
    }

    /**
     * @param facultad the facultad to set
     */
    public void setFacultad(String facultad) {
        this.facultad = facultad;
    }
}


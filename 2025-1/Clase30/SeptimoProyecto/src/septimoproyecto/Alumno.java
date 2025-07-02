/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package septimoproyecto;
import java.util.Scanner;
/**
 *
 * @author hecto
 */
class Alumno {

    private int codigo;
    private String nombre;

    void leerDatos(Scanner arch) {
        //20160658 Arca/Amezquita/Edric-Ronald
        setCodigo(arch.nextInt());
        setNombre(arch.next());
    }

    // Metodo polimorfico
    public void imprimeDatos() {
        //System.out.println("=====================================================");
        imprimeLinea('=', 53);
        System.out.println("Codigo del alumno: " + getCodigo());
        System.out.println("Nombre del alumno: " + getNombre());
    }

    public void imprimeLinea(char c, int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(c);
        }
        System.out.println();
    }

    /**
     * @return the codigo
     */
    public int getCodigo() {
        return codigo;
    }

    /**
     * @param codigo the codigo to set
     */
    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    /**
     * @return the nombre
     */
    public String getNombre() {
        return nombre;
    }

    /**
     * @param nombre the nombre to set
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
}
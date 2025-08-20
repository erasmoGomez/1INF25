package l10;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author erasmo
 */
class Cafeteria {
    private final ArrayList<Pais> paises;
    private final ArrayList<Alumno> participantes;
    private final Menu menu;

    private final Scanner archivo;
    
    public Cafeteria() {
        paises = new ArrayList<>();
        participantes = new ArrayList<>();
        menu = new Menu();
        archivo = new Scanner(System.in);
    }
    
    public Cafeteria(final String nombreArchivo) throws FileNotFoundException {
        paises = new ArrayList<>();
        participantes = new ArrayList<>();
        menu = new Menu();
        archivo = new Scanner(new File(nombreArchivo));
    }
    
    public void cargarPaises() {
        while (archivo.hasNext()) {
            char tipo = archivo.next().charAt(0);
            if (!(tipo == 'I' || tipo == 'N')) break;
            
            Pais pais = new Pais();
            pais.cargar(archivo);
            paises.add(pais);
        }
    }
    
    public void cargarParticipantes() {
        while (archivo.hasNext()) {
            String tipo = archivo.next();
            if (tipo.equals("FIN")) break;
            
            Alumno alumno = tipo.equals("I") ? new AlumnoIntercambio() : new AlumnoRegular();
            alumno.cargar(archivo);
            participantes.add(alumno);
        }
    }
    
    public void cargarMenu() {
        menu.cargarProductos(archivo);
    }
    
    public void imprimirPaises() {
        System.out.println("==================LISTADO DE PAISES===================");
        System.out.println("------------------------------------------------------");
        System.out.println(String.format("%-15s\t%-10s\t%-10s\t%-10s", "NOMBRE", "MONEDA", "TIPO-CAMBIO", "IDIOMA"));
        System.out.println("------------------------------------------------------");
        for (Pais pais : paises) {
            pais.imprimir();
        }
        System.out.println("======================================================");
        System.out.println();
    }
    
    public void imprimirParticipantes() {
        System.out.println("====================================================================================LISTADO DE PARTICIPANTES=================================================================================");
        System.out.println("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
        System.out.println(String.format("%-10s\t%-35s\t%-15s\t%-30s\t%-15s\t%-50s\t%-15s", "CÓDIGO", "NOMBRE", "FACULTAD", "ESPECIALIDAD", "PAÍS", "IDIOMAS", "DURACIÓN"));
        System.out.println("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
        for (Alumno alumno : participantes) {
            alumno.imprimir();
        }
        System.out.println("=============================================================================================================================================================================================");
        System.out.println();
    }
    
    public void imprimirMenuPredeterminado() {
        menu.imprimirMenu();
        System.out.println();
    }
    
    public void imprimirMenusPersonalizados() {
        for (Alumno alumno : participantes) {
            Pais pais = buscarPais(alumno.getPaisDeOrigen());
            menu.imprimirMenuPersonalizado(alumno, pais);
            System.out.println();
        }
    }
    
    private Pais buscarPais(String nombre) {
        for (Pais pais : paises) {
            if (pais.getNombre().equals(nombre)) {
                return pais;
            }
        }
        
        return paises.get(0);
    }
}
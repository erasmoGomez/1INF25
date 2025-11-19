/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author hecto
 */
public class ListaPersonas {

    private ArrayList<Persona> personas;

    public ListaPersonas() {
        personas = new ArrayList<Persona>();
    }

    public void leer() throws IOException{
        Scanner input = crearScannerEntrada("personal.txt");

        while(input.hasNext()){
            Persona persona = new Persona(); //Tiene que tener reserva de memoria
            persona.leer(input);
            personas.add(persona); //Agregarlo al arraylist
        }
        input.close();
    }

    public void imprimir() throws IOException{
        FileWriter output = crearFileWriterSalida("reporte.txt");
        for(Persona p: personas){
            p.imprimir(output);
        }
        output.close();
    }

    public static Scanner crearScannerEntrada(String nombreArchivo) throws IOException {
        File archivo = new File(nombreArchivo);
        if (!archivo.exists()) {
            throw new IOException("Archivo no encontrado: " + nombreArchivo);
        }
        return new Scanner(archivo);
    }

    public static FileWriter crearFileWriterSalida(String nombreArchivo) throws IOException {
        File archivo = new File(nombreArchivo);
        if (!archivo.exists()) {
            archivo.createNewFile();
        }
        return new FileWriter(archivo);
    }
}
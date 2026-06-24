import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class ListaPersonas {
    private ArrayList<Persona> personas;

    public ListaPersonas() {
        personas = new ArrayList<Persona>();
    }

    public void leer() throws IOException {
        Scanner input = crear_scanner_entrada("personal.txt");
        while(input.hasNext()){
            Persona persona = new Persona();
            persona.leer(input);
            personas.add(persona);
        }
        input.close();
    }

    public void imprimir() throws IOException {
        FileWriter output = crear_filewriter_salida("reporte.txt");
        for(Persona persona : personas){
            //System.out.println(persona.getNombre());
            persona.imprimir_archivo(output);
        }
        output.close();
    }
    public Scanner crear_scanner_entrada(String file_name) throws IOException {
        File file = new File(file_name);
        if(!file.exists()){
            throw new IOException("No existe el archivo " + file_name);
        }
        return new Scanner(file);
    }

    public static FileWriter crear_filewriter_salida(String file_name) throws IOException {
        File file = new File(file_name);
        if(!file.exists()) file.createNewFile();
        return new FileWriter(file);
    }


}

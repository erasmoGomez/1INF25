import java.util.ArrayList;
import java.util.Scanner;

class ListaDePersonas{
	private ArrayList <Persona> listaDePersonas;
	
	public ListaDePersonas(){
		listaDePersonas = new ArrayList<Persona>();
	}
	
	public void leerPersonas(){
		Scanner arch = new Scanner(System.in);
		
		while(arch.hasNext()){
			Persona persona = new Persona(); //Reservr memoria
			persona.leeDatos(arch);
			listaDePersonas.add(persona); // Agregar al arraylist
		}
	}
	
	public void mostrarPersonas(){
		for(Persona per: listaDePersonas) // Foreach
			per.imprimeDatos();
	}
}
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
			Persona persona = new Persona();
			persona.leeDatos(arch);
			listaDePersonas.add(persona);
		}
	}
	
	public void mostrarPersonas(){
		for(Persona per: listaDePersonas) 
			per.imprimeDatos();
	}
}
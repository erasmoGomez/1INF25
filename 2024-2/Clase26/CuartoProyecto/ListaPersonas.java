import java.util.ArrayList;
import java.util.Scanner;
class ListaPersonas{
	private ArrayList <Persona> personas;

	public ListaPersonas(){
		personas = new ArrayList<Persona>();
	}

	public void leer(){
		Scanner input = new Scanner(System.in);

		while(input.hasNext()){
			Persona persona = new Persona();
			persona.leer(input);
			personas.add(persona);
		}
	}

	public void imprimir(){
		for (Persona persona:personas)//Foreach
			persona.imprimir();
	}
}
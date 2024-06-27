import java.util.Scanner;

class RedireccionamientoConClase{
	public static void main(String arg[]){
		Scanner arch = new Scanner(System.in);
		
		
		while(arch.hasNext()){
			Persona persona = new Persona();
			persona.leeDatos(arch);
			persona.imprimeDatos();
		}
	}
}
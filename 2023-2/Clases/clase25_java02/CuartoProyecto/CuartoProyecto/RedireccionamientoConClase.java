import java.util.Scanner;

class RedireccionamientoConClase{
	public static void main(String arg[]){
		Scanner arch = new Scanner(System.in);
		
		Persona persona = new Persona();
		while(arch.hasNext()){
			persona.leeDatos(arch);
			persona.imprimeDatos();
		}
	}
}

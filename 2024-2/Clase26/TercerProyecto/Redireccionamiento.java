import java.util.Scanner;

class Redireccionamiento{
	public static void main(String[]arg){
		Scanner input = new Scanner(System.in); //Permite el redireccionamiento de la entrada de datos
		int dni;
		String nombre;
		String buffer;
		char sexo;
		double sueldo;

		//37870823  M SAENZ_ARANDA_WILMER  23455.60
		//Leyendo un archivo hasta el fin del mismo
		while(input.hasNext()){
			dni = input.nextInt();
			buffer = input.next();
			sexo = buffer.charAt(0);
			nombre = input.next();
			sueldo = input.nextDouble();

			System.out.println(dni + " - " + nombre + " - " + sueldo + " - " + sexo);
	
		}
	}
}
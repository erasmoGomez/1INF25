import java.util.Scanner;

class RedireccionamientoES{ // Puede usarse cualquier nombre, pero debe entenderse que es el principal 
	public static void main(String arg[]){
		Scanner arch = new Scanner(System.in);  //Permite el redireccionamiente de la Entrada de datos
		int dni;
		String nombre;
		String palabra;
		char sexo;
		double sueldo;
		while(arch.hasNext()){
			//37870823  M SAENZ_ARANDA_WILMER  23455.60
			dni = arch.nextInt();
			palabra = arch.next(); // "M"
			sexo = palabra.charAt(0);
			nombre = arch.next();
			sueldo= arch.nextDouble();
			
			System.out.println(dni + "   " + sexo + "   " + sueldo + "   " + nombre);
		}
	}
}
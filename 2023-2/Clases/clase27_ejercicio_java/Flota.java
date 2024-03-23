import java.util.ArrayList;
import java.util.Scanner;

public class Flota{
	private ArrayList <Vehiculo> vehiculos;

	public void cargar_flota(){
		Scanner input = new Scanner(System.in);
		String cadena;
		while(input.hasNext()){
			cadena = input.next();
			Vehiculo v;
			if(cadena.compareTo("F") == 0)
				v = new Furgon();
			else
				v = new Camion();

			v.leer(input);
			vehiculos.add(v);
		}
	}
}
import java.util.ArrayList;

class Camion extends Vehiculo{
	private int ejes;
	private int llantas;
	private ArrayList <Pedido> pedidos;

	@Override
	public void leer(Scanner input){
		super.leer(input);
		this.ejes = input.nextInt();
		this.llantas = input.nextInt();
		this.cadena = input.next();
		String arr[] = cadena.split(".");
	}
}
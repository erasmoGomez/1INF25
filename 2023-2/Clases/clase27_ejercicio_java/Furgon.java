class Furgon extends Vehiculo{
	private int filas;
	private int puertas;
	private ArrayList <Pedido> pedidos; 

	@Override
	public void leer(Scanner input){
		super.leer(input);
		this.filas = input.nextInt();
		this.puertas = input.nextInt();
	}
}
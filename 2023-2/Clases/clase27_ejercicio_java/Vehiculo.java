abstract public class Vehiculo{
	private int id;
	private String placa;
	private double maxcarga;
	private double actcarga;
	
	public Vehiculo(){
		this.actcarga = 0;
	}
	//Funcion poliformica
	// 79464412 K0D-676 300
	public void leer(Scanner input){
		this.id = input.nextInt();
		this.placa = input.next();
		this.maxcarga = input.nextDouble();
		this.actcarga = 0;
	}
}
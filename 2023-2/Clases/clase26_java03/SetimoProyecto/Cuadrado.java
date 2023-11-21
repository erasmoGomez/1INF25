class Cuadrado extends Figura{
	public Cuadrado(String identificacion, double base, double altura){
		super(identificacion, base, altura);
	}
	
	@Override
	public void calcularArea(){
		System.out.println("Figura: Cuadrado (" + identificacion + ")");
		System.out.println("Formula = Base x Altura");
		System.out.println("Area = "+ base*altura);		
	}
}

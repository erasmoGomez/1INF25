class Cilindro extends Circulo{
	private double altura;

	public Cilindro(String identificacion, double radio, double altura){
		//Circulo(String identificacion, double radio)
		super(identificacion,radio); //Metodo super q llama al cnsructr de la clase base
		this.altura = altura;
	}

	public void setAltura(double altura){
		this.altura = altura;
	}
	public double getAltura(){
		return this.altura;
	}

	@Override
	public double area(){
		return 2*super.area() + perimetro()*altura;
	}

	public double areaDeLaBase(){
		return super.area();
	}

	public double volumen(){
		return super.area()*altura;
	}
}
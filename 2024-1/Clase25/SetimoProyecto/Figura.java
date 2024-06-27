abstract public class Figura{
	private String identificacion;
	private double base;
	private double altura;
	
	public Figura(String identificacion, double base, double altura){
		this.identificacion = identificacion;
		this.base = base;
		this.altura = altura;
	}
	
	public void setIdentificacion(String identificacion){
		this.identificacion = identificacion;
	}

	public String getIdentificacion(){
		return this.identificacion;
	}

	public void setBase(double base){
		this.base = base;
	}

	public double getBase(){
		return this.base;
	}

	public void setAltura(double altura){
		this.altura = altura;
	}

	public double getAltura(){
		return this.altura;
	}

	abstract public void calcularArea(); //Metod Polimorfico
	

}
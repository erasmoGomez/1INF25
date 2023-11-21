abstract public class Figura{
	public String identificacion;
	public double base;
	public double altura;
	
	public Figura(String identificacion, double base, double altura){
		this.identificacion = identificacion;
		this.base = base;
		this.altura = altura;
	}
	
	public abstract void calcularArea();
	
}
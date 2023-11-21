import java.util.ArrayList;
class Polimorfismo{
	public static void main(String [] args){
		Cuadrado c1 = new Cuadrado("C01",45.67,25.99);
		Cuadrado c2 = new Cuadrado("C02",10.71, 9.35);
		Cuadrado c3 = new Cuadrado("C03",5.97,2.19);
		Triangulo t1 = new Triangulo("T01", 43.23, 27.53);
		Triangulo t2 = new Triangulo("T02", 11.57, 7.47);
		
		ArrayList <Figura> figuras = new ArrayList<>();
		figuras.add(c3);
		figuras.add(t1);
		figuras.add(c1);
		figuras.add(t2);
		figuras.add(c2);
		for(Figura f: figuras){
			f.calcularArea();
			System.out.println();
		}
	}
	
}
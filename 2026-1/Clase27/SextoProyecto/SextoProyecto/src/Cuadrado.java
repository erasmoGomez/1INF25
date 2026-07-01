public class Cuadrado extends Figura{

    public Cuadrado(String id, double base, double altura) {
        super(id, base, altura);
    }

    @Override
    public void area(){
        System.out.println("Area del Cuadrado es: " + getBase()*getAltura());
    }
}
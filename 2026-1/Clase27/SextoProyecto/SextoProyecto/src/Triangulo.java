public class Triangulo extends Figura{

    public Triangulo(String id, double base, double altura) {
        super(id, base, altura);
    }

    @Override
    public void area(){
        System.out.println("Area del Triangulo es: " + (getBase()*getAltura())/2);
    }
}
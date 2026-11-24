public class Cilindro extends Circulo{ // herencia!

    private double altura;

    public Cilindro(String id, double radio, double altura){
        super(id, radio); //Llama directamente al metodo constructor del padre.
        this.altura = altura;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    @Override
    public double area(){ //area del hijo
        return 2*altura*super.area()*super.perimetro();
    }

    public double area_base(){
        return super.area();
    }

    public double volumen(){
        return super.area()*altura; // LLama al area del padre.
        // return area()*altura; // LLama al area del hijo
    }
}
public class Circulo {
    private String id;
    private double radio;
    private final double PI = 3.131592; // CONSTANTE PI

    public Circulo() {

    }

    public Circulo(String id, double radio) {
        this.id = id;
        this.radio = radio;
    }

    public Circulo(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public double getRadio() {
        return radio;
    }

    public void setRadio(double radio) {
        this.radio = radio;
    }

    public double area() {
        return PI * radio * radio;
    }

    public double perimetro() {
        return 2 * PI * radio;
    }
}
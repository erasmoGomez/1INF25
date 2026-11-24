
public class QuintoProyecto {
    public static void main(String[] args) {
        // TODO code application logic here
        Circulo circulo = new Circulo("Circulo A", 55.6);
        System.out.println("Perimetro : " + circulo.perimetro());
        Cilindro cilindro = new Cilindro("Cilindro B", 24.6, 32.1);
        System.out.println("Area : " + cilindro.area());
        System.out.println("Volumen : " + cilindro.volumen());
    }

}
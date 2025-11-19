import java.util.ArrayList;

/**
 *
 * @author hecto
 */
public class SextoProyecto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Cuadrado c1 = new Cuadrado("C1", 10, 12);
        Cuadrado c2 = new Cuadrado("C2", 10.5, 12.5);
        Cuadrado c3 = new Cuadrado("C3", 9.5, 11.5);
        Triangulo t1 = new Triangulo("T1", 5, 10);
        Triangulo t2 = new Triangulo("T2", 10, 5);

        ArrayList<Figura> figuras = new ArrayList<Figura>();

        figuras.add(c1);
        figuras.add(c2);
        figuras.add(c3);
        figuras.add(t1);
        figuras.add(t2);

        for(Figura f: figuras){
            f.area();
            System.out.println();
        }
    }
}
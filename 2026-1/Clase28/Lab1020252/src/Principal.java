import java.io.FileNotFoundException;
import java.util.ArrayList;


public class Principal {
    public static void main(String[] args) throws FileNotFoundException {
//        PlataformaStreaming plataforma = new PlataformaStreaming("datos.txt");
//        plataforma.cargarDatos();
//        plataforma.imprimirReporte();
        ArrayList<String> nombres = new ArrayList<String>();
        nombres.add("Juan");
        nombres.add("Maria");
        nombres.add("Pedro");
        nombres.add("Ana");
        nombres.add("Erasmo");
        nombres.sort(null);
        System.out.println(nombres.toString());
        System.out.println(nombres.reversed().toString());

        ArrayList<Persona> personas = new ArrayList<Persona>();
        Persona p = new Persona(123, "Erasmo");
        personas.add(p);
        Persona p2 = new Persona(111, "Ana");
        personas.add(p2);
        Persona p3 = new Persona(122, "Zoila");
        personas.add(p3);
        Persona p4 = new Persona(101, "Pedro");
        personas.add(p4);

        //personas.sort((x,y)->Integer.compare(x.getId(), y.getId()));
        personas.sort((x,y)->String.CASE_INSENSITIVE_ORDER.compare(x.getNombreCompleto(), y.getNombreCompleto()));

        for(Persona pp:personas){
            System.out.println(pp.getId() + " " + pp.getNombreCompleto());
        }

    }
}
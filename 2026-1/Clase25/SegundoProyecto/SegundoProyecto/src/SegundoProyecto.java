public class SegundoProyecto {
    public static void main(String[] args) {
        Persona persona;
        persona = new Persona();
        Persona persona1 = new Persona("Erasmo",
                                       "Gomez",
                                                33);
        System.out.println("Imprimiendo los datos de la persona:");
        persona1.imprimir();

        persona1.setSexo('M');
        persona1.setEstado(true);
    }
}

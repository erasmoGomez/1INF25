public class SegundoProyecto {
    public static void main(String[] args) {
        Persona persona;
        Persona persona1;
        Persona persona2;

        //Antes de usar un objeto persona que tenemos que hace?
        persona = new Persona();
        //int dni, String nombre, String apellido, double sueldo, boolean estado, char sexo) {
        persona1 = new Persona(20082060, "erasmo", "gomez", 1.5, true, 'M');
        System.out.println("Persona> ");
        persona1.imprimir();
        persona = persona1;
        persona.imprimir();
        persona1.setDni(666666);
        persona.setDni(11111);
        persona1.imprimir();
        persona.imprimir();
    }
}

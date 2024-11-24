class ClasesObjetos{
	public static void main(String[] arg){
		Persona persona;
		Persona persona1;
		Persona persona2;
		//Antes d usar un objeto debemos siempre instanciarlos
		persona = new Persona(22334455, "Erasmo Montoya", 1.5, true, 'M');
		System.out.print("Persona:> ");
		persona.imprimir();
		System.out.println();

		persona1 = new Persona();
		System.out.print("Persona 1:> ");
		persona1.set_dni(123456789);
		persona1.set_nombre("Ana Cecilia Roncal de Guanira");
		persona1.set_sueldo(5.5);
		persona1.set_activo(true);
		persona1.set_sexo('F');
		
		persona1.imprimir();
		System.out.println();

		//Ojo esto pasa siempre q no instancies memoria para el objeto
		persona2 = persona1;
		persona1.set_nombre("Rony Cueva");
		System.out.print("Persona 2:> ");
		persona1.imprimir();
		System.out.println();
		System.out.print("Persona 3:> ");
		persona2.imprimir();

	}
}
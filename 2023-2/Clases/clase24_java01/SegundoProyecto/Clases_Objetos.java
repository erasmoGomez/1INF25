class Clases_Objetos{ // Puede usarse cualquier nombre, pero debe entenderse que es el principal 
	public static void main(String arg[]){
		// Primero se debe crear los objetos
		Persona persona;
		Persona persona2;
		Persona persona3;
		
		// antes de usar el objeto hay que instanciarlo
		persona = new Persona(27345123,"Ana Cecilia Roncal Neyra", 'F', 4569.95,true);
		System.out.print("Persona:  ");
		persona.impimirDatos();
		System.out.println();
		
		persona2 = new Persona();
		persona2.setDni(27395711);
		persona2.setNombre("Juan Pedro Perez Ruiz");
		persona2.setSexo('M');
		persona2.setSueldo(3500.00);
		persona2.setActivo(true);
		System.out.print("Persona2: ");
		persona2.impimirDatos();
		System.out.println();
		
		// Tomar en cuenta esto que es muy importante
		persona3 = persona;
		persona3.setDni(11111111);
		System.out.print("Persona:  ");
		persona.impimirDatos();
		System.out.print("Persona3: ");
		persona3.impimirDatos();
		
		
	}
}

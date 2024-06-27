class Persona {
	private int dni;
	private String nombre;
	private char sexo;
	private double sueldo;
	private boolean activo;
	
	// CONSTRUCTORES
	public Persona(){
		sueldo = 0.0;
		activo = false;
	}
	public Persona(int dni, String nombre, char sexo, double sueldo, boolean activo){
		this.dni = dni;
		this.nombre = nombre;
		this.sexo = sexo;
		this.sueldo = sueldo;
		this.activo = activo;
	}
	
	// DESTRUCTOR
	// NO HAY DESTRUCTOR: PARA ESO ESTA EL RECOLECTOR DE BASURA
	
	public void impimirDatos(){
		System.out.println(dni + " - " + nombre + " - " + sexo + 
		                   " - " + sueldo + " - " + activo);
	}
	
	// MÉTODOS SELECTORES
	public void setDni(int dni){
		this.dni = dni;
	}
	
	public int getDni(){
		return dni;
	}
	
	public void setNombre(String nombre){
		this.nombre = nombre;
	}
	
	public String getNombre(){
		return nombre;
	}

	public void setSexo(char sexo){
		this.sexo = sexo;
	}
	
	public char getSexo(){
		return sexo;
	}
	
	public void setSueldo(double sueldo){
		this.sueldo = sueldo;
	}
	
	public double getSueldo(){
		return sueldo;
	}
	
	public void setActivo(boolean activo){
		this.activo = activo;
	}
	
	public boolean getActivo(){
		return activo;
	}
	
}
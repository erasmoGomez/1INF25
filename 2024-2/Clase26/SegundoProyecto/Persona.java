class Persona{
	private int dni;
	private String nombre;
	private double sueldo;
	private boolean activo;
	private char sexo;

	//Constructores
	public Persona(){
		sueldo = 0.0;
		activo = false;
	}

	public Persona(int dni, String nombre, double sueldo, boolean activo, char sexo){
		this.dni = dni;
		this.nombre = nombre;
		this.sueldo = sueldo;
		this.activo = activo;
		this.sexo = sexo;
	}

	//No necesitamos constructor copia ni destructores

	public void imprimir(){
		System.out.println(dni + " - " + nombre + " - " + sueldo + " - " + sexo + " - " + activo);
	}

	public int get_dni(){
		return dni;
	}

	public String get_nombre(){
		return nombre;
	}

	public double get_sueldo(){
		return sueldo;
	}

	public char get_sexo(){
		return sexo;
	}

	public boolean get_activo(){
		return activo;
	}

	public void set_dni(int dni){
		this.dni = dni;
	}

	public void set_nombre(String nombre){
		this.nombre = nombre;
	}

	public void set_sexo(char sexo){
		this.sexo = sexo;
	}
	
	public void set_sueldo(double sueldo){
		this.sueldo = sueldo;
	}

	public void set_activo(boolean activo){
		this.activo = activo;
	}
}
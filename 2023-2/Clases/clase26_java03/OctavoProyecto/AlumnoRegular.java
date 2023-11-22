import java.util.Scanner;

class AlumnoRegular extends Alumno{
	private String especialidad;
	private String facultad;
	
	public AlumnoRegular(){
		
	}	
		
	public String getEspecialidad(){
		return especialidad;
	}
	
	public void setEspecialidad(String especialidad){
		this.especialidad = especialidad;
	}
	
	public String getFacultad(){
		return facultad;
	}
	
	public void setFacultad(String facultad){
		this.facultad = facultad;
	}
	
	@Override
	public void leerDatos(Scanner arch){
		super.leerDatos(arch);
		especialidad = arch.next();
		facultad = arch.next();
	}
	
	@Override
	public void imprimeDatos(){
		super.imprimeDatos(); 
		System.out.println("Alumno Regular");
		System.out.println("Especialidad: " + especialidad);
		System.out.println("Facultadad:   " + facultad);
	}
	
}
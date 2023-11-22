import java.util.ArrayList;
import java.util.Scanner;

class ListaDeAlumnos {
	private ArrayList <Alumno> listaDeAlumnos;
	
	public ListaDeAlumnos(){
		listaDeAlumnos = new ArrayList <Alumno>();
	}
	
	public void agregaAlumno(Alumno al){
		listaDeAlumnos.add(al);
	}
	
	public void leerAlumnos(){
		Scanner arch = new Scanner(System.in);
		String tipoAlumno;
		Alumno alumno;
		while(arch.hasNext()){
			tipoAlumno = arch.next();
			if(tipoAlumno.compareTo("R")==0) 
				alumno = new AlumnoRegular();
			else 
				alumno = new AlumnoIntercambio();
			alumno.leerDatos(arch);
			listaDeAlumnos.add(alumno);
		}
	}
	
	public void listarAlumnos(){
		for(Alumno al: listaDeAlumnos) 
			al.imprimeDatos();
	}
	
}
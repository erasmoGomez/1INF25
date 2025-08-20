/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package l10;

import java.io.FileNotFoundException;

/**
 *
 * @author hecto
 */
public class L10 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        Cafeteria cafeteria = new Cafeteria("datos.txt");
        cafeteria.cargarPaises(); // 2 puntos
        cafeteria.imprimirPaises(); // 2 puntos
        
        cafeteria.cargarParticipantes(); // 3 puntos
        cafeteria.imprimirParticipantes(); // 2 puntos
        
        cafeteria.cargarMenu(); // 4 puntos
        cafeteria.imprimirMenuPredeterminado(); // 2 puntos
        cafeteria.imprimirMenusPersonalizados(); // 5 puntos
    }
    
}

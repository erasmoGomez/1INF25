/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package l10;

import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
abstract class Registro {

    abstract public void cargar(Scanner archivo);

    abstract public void imprimir();
}

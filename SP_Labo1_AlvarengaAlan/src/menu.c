/*
 * menu.c
 *
 *  Created on: Nov 4, 2021
 *      Author: Alan
 */
#include "menu.h"

void mostrarMenu (int* opciones) {

	printf ("\n\n-------------------MENU-------------------\n\n"
			"1) Leer perritos.csv (modo texto)\n"
			"2) Ordenar ascendentemente y listar perritos\n"
			"3) Calcular raciones\n"
			"4) Listar perritos con sus raciones\n"
			"5) Filtrar galgos\n"
			"6) Guardar en archivo de texto la lista de galgos\n"
			"7) Salir del programa\n\n");

			tomarInt (opciones,"Ingrese la opcion que deseas utilizar: ","ERROR. Has ingresado una opcion incorrecta. 1-7: ",1, 7);
}

/*
 * parser.h
 *
 *  Created on: Nov 5, 2021
 *      Author: Alan
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * @fn int parser_PerritosFromText(FILE*, LinkedList*)
 * @brief Funcion que se encarga de cargar los datos a la LinkedList desde el archivo csv de texto
 *
 * @param pFile Archivo donde se tomaran los archivos a cargar
 * @param pArrayListPerritos LinkedList donde se cargaran los datos
 * @return devuelve 1 si salio bien y 0 si salio mal
 */
int parser_PerritosFromText(FILE* pFile , LinkedList* pArrayListPerritos);



#endif /* SRC_PARSER_H_ */

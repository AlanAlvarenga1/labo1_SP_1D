#ifndef perrito_H_INCLUDED
#define perrito_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define maxChar 128

typedef struct {
	int id;
	char nombre[maxChar];
	float peso;
	char raza[maxChar];
	int edad;
	float racion;
}Perrito;

/**
 * @fn Perrito perrito_new*()
 * @brief Crea un espacio para el array de perrito en el malloc
 *
 * @return Retorna el puntero creado
 */
Perrito* perrito_new();
/**
 * @fn Perrito perrito_newParametros*(char*, char*, char*, char*)
 * @brief Toma ciertos parametros para añadirlos al perrito ya creado en el malloc
 *
 * @param idStr Parametro de ID a añadir
 * @param nombreStr Parametro de nombre a añadir
 * @param pesoStr Parametro de peso a añadir
 * @param edadStr Parametro de edad a añadir
 * @param razaStr Parametro de raza a añadir
 * @return Retorna al perrito con los datos ya cargados
 */
Perrito* perrito_newParametros(char* idStr,char* nombreStr,char* pesoStr,char* edadStr,char* razaStr);
/**
 * @fn int perrito_setId(Perrito*, int)
 * @brief Inserta un ID a un perrito determinado
 *
 * @param this Perrito al que se le insertara el parametro
 * @param id ID a insertar
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int perrito_setId(Perrito* this,int id);
/**
 * @fn int perrito_getId(Perrito*, int*)
 * @brief Obtiene el ID de un perrito
 *
 * @param this Perrito al que se le obtendra el ID
 * @param id  parametro que recibira el ID obtenido
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int perrito_getId(Perrito* this,int* id);
/**
 * @fn int perrito_setNombre(Perrito*, char*)
 * @brief Inserta un nombre a un perrito determinado
 *
 * @param this Perrito al que se le insertara el parametro
 * @param nombre Nombre a insertar
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int perrito_setNombre(Perrito* this,char* nombre);
/**
 * @fn int perrito_getNombre(Perrito*, char*)
 * @brief Obtiene el nombre de un perrito
 *
 * @param this Perrito al que se le obtendra el nombre
 * @param nombre parametro que recibira el nombre obtenido
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int perrito_getNombre(Perrito* this,char* nombre);
/**
 * @fn int perrito_setPeso(Perrito*, float)
 * @brief Inserta un peso a un perrito determinado
 *
 * @param this Perrito al que se le insertara el parametro
 * @param peso Parametro que se insertara
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int perrito_setPeso(Perrito* this,float peso);
/**
 * @fn int perrito_getPeso(Perrito*, float*)
 * @brief Obtiene el peso del perrito
 *
 * @param this Perrito al que se le obtendra el peso
 * @param peso Parametro que recibira el peso del perro
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int perrito_getPeso(Perrito* this,float* peso);
/**
 * @fn int perrito_setRaza(Perrito*, char*)
 * @brief Inserta la raza a un perrito determinado
 *
 * @param this Perrito al que se le insertara el parametro
 * @param raza Raza a insertar
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int perrito_setRaza(Perrito* this,char* raza);
/**
 * @fn int perrito_getRaza(Perrito*, char*)
 * @brief Obtiene la raza de un perrito
 *
 * @param this Perrito al que se le obtendra las horas
 * @param raza  parametro que recibira la raza obtenida
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int perrito_getRaza(Perrito* this,char* raza);
/**
 * @fn int perrito_setEdad(Perrito*, int)
 * @brief Inserta la edad a un perrito determinado
 *
 * @param this Perrito al que se le insertara el parametro
 * @param edad Edad a insertar
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int perrito_setEdad(Perrito* this,int edad);
/**
 * @fn int perrito_getEdad(Perrito*, int*)
 * @brief Obtiene la edad de un perrito
 *
 * @param this Perrito al que se le obtendra la edad
 * @param edad parametro que recibira la edad obtenida
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int perrito_getEdad(Perrito* this,int* edad);
/**
 * @fn int perrito_setRaciones(Perrito*, float)
 * @brief Inserta una racion a un perrito determinado
 *
 * @param this Perrito al que se le insertara el parametro
 * @param raciones Parametro que se insertara
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int perrito_setRaciones(Perrito* this,float raciones);
/**
 * @fn int perrito_getRaciones(Perrito*, float*)
 * @brief Obtiene la racion del perrito
 *
 * @param this Perrito al que se le obtendra la racion
 * @param raciones Parametro que recibira la racion del perro
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int perrito_getRaciones(Perrito* this,float* raciones);
/**
 * @fn void printUnPerrito(Perrito*)
 * @brief Imprime un perrito
 *
 * @param this Perrito a imprimir
 */
void printUnPerrito(Perrito* this);
/**
 * @fn void printUnPerritoConRaciones(Perrito*)
 * @brief Imprime un perrito con las raciones
 *
 * @param this Perrito a imprimir
 */
void printUnPerritoConRaciones(Perrito* this);

/**
 * @fn int perrito_orderName(void*, void*)
 * @brief Funcion que chequeara si las estructuras ingresadas tienen un nombre mayor, menor o iguales a la otra
 *
 * @param perritoOne primer perrito a comparar
 * @param perritoTwo segundo perrito a comprarar
 * @return retornara 1 si el primer perrito tiene un nombre mas alto, 0 si tienen el mismo nombre o -1 si el primer perrito tiene un nombre menor
 */
int perrito_orderName (void* perritoOne, void* perritoTwo);
/**
 * @fn int ePerrito_laQueMapea(void*)
 * @brief Calcula un valor y lo inserta a un parametro de una estructura
 *
 * @param perrito Estructura a la que se le insertara el valor
 * @return Retorna 1 si salio bien y 0 si salio mal
 */
int ePerrito_laQueMapea(void* perrito);
/**
 * @fn int ePerrito_laQueFiltra(void*)
 * @brief Filtra a los perros dependiendo de x parametro
 *
 * @param perrito Perrito al que se chequeara si cumple con los parametros
 * @return Si el perro cumple con los parametros devuelve 1 y si no 0
 */
int ePerrito_laQueFiltra(void* perrito);


#endif // perrito_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/** \brief Carga los datos de los perritos desde el archivo data.csv (modo texto).
 *
 * \param path char* ruta o nombre del archivo donde se cargaran los datos
 * \param pArrayListPerrito LinkedList* Lista a donde se volcaran los datos
 * \return int Devuelve 1 si salio bien o 0 si salio mal
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPerrito);
/**
 * @fn int controller_ListPerrito(LinkedList*)
 * @brief Lista la lista de perritos simple
 *
 * @param pArrayListPerrito Lista que contiene los perritos
 * @return retorna 0 si salio mal y 1 si salio bien
 */
int controller_ListPerrito(LinkedList* pArrayListPerrito);
/**
 * @fn int controller_ListPerritoConRaciones(LinkedList*)
 * @brief Lista la lista de perritos con las raciones
 *
 * @param pArrayListPerrito Lista que contiene los perritos
 * @return retorna 0 si salio mal y 1 si salio bien
 */
int controller_ListPerritoConRaciones(LinkedList* pArrayListPerrito);
/** \brief Guarda los datos de los perritos en el archivo data.csv (modo texto).
 *
 * \param pArrayListPerrito LinkedList* Lista a donde se guardaran los datos
 * \return int Devuelve 1 si salio bien o 0 si salio mal
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPerrito);



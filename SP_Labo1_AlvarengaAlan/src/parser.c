#include "LinkedList.h"
#include "Perritos.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los perritos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPerritos LinkedList*
 * \return int
 *
 */
int parser_PerritosFromText(FILE* pFile , LinkedList* pArrayListPerritos) {
	int retorno=0;
	char id[10];
	char nombre[51];
	char peso[10];
	char raza[51];
	char edad[10];


	if (pFile!=NULL && pArrayListPerritos!=NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,peso,edad,raza);
		while (feof(pFile)==0) {
			Perrito* unPerrito;
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,peso,edad,raza);

			unPerrito= perrito_newParametros(id,nombre,peso,edad,raza);

			if (feof(pFile)) {
				break;
			}

			if (unPerrito!=NULL) {
				ll_add(pArrayListPerritos, unPerrito);
			}
			unPerrito=NULL;
		}
		retorno=1;
	}
	return retorno;
}

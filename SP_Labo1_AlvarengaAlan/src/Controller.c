#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "input.h"
#include "menu.h"
#include "Perritos.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPerrito) {
	int retorno=0;
	FILE* pFile;

	if (path!=NULL && pArrayListPerrito!=NULL) {
		pFile= fopen(path,"r");

		if (parser_PerritosFromText(pFile , pArrayListPerrito)==1) {
			retorno=1;
		}
		fclose(pFile);
	}

    return retorno;
}

int controller_ListPerrito(LinkedList* pArrayListPerrito) {
    int llTam=ll_len(pArrayListPerrito);
	int i;
	Perrito* aux;

	if (pArrayListPerrito!=NULL) {

		printf ("------------------------------------------------------------------------------------------------------------------------------\n");
		printf ("%-10s %-25s %-25s %-25s %s","ID","Nombre","Peso","Edad","Raza");
		printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
		for (i=0;i<llTam;i++) {
    		aux=(Perrito*)ll_get(pArrayListPerrito,i);
    		printUnPerrito(aux);
		}
		printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
	}
	return 1;
}
int controller_ListPerritoConRaciones(LinkedList* pArrayListPerrito) {
    int llTam=ll_len(pArrayListPerrito);
	int i;
	Perrito* aux;

	if (pArrayListPerrito!=NULL) {

		printf ("------------------------------------------------------------------------------------------------------------------------------\n");
		printf ("%-10s %-25s %-25s %-25s %-25s %s","ID","Nombre","Peso","Edad","Raza","Raciones");
		printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
		for (i=0;i<llTam;i++) {
    		aux=(Perrito*)ll_get(pArrayListPerrito,i);
    		printUnPerritoConRaciones(aux);
		}
		printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
	}
	return 1;
}

int controller_saveAsText(char* path , LinkedList* this) {
    int retorno=0;
    FILE* pFile;
    int llTam=ll_len(this);
    Perrito* aux;

	int id;
	char nombre[maxChar];
	float peso;
	int edad;
	char raza[maxChar];
	float raciones;

    if (path!=NULL && this!=NULL) {
    	pFile=fopen(path,"w");

    	fprintf (pFile,"%s\n","id,nombre,peso,edad,raza,raciones");

    	for (int i=0;i<llTam;i++) {
    		aux=(Perrito*)ll_get(this,i);

    		perrito_getId(aux,&id);
    		perrito_getNombre(aux,nombre);
    		perrito_getPeso(aux,&peso);
    		perrito_getEdad(aux,&edad);
    		perrito_getRaza(aux,raza);
    		perrito_getRaciones(aux,&raciones);

        	fprintf (pFile,"%d,%s,%f,%d,%s,%f\n",id,nombre,peso,edad,raza,raciones);
    	}
    	fclose(pFile);
    	retorno=1;
   }

	return retorno;
}


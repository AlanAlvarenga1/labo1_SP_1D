#include "Perritos.h"

Perrito* perrito_new() {
	Perrito* perritoARetornar = NULL;
	perritoARetornar= (Perrito*) malloc (sizeof(Perrito));
	return perritoARetornar;
}

Perrito* perrito_newParametros(char* idStr,char* nombreStr,char* pesoStr,char* edadStr,char* razaStr) {
	Perrito* perrito = NULL;
	perrito= perrito_new();

	int id=atoi(idStr);
	int edad=atoi(edadStr);
	float peso=atof(pesoStr);

	perrito_setId(perrito,id);
	perrito_setNombre(perrito,nombreStr);
	perrito_setPeso(perrito,peso);
	perrito_setRaza(perrito,razaStr);
	perrito_setEdad(perrito,edad);

	return perrito;
}

int perrito_setId(Perrito* this,int id) {
	int retorno=0;
	if (this!=NULL) {
		this->id=id;
		retorno=1;
	}
	return retorno;
}
int perrito_getId(Perrito* this,int* id) {
	int retorno=0;
	if (this!=NULL) {
		*id=this->id;
		retorno=1;
	}
	return retorno;
}

int perrito_setNombre(Perrito* this,char* nombre) {
	int retorno=0;
	if (this!=NULL && nombre!=NULL) {
		strcpy(this->nombre, nombre);
		retorno=1;
	}
	return retorno;
}
int perrito_getNombre(Perrito* this,char* nombre) {
	int retorno=0;
	if (this!=NULL && nombre!=NULL) {
		strcpy(nombre,this->nombre);
		retorno=1;
	}
	return retorno;
}
int perrito_setPeso(Perrito* this,float peso) {
	int retorno=0;
	if (this!=NULL) {
		this->peso=peso;
		retorno=1;
	}
	return retorno;
}
int perrito_getPeso(Perrito* this,float* peso) {
	int retorno=0;

	if (this!=NULL) {
		*peso=this->peso;
		retorno=1;
	}
	return retorno;
}

int perrito_setRaza(Perrito* this,char* raza) {
	int retorno=0;
	if (this!=NULL && raza!=NULL) {
		strcpy(this->raza,raza);
		retorno=1;
	}
	return retorno;
}
int perrito_getRaza(Perrito* this,char* raza) {
	int retorno=0;
	if (this!=NULL && raza!=NULL) {
		strcpy(raza,this->raza);
		retorno=1;
	}
	return retorno;
}

int perrito_setEdad(Perrito* this,int edad) {
	int retorno=0;
	if (this!=NULL) {
		this->edad= edad;
		retorno=1;
	}
	return retorno;
}
int perrito_getEdad(Perrito* this,int* edad) {
	int retorno=0;
	if (this!=NULL) {
		*edad=this->edad;
		retorno=1;
	}
	return retorno;
}
int perrito_setRaciones(Perrito* this,float raciones) {
	int retorno=0;
	if (this!=NULL) {
		this->racion=raciones;
		retorno=1;
	}
	return retorno;
}
int perrito_getRaciones(Perrito* this,float* raciones) {
	int retorno=0;
	if (this!=NULL) {
		*raciones=this->racion;
		retorno=1;
	}
	return retorno;
}
void printUnPerrito(Perrito* this) {
	int id;
	char nombre[maxChar];
	float peso;
	int edad;
	char raza[maxChar];

	perrito_getId(this,&id);
	perrito_getNombre(this,nombre);
	perrito_getPeso(this,&peso);
	perrito_getEdad(this,&edad);
	perrito_getRaza(this,raza);

	printf ("%-10d %-25s %-25f %-25d %s\n",id,nombre,peso,edad,raza);
}
void printUnPerritoConRaciones(Perrito* this) {
	int id;
	char nombre[maxChar];
	float peso;
	int edad;
	char raza[maxChar];
	float raciones;

	perrito_getId(this,&id);
	perrito_getNombre(this,nombre);
	perrito_getPeso(this,&peso);
	perrito_getEdad(this,&edad);
	perrito_getRaza(this,raza);
	perrito_getRaciones(this,&raciones);

	printf ("%-10d %-25s %-25f %-25d %-25s %f\n",id,nombre,peso,edad,raza,raciones);
}


int perrito_orderName (void* perritoOne, void* perritoTwo) {
	int retorno;

	if (perritoOne!=NULL && perritoTwo!=NULL) {
		char perritoOne_Name[maxChar];
		char perritoTwo_Name[maxChar];
		perrito_getNombre(perritoOne,perritoOne_Name);
		perrito_getNombre(perritoTwo,perritoTwo_Name);

		retorno=strcmp(perritoOne_Name,perritoTwo_Name);
	}

	return retorno;
}

int ePerrito_laQueMapea(void* perrito) {
	int retorno=0;

	if (perrito!=NULL) {
		float calculoRaciones;
		float peso;

		perrito_getPeso(perrito,&peso);
		calculoRaciones=peso*23;
		perrito_setRaciones(perrito,calculoRaciones);

		retorno=1;
	}

	return retorno;
}
int ePerrito_laQueFiltra(void* perrito) {
	int retorno=0;
	char raza[maxChar];
	int edad;
	float racion;

	if (perrito!=NULL) {
		perrito_getRaza(perrito,raza);
		perrito_getEdad(perrito,&edad);
		perrito_getRaciones(perrito,&racion);

		if (strcmp(raza,"Galgo")==0 && edad>10 && racion<200) {
			retorno=1;
		}
	}

	return retorno;
}

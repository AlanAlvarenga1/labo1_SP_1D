#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "menu.h"
#include "Perritos.h"

/****************************************************
    NOTA: En mi pc no dejaba modificar el archivo dado
    en el rar del TP, por lo que en mi caso tenia que
    guardarlo como Binario, cargarlo de ese modo y dejar
    que se cree un nuevo archivo de texto, guardandolo
    de ese modo
*****************************************************/



int main()
{
	setbuf (stdout,NULL);

    int option = 0;
    int flagGeneral=0;//0=SIN CARGAR 1=CARGADO
    int flagMap=0;//0=RACIONES SIN CALCULAR 1=RACIONES CALCULADAS
    int flagFilter=0;//0=FILTRO SIN UTILIZAR 1=FILTRO USADO

    LinkedList* listaPerritos = ll_newLinkedList();
    LinkedList* listaGalgos;
    do{
    	mostrarMenu(&option);

        switch(option)
        {
            case 1:
            	if (flagGeneral==0) {
                    if (controller_loadFromText("perritos.csv", listaPerritos)==1) {
                    	flagGeneral=1;
                    	printf ("\n\nLa lista ha sido cargada satisfactoriamente\n");
                    }
                    else {
                    	printf ("\n\nHa ocurrido un error. Intente nuevamente\n");
                    }
            	}
            	else {
            		printf ("\n\nERROR. Ya has cargado la lista de perritos\n");
            	}
            	systemPause("Presiones ENTER para continuar");
                break;
            case 2:
            	if (flagGeneral!=0) {
            		ll_sort(listaPerritos, perrito_orderName, 1);
					controller_ListPerrito(listaPerritos);
            	}
            	else {
            		printf ("\n\nERROR. No has cargado ninguna lista. Vuelva a intentar mas tarde\n");
            	}
            	systemPause("Presiones ENTER para continuar");
            	break;
            case 3:
            	if (flagGeneral!=0) {
            		if(ll_map(listaPerritos, ePerrito_laQueMapea)==1) {
            			printf("\n\nSe han calculado las raciones correctamente");
            			flagMap=1;
            		}
            		else{
            			printf("\n\nERROR. Hubo un error en el calculo de las raciones");
            		}
            	}
            	else {
            		printf ("\n\nERROR. No has cargado ninguna lista. Vuelva a intentar mas tarde\n");
            	}
            	systemPause("Presiones ENTER para continuar");
            	break;
            case 4:
            	if (flagGeneral!=0) {
            		if (flagMap!=0) {
    					controller_ListPerritoConRaciones(listaPerritos);
            		}
            		else {
              			printf("\n\nERROR. No has calculado la cantidad de raciones");
            		}
            	}
            	else {
            		printf ("\n\nERROR. No has cargado ninguna lista. Vuelva a intentar mas tarde\n");
            	}

            	systemPause("Presiones ENTER para continuar");
            	break;
            case 5:
            	if (flagGeneral!=0) {
            		if (flagMap!=0) {
						listaGalgos=ll_filter(listaPerritos,ePerrito_laQueFiltra);
						if (listaGalgos!=NULL) {
							printf("\n\nSe han guardado los galgos en la LinkedList con exito\n");
							flagFilter=1;
						}
						else {
							printf("\n\nERROR. No se ha podido cargar la lista de galgos");
						}
            		}
            		else {
            			printf("\n\nERROR. No has calculado la cantidad de raciones\n");
            		}
            	}
            	else {
            		printf ("\n\nERROR. No has cargado ninguna lista. Vuelva a intentar mas tarde\n");
            	}
            	systemPause("Presiones ENTER para continuar");
            	break;
            case 6:
            	if (flagGeneral!=0) {
            		if (flagFilter!=0) {
            			controller_saveAsText("galgosFlaquitos.csv", listaGalgos);
            			printf("\n\nSe ha guardado el archivo con exito\n");
            		}
            		else {
            			printf ("\n\nERROR. No has cargado la lista de galgos\n");
            		}
            	}
            	else {
            		printf ("\n\nERROR. No has cargado ninguna lista. Vuelva a intentar mas tarde\n");
            	}
            	systemPause("Presiones ENTER para continuar");
            	break;
            case 7:
            	ll_deleteLinkedList(listaPerritos);
            	ll_deleteLinkedList(listaGalgos);
            	printf ("\n\nMuchas gracias por usar este programa!!");
            	break;
        }
    }while(option != 7);
    return 0;
}

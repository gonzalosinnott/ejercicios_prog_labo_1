/*
 ============================================================================
 Name        : clase_12a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Practica Examen
 ============================================================================
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "mi_biblioteca.h"
#include "pantalla.h"
#include "publicidad.h"


int main(void){

	int choosenOption;
	int firstLoad = FALSE;

	Pantalla arrayPantalla[QTY_PANTALLAS];
	Publicidad arrayPublicidades[QTY_PUBLICIDADES];

	initPantalla(arrayPantalla, QTY_PANTALLAS);
	initPublicidad(arrayPantalla, QTY_PANTALLAS);

	do
	{
		getMenu(&choosenOption);
		switch(choosenOption)
		{
			case 1://ALTA PANTALLA (LISTO)
				pantalla_alta(arrayPantalla, QTY_PANTALLAS, &firstLoad);
				break;
			case 2://MODIFICAR PANTALLA (LISTO)
				pantalla_modifyMenu(arrayPantalla, QTY_PANTALLAS,firstLoad);
				break;
			case 3://BAJA PANTALLA (AGREGAR BAJA DE CONTRATACIONES)
				pantalla_removeMenu(arrayPantalla, QTY_PANTALLAS, &firstLoad);
				break;
			case 4://CONTRATACION PUBLICIDAD !
				break;
			case 5://MODIFICAR CONTRATACION !
				break;
			case 6://CANCELAR CONTRATACION !
				break;
			case 7://CONSULTA FACTURACION !
				break;
			case 8://LISTAR CONTRATACIONES !
				break;
			case 9://LISTAR PANTALLAS !
				break;
			case 10://INFORME !
				break;

		}
	}while(choosenOption!=6);
	printf("PROGRAMA TERMINADO");
	return EXIT_SUCCESS;
}


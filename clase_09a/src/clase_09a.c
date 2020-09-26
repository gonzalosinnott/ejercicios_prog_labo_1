/*
 ============================================================================
 Name        : clase_09a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Estructuras
 ============================================================================
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "mi_biblioteca.h"
#include "alumno.h"

#define ARRAY_LEN 5

int main(void)
{
	int opcionIngresada;
	int indice;
	Alumno arrayAlumnos[ARRAY_LEN];

	alumno_initArray(arrayAlumnos,QTY_ALUMNOS);
	do
	{
		utn_getEntero("\nIngrese una opcion:"
					  "\n 1-Alta"
				      "\n 2-Modificar"
				      "\n 3-Baja"
				      "\n 4-Ordenar por nombre(EN CONSTRUCCION)"
				      "\n 5-Ordenar por Legajo"
				      "\n 6-Imprimir ingresos"
					  "\n 7-Salir"
				      "\nOpcion:",
					  "\nError",&opcionIngresada,2,7,1);
		switch(opcionIngresada)
		{
			case 1:
				if(indice < QTY_ALUMNOS)
				{
					do
					{
						if(arrayAlumnos[indice].isEmpty == TRUE)
						{
							alumno_alta(arrayAlumnos,QTY_ALUMNOS,indice);
						}
						else
						{
							indice++;
						}
					}while(arrayAlumnos[indice].isEmpty == FALSE);
				}
				else
				{
					printf("\nNO SE PUEDEN CARGAR MAS REGISTROS.\n");
				}
				break;
			case 2:
				if(utn_getEntero("\nIndice:","\nError",&indice,2,QTY_ALUMNOS-1,0) == 0)
				{
					alumno_modificar(arrayAlumnos,QTY_ALUMNOS,indice);
				}
				break;
			case 3:
				if(utn_getEntero("\nIndice:","\nError",&indice,2,QTY_ALUMNOS-1,0) == 0)
				{
					alumno_baja(arrayAlumnos,QTY_ALUMNOS,indice);
				}
				break;
			case 4:
				alumno_ordenarPorNombre(arrayAlumnos,QTY_ALUMNOS);
				break;
			case 5:
				alumno_ordenarPorLegajo(arrayAlumnos,QTY_ALUMNOS);
				break;
			case 6:
				alumno_imprimir(arrayAlumnos,QTY_ALUMNOS);
				break;
		}
	}while(opcionIngresada != 7);
	return EXIT_SUCCESS;
}


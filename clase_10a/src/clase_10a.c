/*
 ============================================================================
 Name        : clase_10a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Estructuras II (continuacion)
 5)Realizar una funcion que reciba el array y un indice,
 e imprima los datos del item de esa posicion, si es que tiene datos validos.
 6) Realizar una funcion que me devuelva el indice de un item vacio (sin cargar).
 7) Alta de alumno. -NO PEDIR INDICE-
 8) Agregar al tipo de dato el campo ID que represente un identificador unico.
 Modificar el codigo anterior para que el ID se genere automaticamente.
 Se debera cargar el ID automaticamente al cargar un alumno,
 y se debera imprimir al imprimir la lista
 9) Realizar una funcion que reciba el array y un ID,
 y me devuelva el indice del item con dicho ID. (buscar por id)
 10) Realizar una funcion que reciba el array, un indice,
 y le permita al usuario modificar los campos nombre y legajo del item
 del array en la posicion especificada por el indice.
 11) Agregar una opcion en el menu. "Editar alumno" que pida al usuario
 el ID del mismo y le permita cambiar el nombre y el legajo.
 12) Agregar una opcion en el menu "Borrar Alumno" que pida al usuario el ID del mismo.


 ============================================================================
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "mi_biblioteca.h"
#include "alumno.h"

int main(void)
{
	int opcionIngresada;
	int indiceVacio;
	int idModificar;
	int indice;
	int id;
	Alumno arrayAlumnos[QTY_ALUMNOS];


	alumno_initArray(arrayAlumnos,QTY_ALUMNOS);
	do
	{
		utn_getEntero("\nIngrese una opcion:"
					  "\n 1-Alta"
				      "\n 2-Modificar por Indice"
					  "\n 3-Modificar por Id"
				      "\n 4-Baja por Indice"
					  "\n 5-Baja por Id (TERMINAR)"
				      "\n 6-Ordenar por nombre(TERMINAR)"
				      "\n 7-Ordenar por Legajo(TERMINAR ASCENDENTE)"
				      "\n 8-Imprimir indice"
					  "\n 9-Imprimir todas las entradas"
					  "\n 10-Chequear primer indice vacio"
					  "\n 11-Consultar indice vacio"
				      "\n 12-Consulta ID"
				      "\n 13-Salir"
				      "\nOpcion:",
					  "\nError",&opcionIngresada,2,13,1);
		switch(opcionIngresada)
		{
			case 1:
				if(alumno_checkPrimerIndiceVacio(arrayAlumnos, QTY_ALUMNOS, &indiceVacio)==0)
				{
					alumno_alta(arrayAlumnos,QTY_ALUMNOS,indiceVacio);
				}
				else
				{
					printf("\nNO SE PUEDEN CARGAR MAS REGISTROS.\n");
				}
				break;
			case 2:
				if(utn_getEntero("\nIndice a modificar:","\nError, no es un indice valido.\n",&indice,2,QTY_ALUMNOS-1,0) == 0)
				{
					alumno_modificar(arrayAlumnos,QTY_ALUMNOS,indice, idModificar);
				}
				break;
			case 3:
				if(utn_getEntero("Ingrese el ID a modificar:","e!",&idModificar,5,1000,1)==0)
				{
					if(alumno_buscarId(arrayAlumnos, QTY_ALUMNOS, &indice, idModificar)==0)
					{
						alumno_modificar(arrayAlumnos,QTY_ALUMNOS,indice, idModificar);
					}
				}
				break;
			case 4:
				if(utn_getEntero("\nIndice a borrar:","\nError, no es un indice valido.\n",&indice,2,QTY_ALUMNOS-1,0) == 0)
				{
					alumno_baja(arrayAlumnos,QTY_ALUMNOS,indice);
				}
				break;
			case 5:
				break;
			case 6:
				alumno_ordenarPorNombre(arrayAlumnos,QTY_ALUMNOS);
				break;
			case 7:
				alumno_ordenarPorLegajo(arrayAlumnos,QTY_ALUMNOS);
				break;
			case 8:
				if(utn_getEntero("\nIndice a imprimir:","\nError, no es un indice valido.\n",&indice,2,QTY_ALUMNOS-1,0) == 0)
				{
					alumno_imprimirIndice(arrayAlumnos,QTY_ALUMNOS,indice);
				}
				break;
			case 9:
				alumno_imprimir(arrayAlumnos,QTY_ALUMNOS);
				break;
			case 10:
				alumno_listPrimerIndiceVacio(arrayAlumnos,QTY_ALUMNOS);
				break;
			case 11:
				if(utn_getEntero("\nIndice a chequear:","\nError",&indice,2,QTY_ALUMNOS-1,0) == 0)
				{
					alumno_listIndiceVacio(arrayAlumnos,QTY_ALUMNOS,indice);
				}
				break;
			case 12:
				if(utn_getEntero("\nID a chequear:","\nError, ese ID no fue utilizado todavia.",&id,2,QTY_ALUMNOS-1,0) == 0)
				{
					alumno_printById(arrayAlumnos,QTY_ALUMNOS,&id);
				}
				break;
		}
	}while(opcionIngresada != 13);
	return EXIT_SUCCESS;
}


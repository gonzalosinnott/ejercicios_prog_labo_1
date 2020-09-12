/*
 ============================================================================
 Name        : clase_06a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Ingresar un nunmero determinado de numeros
 1)Guardarlos en un array
 2)Impprimir el array desordenado
 3)Imprimir el array ordenado
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "mi_biblioteca.h"

#define CANTIDAD_ELEMENTOS 5
int printArray(int array[], int elementos);

int main(void)
{
	int numeroIngresado;
	int arrayInt[CANTIDAD_ELEMENTOS];

	for(int i = 0;i<CANTIDAD_ELEMENTOS;i++)
	{
		if(getEntero(&numeroIngresado, "\nIngrese un numero:", "Error, no es un numero.", 3)==0)
		{
			arrayInt[i] = numeroIngresado;
		}
	}

	printf("Array Desordenado:\n");
	printArray(arrayInt, CANTIDAD_ELEMENTOS);

	printf("\nArray Ordenado:\n");
	if(sortArrayEnteros(arrayInt, CANTIDAD_ELEMENTOS)==0)
	{
		printArray(arrayInt, CANTIDAD_ELEMENTOS);
	}
}





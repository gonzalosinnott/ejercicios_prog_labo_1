/*
 ============================================================================
 Name        : clase_08a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : 1) Se tiene el siguiente array de variables del tipo int
int numeros[12]={3,7,4,5,2,3,7,1,7,3,2,7};
Hacer una funcion que reciba el array y su tamaño, y lo imprima.
Escribir un programa para probar la funcion.
 ============================================================================
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "mi_biblioteca.h"

#define ARRAY_SIZE 12

int main(void){
	int numeros[ARRAY_SIZE]={3,7,4,5,2,3,7,1,7,3,2,7};

	if(utn_printArrayInt(numeros, ARRAY_SIZE)==0)
	{
		printf("FIN.");
	}
}



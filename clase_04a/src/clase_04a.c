/*
 ============================================================================
 Name        : clase_04a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Creacion de Bibliotecas
 ============================================================================
 */

// Tarea
// utn_getNumeroFloat() (1 float)
// utn_getChar() (1 caracter)

#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"

int main(void)
{
	int numeroEnteroIngresado;
	float numeroFloatIngresado;
	char letraIngresada;

	if(utn_getEntero(&numeroEnteroIngresado, 0, 100, "\nIngrese un numero entre 0 y 100:", "\nError, ingrese un numero entre 0 y 100.", 3)==0)
	{
		printf("\nEl numero ingresado es %d.", numeroEnteroIngresado);
	}

	if(utn_getFloat(&numeroFloatIngresado, 0, 100, "\nIngrese un numero con decimales entre 0 y 100:", "\nError, ingrese un numero con decimales entre 0 y 100.", 3)==0)
	{
		printf("\nEl numero ingresado es %f.", numeroFloatIngresado);
	}

	if(utn_getChar(&letraIngresada, "\nIngrese una letra:", "Error, no es una letra.", 3)==0)
	{
		printf("\nLa letra ingresada es %c.", letraIngresada);
	}

	return EXIT_SUCCESS;

}



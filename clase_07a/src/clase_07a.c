/*
 ============================================================================
 Name        : clase_07a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description :getString Funcion que pide una string
 	 	 	  getValidarNombre Funcion que valida los caracteres de un nombre
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "mi_biblioteca.h"

#define ARRAY_LEN 100

int main(void)
{
	char nombre[ARRAY_LEN];

	if(utn_getString("Ingrese su nombre: ", "Error, no es un nombre valido. ", nombre, 3, ARRAY_LEN-1) == 0)
	{
		printf("El nombre ingresado es: %s",nombre);
	}

	return EXIT_SUCCESS;

}





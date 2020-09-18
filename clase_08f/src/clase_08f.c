/*
 ============================================================================
 Name        : clase_08c.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description :6) Realizar un programa para probar la funcion del punto 5,
  permitiendo que el usuario ingrese un texto y luego validando si lo ingresado
   es un nombre válido. Usar scanf para tomar el texto.

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


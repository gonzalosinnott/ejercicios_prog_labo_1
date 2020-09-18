/*
 ============================================================================
 Name        : clase_08d.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description :4) Dada la siguiente cadena de caracteres:
 char nombre[8]={'p','e','p','e','1','2','3','\0'};
​
 Hacer una funcion que reciba el array y su tamaño,
 y cuente cuantas veces aparece la letra 'e'.
 Al terminar de contar, la funcion deberá imprimir por pantalla el valor contado.
Escribir un programa para probar la funcion.
 ============================================================================
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "mi_biblioteca.h"

#define ARRAY_SIZE 8



int main(void){
	char nombre[ARRAY_SIZE]={'p','e','p','e','1','2','3','\0'};
	int cantidadValorBuscado;
	char caracterBuscado = 'e';

	if(utn_getCantidadValorChar(&cantidadValorBuscado, nombre,caracterBuscado)== 0)
	{
		printf("Cantidad de veces que aparece el caracter %c: %d\n",caracterBuscado, cantidadValorBuscado);
	}
	else
	{
		printf("El elemento %c no se encuentra en la lista\n", caracterBuscado);
	}
	printf("FIN");
}


/*
 ============================================================================
 Name        : clase_08c.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description :5) Hacer una funcion que reciba el array del punto 4,
 y verifique que las letras dentro del mismo esten en el rango de 'a' a 'z'
 o de 'A' a 'Z'. Si estan dentro del rango la funcion deberá devolver por valor
 (usando el return) un 0, de lo contrario devolverá -1.

 ============================================================================
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "mi_biblioteca.h"

#define ARRAY_SIZE 8

int main(void){
	char nombre[ARRAY_SIZE]={'p','e','p','e','1','2','3','\0'};

	if(utn_getValidarArrayChar(nombre)== 0)
	{
		printf("Todos los caracteres son letras.\n");
	}
	else
	{
		printf("Hay elementos que no pertenecen al grupo de las letras.\n");
	}
	printf("FIN");
}



/*
 ============================================================================
 Name        : clase_08c.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description :3) Modificar la funcion del punto 2 para que NO imprima el valor contado,
  sino que lo devuelva por referencia (recibiendo la direccion de memoria de una variable
  donde escribirá el valor contado). Escribir un programa para probar la funcion.

 ============================================================================
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "mi_biblioteca.h"

#define ARRAY_SIZE 12

int main(void){
	int numeros[ARRAY_SIZE]={3,7,4,5,2,3,7,1,7,3,2,7};
	int valor;
	int valorBuscado = 7;

	if(utn_getCantidadValorInt(&valor, numeros, ARRAY_SIZE, valorBuscado)== 0)
	{
		printf("Cantidad de veces que aparece el numero 7: %d\n", valor);
	}
	else
	{
		printf("El elemento %d no se encuentra en la lista\n", valorBuscado);
	}
	printf("FIN");
}

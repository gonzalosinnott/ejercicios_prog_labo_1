/*
 ============================================================================
 Name        : clase_08b.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description :2) Hacer una funcion que reciba el array del punto 1 y su tamaño,
y cuente cuantas veces aparece el numero 7.
Al terminar de contar, la funcion deberá imprimir por pantalla el valor contado.
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
	int valor;
	int valorBuscado = 7;

	if(utn_getCantidadValorInt(&valor, numeros, ARRAY_SIZE, 7)== 0)
	{
		printf("Cantidad de veces que aparece el numero 7: %d\n", valor);
	}
	else
	{
		printf("El elemento %d no se encuentra en la lista", valorBuscado);
	}

	printf("FIN");
}


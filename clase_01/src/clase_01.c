/*
 ============================================================================
 Name        : clase_01.c
 Author      : Gonzalo Sinnott
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

int main(void) {

	//Declaro variables
	int numero;
	int acumulador = 0;
	float promedio;
	int respuestaScanf;
	int i;

	//Bucle para ingresar 5 valores
	for(i = 0; i < 5 ; i++)
	{
		printf("\nIngrese un numero: ");
		respuestaScanf = scanf("%d", &numero);
		while(respuestaScanf == 0)
		{
			printf("Error, ingrese un numero: ");
			__fpurge(stdin);
			respuestaScanf = scanf("%d", &numero);
		}
		acumulador = acumulador + numero;
	}
	//Sumo los resultados y los promedio
	promedio = (float)acumulador / i;
	//Muestro resultados en pantalla.
	printf("\nEl promedio es %.2f", promedio);
}

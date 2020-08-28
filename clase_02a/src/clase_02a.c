/*
 ============================================================================
 Name        : clase_02.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Dar el maximo  y el minimo de un ingreso de 5 numeros
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

int main(void) {

	int numeroIngresado;
	int maximo;
	int minimo;
	int i;

	for(i=0;i<5;i++)
	{
		printf("ingrese numero %d:",i+1);
		__fpurge(stdin);
		scanf("%d", &numeroIngresado);
		if(i == 0)
		{
			maximo = numeroIngresado;
			minimo = numeroIngresado;
		}
		else
		{
			if(numeroIngresado > maximo)
			{
				maximo = numeroIngresado;
			}
			if(numeroIngresado < minimo)
			{
				minimo = numeroIngresado;
			}
		}
	}

	printf("El numero mas chico ingresado es: %d \nEl numero mas grande ingresado es: %d",minimo,maximo);

}

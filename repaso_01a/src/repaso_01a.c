/*
 ============================================================================
 Name        : repaso_01a.c
 Author      : Gonzalo Sinnott
 Version     :
 Copyright   : 
 Description : Se pide una cantidad indeterminada de edades enteras, informar:
- el máximo ingresado
- el mínimo ingresado
- el promedio
- la cantidad de edades ingresadas
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

int main(void)
{
	//Declaro variables
	int numeroIngresado;
	int maximo;
	int minimo;
	int acumulador = 0;
	int contador = 0;
	float promedio;
	char respuesta;
	int respuestaScanf;

	//Bucle para ingresar valores indeterminados
	do
	{
		printf("\nIngrese un numero:");
		__fpurge(stdin);
		respuestaScanf = scanf("%d", &numeroIngresado);
		while(respuestaScanf == 0)
		{
			printf("Error, ingrese un numero: ");
			__fpurge(stdin);
			respuestaScanf = scanf("%d", &numeroIngresado);
		}

		if(contador == 0)
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
		acumulador = acumulador + numeroIngresado;
		contador++;

		printf("\n¿Desea continuar? (S/N)");
		__fpurge(stdin);
		scanf("%c", &respuesta);
	}while(respuesta == 'S');

	promedio = (float)acumulador / contador;

	//Muestro resultados en pantalla.
	printf("\nEl numero mas grande es: %d \nEl numero mas chico es: %d",maximo,minimo);
	printf("\nEl promedio es %.2f", promedio);
	printf("\nLa cantidad de numeros ingresados es %d", contador);
}

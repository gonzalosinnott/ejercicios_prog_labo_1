/*
 ============================================================================
 Name        : clase_05a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Arrays - Pedir 5 numeros y darle a elegir al usuario:
 1-Calcular Maximo
 3- Calcular Minimo
 2-Calcular Promedio
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>

#include "mi_biblioteca.h"


#define CANTIDAD_ELEMENTOS 5

int main(void) {

	int numeroIngresado;
	int arrayInt[CANTIDAD_ELEMENTOS];
	int opcionElegida;
	int numeroMax;
	int numeroMin;
	float promedio;


	for(int i = 0;i<CANTIDAD_ELEMENTOS;i++)
	{
		getEntero(&numeroIngresado, "\nIngrese un numero:", "Error, no es un numero.", 3);
		arrayInt[i] = numeroIngresado;
	}

	if(getEnteroConRango(&opcionElegida, 1, 3, "\nElegir una opcion:\n 1-Calcular Maximo\n 2-Calcular Minimo\n 3-Calcular Promedio\nOpcion:", "Error, no es una opcion valida.", 3)==0)
	{
		switch(opcionElegida)
		{
			case 1:
				if(getMaxEntero(&numeroMax, arrayInt, CANTIDAD_ELEMENTOS)==0)
				{
					printf("El mayor numero ingresado es: %d\n", numeroMax);
				}
				break;
			case 2:
				if(getMinEntero(&numeroMin, arrayInt, CANTIDAD_ELEMENTOS)==0)
				{
					printf("El menor numero ingresado es: %d\n", numeroMin);
				}
				break;
			case 3:
				if(getPromedioEntero(&promedio, arrayInt, CANTIDAD_ELEMENTOS)==0)
				{
					printf("El promedio es: %.2f\n", promedio);
				}
				break;
		}
	}
}







/*
 ============================================================================
 Name        : repaso_02b.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Realizar una función que reciba el precio float y el porcentaje
 de descuento como entero  ,retornar el precio con el descuento al main
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

int precioConDescuento(float precio, int descuento, float* resultado);

int main(void)
{
	float precio;
	int descuento;
	float resultado;
	int respuestaScanf;


	printf("\nIngrese un precio:");
	__fpurge(stdin);
	respuestaScanf = scanf("%f", &precio);
	while(respuestaScanf == 0)
	{
		printf("\nError, ingrese un precio en numeros:");
		__fpurge(stdin);
		respuestaScanf = scanf("%f", &precio);
	}

	printf("\nIngrese el descuento:");
	__fpurge(stdin);
	respuestaScanf = scanf("%d", &descuento);
	while(respuestaScanf == 0)
	{
		printf("\nError, ingrese un descuento en numeros enteros:");
		__fpurge(stdin);
		respuestaScanf = scanf("%d", &descuento);
	}

	if(precioConDescuento(precio, descuento, &resultado) == 0)
	{
		printf("\nEl precio con descuento es: %.2f",resultado);
	}
}

int precioConDescuento(float precio, int descuento, float *resultado)
{
	int retorno = -1;
	if (resultado != NULL)
	{
		*resultado = (float)descuento * precio / 100;
		retorno = 0;
	}
	return retorno;
}

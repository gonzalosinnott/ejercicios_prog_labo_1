/*
 ============================================================================
 Name        : repaso_03a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : 1- realizar el pedido de 10 números entre -100 y 100
 al usuario y guardarlos en un vector, luego de ese vector obtén
	a- la suma de los números pares
	b- que se muestren los números impares
	c- la cantidad de ceros
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "mi_biblioteca.h"

#define CANTIDAD_ELEMENTOS 10

int getPares(int array[], int elementos, int arrayProvisorio[]);
int getImpares(int array[], int elementos, int arrayProvisorio[]);
int getContadorCeros(int array[], int elementos);
int getSumaArray(int array[], int elementos);


int main(void)
{
	int numeroIngresado;
	int arrayInt[CANTIDAD_ELEMENTOS];
	int arrayProvisorio [CANTIDAD_ELEMENTOS];

	for(int i = 0;i<CANTIDAD_ELEMENTOS;i++)
	{
		if(getEnteroConRango(&numeroIngresado, -100, 100, "Ingrese un numero entre -100 y 100: ", "Error.", 3)==0)
		{
			arrayInt[i] = numeroIngresado;
		}
	}

	if(getPares(arrayInt, CANTIDAD_ELEMENTOS, arrayProvisorio)== 0)
	{
		getSumaArray(arrayProvisorio, CANTIDAD_ELEMENTOS);
	}

}


int getPares(int array[], int elementos, int arrayProvisorio[])
{
	int retorno = -1;
	int i;

	if(array != NULL && elementos > 0)
	{
		for(i = 0; i < elementos; i++)
		{
			if(array[i] !=0 && array[i]%2==0)
			{

			}
		}
		retorno = 0;
	}
	return retorno;
}

int getImpares(int array[], int elementos, int arrayProvisorio[])
{
	int retorno = -1;
	int i;

	if(array != NULL && elementos > 0)
	{
		for(i = 0; i < elementos; i++)
		{
			if(array[i] !=0 && array[i]%2!=0)
			{
				arrayProvisorio[i] = array[i];
			}
		}
		retorno = 0;
	}
	return retorno;
}

int getContadorCeros(int array[], int elementos)
{
	int retorno = -1;
	int i;
	int contadorCeros = 0;

	if(array != NULL && elementos > 0)
	{
		for(i = 0; i < elementos; i++)
		{
			if(array[i]==0)
			{
				contadorCeros++;
			}
		}
		retorno = 0;
		printf("%d", contadorCeros);
	}
	printf("\n");
	return retorno;
}

int getSumaArray(int array[], int elementos)
{
	int retorno = -1;
	int i;
	int acumuladorArray = 0;

	if(array != NULL && elementos > 0)
	{
		for(i = 0; i < elementos; i++)
		{
			acumuladorArray = acumuladorArray + array[i];
		}
		retorno = 0;
	}
	printf("%d", acumuladorArray);
	return retorno;
}

/*
 ============================================================================
 Name        : reapso_04a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description :necesitamos hacer una aplicación para una veterinaria que tiene 10
 lugares para atender a las mascotas.
 deberíamos almacenar nombre de (máximo 10 letras o un solo carácter para los que NO
 vieron cadena de caracteres) y edad de la mascota.
 a-permitir el ingreso de las 10 mascotas
 b-mostrar el listado de las mascotas ingresadas
 c-Hacer  inclusive el menú en FUNCIONES

 2-
 d- ordenar por nombre( o inicial si no se vio cadenas)
 e-ordenar por edad
 ============================================================================
 */
//NO FUNCIONA!!!!!!!!!!!!!!

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "mi_biblioteca.h"

#define ARRAY_LEN 2
#define STRING_LEN 50
#define LIMITE_BUFFER_STRING 1000

static int myGets (char cadena[], int longitud);
int getString(char* msj, char* msjError, char *string[], int intentos, int limite);
int getValidarArrayChar(char array[]);
int getEnteroConRango(int* pValor, int min, int max, char* msj, char* msjError, int intentos);
int printArrayString(char *array[], int limiteArray, int limiteString);


int main(void)
{
	char nombreMascota[ARRAY_LEN][STRING_LEN];
	int edadMascota[ARRAY_LEN];
	int numeroIngresado;
	int i = 0;

	while(i < ARRAY_LEN)
	{
		getString("Ingrese nombre de la mascota: ", "Error, no es un nombre valido. ", nombreMascota, 3, ARRAY_LEN-1);
		if(getEnteroConRango(&numeroIngresado, 0, 20, "Ingrese edad de la mascota: ", "Error.", 3)==0)
		{
			edadMascota[i] = numeroIngresado;
		}
		i++;
	}
    printArrayString(nombreMascota,ARRAY_LEN,STRING_LEN);
	return EXIT_SUCCESS;
}

int getString(char* msj, char* msjError, char *string[], int intentos, int limite)
{
	int retorno = -1;
	char bufferString[4000];

	if(msj != NULL && msjError != NULL && string != NULL && intentos > 0 && limite > 0)
	{
		do
		{
			printf("%s", msj);
			if(myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
			   strnlen(bufferString, sizeof(bufferString)-1) &&
			   getValidarArrayChar(bufferString) == 0)
			{
				retorno = 0;
				strncpy(string,bufferString,limite);
				break;
			}
			else
			{
				intentos--;
				printf("%s Te quedan %d reintentos.\n", msjError,intentos);
				if(intentos == 0)
				{
					printf("\nSe agotaron los intentos\n");
					break;
				}
			}
		}while(intentos > 0);
	}
	return retorno;
}

int getValidarArrayChar(char array[])
{
	int respuesta = 0;
	int i = 0;

	if(array != NULL)
	{
		while(array[i] != '\0')
		{
			if((array[i] < 'A' || array[i] > 'Z') &&
			   (array[i] < 'a' || array[i] > 'z'))
			{
				respuesta = -1;
				break;
			}
			i++;
		}
	}
	else
	{
		respuesta = -1;
	}
	return respuesta;
}

int getEnteroConRango(int* pValor, int min, int max, char* msj, char* msjError, int intentos)
{
	int retorno = -1;
	int num;
	int retornoScanf;

	if(pValor != NULL && msj != NULL && msjError != NULL && min<=max)
	{
		do
		{
			printf("%s", msj);
			__fpurge(stdin);
			retornoScanf = scanf( "%d" ,&num);
			if(retornoScanf == 1 && num >= min && num <= max)
			{
				*pValor = num;
				retorno = 0;
				break;
			}
			intentos--;
			if(intentos == 0)
			{
				printf("\nSe agotaron los intentos");
				break;
			}
			printf("%s Te quedan %d reintentos.", msjError,intentos);
		}while(intentos > 0);
	}
	return retorno;
}

int printArrayString(char *array[], int limiteArray, int limiteString)
{
	int retorno = -1;
	int i;
	int j;

	if(array != NULL)
	{
		for (i= 0; i < limiteArray; i ++)
		{
			for (j= 0; j < limiteString; j++) {
		        printf("%c", array[i][j]);
		    }
			printf("\n");
		}
		retorno = 0;
	}
	return retorno;
}

static int myGets(char cadena[],int longitud)
{
	if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin)==cadena)
	{
		__fpurge (stdin);
		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]='\0';
		}
		return 0;
	}
	return -1;
}



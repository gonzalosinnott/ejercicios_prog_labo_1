/*
 ============================================================================
 Name        : utn.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Creacion de Biblioteca utn.c
 ============================================================================
 */



#include <stdio_ext.h>
#include <stdlib.h>

//Comentar descripcion utn_getEntero modelo abajo\\

/**
 * \brief utn_getNumero : Pide al usuario un numero
 * \param pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param min: valor minimo valido (inclusive)
 * \param max: valor maximo valido (no inclusive)
 * \param msg: El mensaje que imprime para pedir un valor
 * \param msgError: mensaje que imprime si el rango no es valido
 * \return Retorno: 0: si esta OK. -1: Si hubo un error
 */

int utn_getEntero(int* pNumero, int min, int max, char* msj, char* msjError, int intentos)
{
	int retorno = -1;
	int num;
	int retornoScanf;

	do
	{
		printf("%s", msj);
		__fpurge(stdin);
		retornoScanf = scanf( "%d" ,&num);
		if(retornoScanf == 1 && num >= min && num <= max)
		{
			*pNumero = num;
			retorno = 0;
		}
		intentos--;
		if(intentos == 0)
		{
			printf("\nSe agotaron los intentos");
			break;
		}
		printf("%s Te quedan %d reintentos.", msjError,intentos);
	}while(intentos > 0);

	return retorno;
}


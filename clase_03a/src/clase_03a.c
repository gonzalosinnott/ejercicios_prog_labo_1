/*
 ============================================================================
 Name        : clase_03a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Funciones.
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

//prototipo de la funcion declarado
int sumarEnteros(int numeroUno, int numeroDos);

int main(void){

	int resultado;

	//Funcion
	resultado = sumarEnteros(14,22);//Funcion

	printf("El resultado es: %d", resultado);
	return EXIT_SUCCESS;
}

//Desarrollo de la funcion
int sumarEnteros(int numeroUno, int numeroDos)
{
	int resultado;

	resultado = numeroUno + numeroDos;
	return resultado;
}

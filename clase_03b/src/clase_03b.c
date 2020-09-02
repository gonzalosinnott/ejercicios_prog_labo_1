/*
 ============================================================================
 Name        : clase_03b.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Validacion de funciones y punteros
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

//prototipo de la funcion declarado
float divisionEnteros (int numeroUno, int numeroDos, float *resultado);

int main(void)
{
	float resultado;
	int numeroUno;
	int numeroDos;
	//Ingreso de Datos
	printf("Ingrese el primer numero:");
	__fpurge(stdin);
	scanf("%d", &numeroUno);
	printf("Ingrese el segundo numero:");
	__fpurge(stdin);
	scanf("%d", &numeroDos);
	//Funcion
	if(divisionEnteros(numeroUno,numeroDos,&resultado) == 0)
	{
		printf("El resultado es: %.2f", resultado);
	}
	else
	{
		printf("No se puede dividir por 0.");
	}
	return EXIT_SUCCESS;
}
//Desarrollo de las funciones extra
float divisionEnteros(int numeroUno, int numeroDos, float *resultado)
{
	int retorno;

	if(numeroDos != 0)
	{
		*resultado = (float)numeroUno / numeroDos;
		retorno = 0;
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}

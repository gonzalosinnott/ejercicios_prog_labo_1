/*
 ============================================================================
 Name        : clase_03c.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Pedir dos numeros FLOAT
 -Imprimir el resultado de las funciones de suma, resta,
 multiplicacion y division.
 -Todas las funciones en caso de exito return 0 y en caso de error return 1
 ============================================================================
 */
#include <stdio_ext.h>
#include <stdlib.h>

//prototipo de la funcion declarado
int suma (float numeroUno, float numeroDos, float *resultado);
int resta (float numeroUno, float numeroDos, float *resultado);
int multiplicacion (float numeroUno, float numeroDos, float *resultado);
int division (float numeroUno, float numeroDos, float *resultado);
int getFloat(char *mensaje, char *mensajeError, int reintentos, float *resultado);

int main(void)
{
	//Declaracion variables
	float resultado;
	float numeroUno;
	float numeroDos;


	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;

	//Ingreso de Datos
	if(getFloat("\nIngrese el primer operando: ","\nError, Ingrese un numero: ",2,&numeroUno) == 0)
	{
		if(getFloat("\nIngrese el segundo operando: ","\nError, Ingrese un numero: ",2,&numeroDos) == 0)
		{
		//Funciones
			if(suma(numeroUno,numeroDos,&resultado) == 0)
			{
				resultadoSuma = resultado;
			}
			if(resta(numeroUno,numeroDos,&resultado) == 0)
			{
				resultadoResta = resultado;
			}
			if(multiplicacion(numeroUno,numeroDos,&resultado) == 0)
			{
				resultadoMultiplicacion = resultado;
			}
			printf("\nEl resultado de la suma es: %.2f\nEl resultado de la resta es: %.2f\nEl resultado de la multiplicacion es: %.2f", resultadoSuma, resultadoResta, resultadoMultiplicacion);

			if(division(numeroUno,numeroDos,&resultado) == 0)
			{
				printf("\nEl resultado de la division es: %.2f", resultado);
			}
			else
			{
				printf("\nNo se puede dividir por 0.");
			}
			return EXIT_SUCCESS;
		}
	}
}

//Desarrollo de las funciones extra
int suma (float numeroUno, float numeroDos, float *resultado)
{
	int retorno = -1;
	if(resultado != NULL)
	{
		*resultado = numeroUno + numeroDos;
		retorno = 0;
	}
	return retorno;
}

int resta (float numeroUno, float numeroDos, float *resultado)
{
	int retorno = -1;
	if(resultado != NULL)
	{
		*resultado = numeroUno - numeroDos;
		retorno = 0;
	}
	return retorno;
}

int multiplicacion (float numeroUno, float numeroDos, float *resultado)
{
	int retorno = -1;
	if(resultado != NULL)
	{
		*resultado = numeroUno * numeroDos;
		retorno = 0;
	}
	return retorno;
}

int division (float numeroUno, float numeroDos, float *resultado)
{
	int retorno = -1;
	if(resultado != NULL && numeroDos != 0)
	{
		*resultado = numeroUno / numeroDos;
		retorno = 0;
	}
	return retorno;
}

int getFloat(char *mensaje,char *mensajeError,int reintentos,float *resultado)
{
	int retorno = -1;
	int resultadoScan;
	float bufferFloat;
	printf("%s",mensaje);
	__fpurge(stdin);
	resultadoScan = scanf("%f", &bufferFloat);
	while (resultadoScan == 0 && reintentos > 0)
	{
		reintentos--;
		printf("%s",mensajeError);
		__fpurge(stdin);
		resultadoScan = scanf("%f", &bufferFloat);
	}
	if(resultadoScan != 0)
	{
		*resultado = bufferFloat;
		retorno = 0;
	}
	return retorno;
}



/*
 ============================================================================
 Name        : utn.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Biblioteca mi_biblioteca.c - Created on: 3 sept. 2020
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STRING_LEN 100
#define LIMITE_BUFFER_STRING 4096

static int myGets(char *cadena, int longitud);

/*
 * \brief utn_getSuma : suma dos numeros float previamente guardados.
 * \param numeroUno: primer variable de la suma.
 * \param numeroDos: segunda variable de la suma.
 * \param * resultado: Direccion de memoria de la variable donde escribe el valor de la suma.
 * \return retorno: 0: si esta OK. -1: Si hubo un error
 */

int utn_getSuma (float numeroUno, float numeroDos, float* resultado)
{
	int retorno = -1;
	if(resultado != NULL)
	{
		*resultado = numeroUno + numeroDos;
		retorno = 0;
	}
	return retorno;
}

/*
 * \brief utn_getResta : resta dos numeros float previamente guardados.
 * \param numeroUno: primer variable de la resta.
 * \param numeroDos: segunda variable de la resta.
 * \param * resultado: Direccion de memoria de la variable donde escribe el valor de la resta.
 * \return retorno: 0: si esta OK. -1: Si hubo un error
 */

int utn_getResta(float numeroUno, float numeroDos, float* resultado)
{
	int retorno = -1;
	if(resultado != NULL)
	{
		*resultado = numeroUno - numeroDos;
		retorno = 0;
	}
	return retorno;
}

/*
 * \brief utn_getMultiplicacion : multiplica dos numeros float previamente guardados.
 * \param numeroUno: primer variable de la multiplicacion.
 * \param numeroDos: segunda variable de la multiplicacion.
 * \param * resultado: Direccion de memoria de la variable donde escribe el valor de la multiplicacion.
 * \return retorno: 0: si esta OK. -1: Si hubo un error
 */

int utn_getMultiplicacion(float numeroUno, float numeroDos, float* resultado)
{
	int retorno = -1;
	if(resultado != NULL)
	{
		*resultado = numeroUno * numeroDos;
		retorno = 0;
	}
	return retorno;
}

/*
 * \brief utn_getDivision : divide dos numeros float previamente guardados.
 * \param numeroUno: variable dividendo.
 * \param numeroDos: variable divisor.
 * \param * resultado: Direccion de memoria de la variable donde escribe el valor de la division.
 * \return retorno: 0: si esta OK. -1: Si hubo un error o se intento dividir por 0.
 */

int utn_getDivision(float numeroUno, float numeroDos, float* resultado)
{
	int retorno = -1;
	if(resultado != NULL && numeroDos != 0)
	{
		*resultado = numeroUno / numeroDos;
		retorno = 0;
	}
	return retorno;
}

/*
 * \brief utn_getFactorial : devuelve el factorial de un numero float previamente guardado.
 * \param numero: variable a calcularle su factorial.
 * \param * resultado: Direccion de memoria de la variable donde escribe el valor del factorial.
 * \return retorno: 0: si esta OK. -1: Si hubo un error o se intento calcular el factorial de un numero negativo
 */

int utn_getFactorial(float numero,float* resultado)
{
	int retorno = -1;

	int contador;
	int factorial = 1;

	if(resultado != NULL )
	{
		if(numero == 0)
		{
			*resultado = 1;
			retorno = 0;
		}
		if(numero > 0)
		{
			for (contador = 1;contador <= numero;contador++)
			{
				factorial = (float)factorial * contador;
			}
			*resultado = factorial;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief utn_getEntero: Solicita un entero al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int maximo, valor maximo admitido
 * \param int minimo, valor minimo admitido
 * \return (-1) Error / (0) Ok
 */
int utn_getEntero(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin);
			resultadoScanf = scanf("%d" , &bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/*
 * \brief utn_getNumeroFloat : Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param mensaje : El mensaje que imprime para pedir un valor.
 * \param mensajeError: El mensaje que imprime si el rango no es valido.
 * \param minimo : valor minimo valido (inclusive)
 * \param maximo : valor maximo valido (inclusive)
 * \param Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * \param Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 */

int utn_getFloat(char* mensaje, char* mensajeError, float* pResultado,int reintentos,int maximo,int minimo)
{
	int retorno = -1;
	float bufferFloat;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin);
			resultadoScanf = scanf("%f" , &bufferFloat);
			if(resultadoScanf == 1 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/*
 * \brief utn_getChar : pide al usuario una letra entre dos opciones
 * \param pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param mensaje : El mensaje que imprime para pedir un valor.
 * \param mensajeError: El mensaje que imprime si el rango no es valido.
 * \param valorUno : valor minimo valido (inclusive)
 * \param valorDos : valor maximo valido (inclusive)
 * \param Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * \param Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 */

int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,char valorUno,char valorDos,int reintentos)
{
	int retorno = -1;
	char bufferChar;
	int resultadoScan;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && valorUno != NULL && valorDos != NULL && reintentos > 0)
	{
		do{
			printf("%s", mensaje);
			fflush(stdin);
			resultadoScan = scanf("%c",&bufferChar);
			if(resultadoScan == 1 && (bufferChar == valorUno || bufferChar == valorDos))
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				if(reintentos == 0)
				{
					printf("\nSe agotaron los intentos");
					break;
				}
				else
				{
					printf("%s Te quedan %d reintentos.", mensajeError,reintentos);
					reintentos--;
				}
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/*
 * \brief utn_getString: Solicita un nombre al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return (-1) Error / (0) Ok
 */
int utn_getString(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
				validarString(bufferString,limite) != 0 )
			{
				retorno = 0;
				//NO EXISTE pResultado = bufferString;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);

	}
	return retorno;
}

/*
 * \brief myGets: Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de ' longitud - 1' caracteres .
 * \param cadena: Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud:  Define el tamaño de cadena
 * \param Retorno: 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 */

static int myGets(char *cadena, int longitud)
{
	__fpurge(stdin);
	fgets (cadena, longitud, stdin);
	cadena[strlen (cadena) - 1] = '\0';
	return 0;
}

//DOCUMENTAR A PARTIR DE ACA

int utn_getMaxEntero(int* resultado, int pArray[],int elementos)
{
	int retorno = -1;
	int numeroMax;
	if(resultado != NULL && pArray != NULL && elementos > 0)
	{
		for(int i = 0;i<elementos;i++)
		{
			if(i == 0 || pArray[i] > numeroMax)
			{
				numeroMax = pArray[i];
			}
		}
		*resultado = numeroMax;
		retorno = 0;
	}
	return retorno;
}

int utn_getMinEntero(int* resultado, int pArray[],int elementos)
{
	int retorno = -1;
	int numeroMin;
	if(resultado != NULL && pArray != NULL && elementos > 0)
	{
		for(int i = 0;i<elementos;i++)
		{
			if(i == 0 || pArray[i] < numeroMin)
			{
				numeroMin = pArray[i];
			}
		}
		*resultado = numeroMin;
		retorno = 0;
	}
	return retorno;
}

int utn_getPromedioEntero(float* resultado, int pArray[],int elementos)
{
	int retorno = -1;
	float promedio;
	int contador = 0;
	int acumulador = 0;

	if(resultado != NULL && pArray != NULL && elementos > 0)
	{
		for(int i = 0;i<elementos;i++)
		{
			contador++;
			acumulador= acumulador + pArray[i];
		}
		promedio = (float)acumulador / contador;
		*resultado = promedio;
		retorno = 0;
	}
	return retorno;
}

int utn_getCantidadValorInt(int* resultado, int array[],int elementos, int valorBuscado)
{
	int retorno = -1;
	int contadorValor = 0;

	if(resultado != NULL && array != NULL && elementos > 0)
	{
		for(int i = 0;i<elementos;i++)
		{
			if(array[i] == valorBuscado)
			{
				contadorValor++;
			}
		}
		if(contadorValor> 0)
		{
			*resultado = contadorValor;
			retorno = 0;
		}
	}
	return retorno;
}


int utn_getCantidadValorChar(int* resultado, char array[], char caracterBuscado)
{
	int retorno = -1;
	int contadorValor = 0;
	int i = 0;
	if(resultado != NULL && array != NULL)
	{
		while(array[i] != '\0')
		{
			if(array[i] == caracterBuscado)
			{
				contadorValor++;
			}
			i++;
		}
		if(contadorValor> 0)
		{
			*resultado = contadorValor;
			retorno = 0;
		}
	}
	return retorno;
}

int jo(int array[], int elementos)
{
	int retorno = -1;
	int indice;
	int swap;
	int ordenado = 0;

	if(array!=NULL && elementos > 0)
	{
		while(ordenado == 0)
		{
			ordenado = 1;
			for(indice = 0; indice <(elementos -1);indice++)
			{
				if(array[indice]>array[indice+1])
				{
					swap =array[indice];
					array[indice] = array[indice+1];
					array[indice+1]=swap;
					ordenado = 0;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int utn_printArrayInt(int array[], int elementos)
{
	int retorno = -1;
	int i;

	if(array != NULL && elementos > 0)
	{
		for(i = 0; i < elementos; i++)
		{
			printf("%d\n", array[i]);
		}
		retorno = 0;
	}
	return retorno;
}

//REVISAR!!!!!!!
int utn_printArrayChar(char array[])
{
	int retorno = -1;
	int i;
	i = 0;

	if(array != NULL)
	{
		while(array[i] != '\0')
		{
			printf("%c\n", array[i]);
			i++;
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief validarString: Verifica una cadena recibida como parametro para determinar si es un nombre valido
 * \param char* cadena, Cadena a analizar
 * \param int limite, indica la cantidad de letras maxima de la cadena
 * \return (0) Indicar que no es un nombre valido / (1) Indica que que es un nombre valido
 *
 */
int validarString(char* cadena,int limite)
{
	int respuesta = 1; // TODOOK

	for(int i=0; i<=limite && cadena[i] != '\0';i++)
	{
		//esta mal <----- A - Z -----> Esta mal
		if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] < 'a' || cadena[i] > 'z') &&
			cadena[i] != '.')
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}


int utn_getValidarArrayInt(int array[])
{
	int respuesta = 0;
	int i = 0;

	if(array != NULL)
	{
		while(array[i] != '\0')
		{
			if(array[i] < '0' || array[i] > '9')
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







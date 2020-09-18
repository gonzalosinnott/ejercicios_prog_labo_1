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

#define LIMITE_BUFFER_STRING 1000

static int myGets (char *cadena, int longitud);

static int myGets (char string[], int longitud)
{
	__fpurge(stdin);
	fgets(string,longitud,stdin);
	string [strlen (string) -1] = '\0';
	return 0;
}
/*
 * \brief utn_getEntero : Pide al usuario un numero entero.
 * \param pValor: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param msg: El mensaje que imprime para pedir un valor
 * \param msgError: El mensaje que imprime si el rango no es valido
 * \param intentos: Intentos totales que quiero dejar al usuario ingresar un valor no valido.
 * \return retorno: 0: si esta OK. -1: Si hubo un error
 */

int utn_getEntero(int* pValor, char* msj, char* msjError, int intentos)
{
	int retorno = -1;
	int num;
	int retornoScanf;

	if(pValor != NULL && msj != NULL && msjError != NULL)
	{
		do
		{
			printf("%s", msj);
			__fpurge(stdin);
			retornoScanf = scanf( "%d" ,&num);
			if(retornoScanf == 1)
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

/*
 * \brief utn_getEnteroConRango : Pide al usuario un numero entero dentor de un rango determinado.
 * \param pValor: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param min: Valor minimo valido (inclusive)
 * \param max: Valor maximo valido (inclusive)
 * \param msg: El mensaje que imprime para pedir un valor
 * \param msgError: El mensaje que imprime si el rango no es valido
 * \param intentos: Intentos totales que quiero dejar al usuario ingresar un valor no valido.
 * \return retorno: 0: si esta OK. -1: Si hubo un error
 */

int utn_getEnteroConRango(int* pValor, int min, int max, char* msj, char* msjError, int intentos)
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

/*
 * \brief utn_getFloat : Pide al usuario un numero con decimales.
 * \param pValor: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param msg: El mensaje que imprime para pedir un valor
 * \param msgError: El mensaje que imprime si el rango no es valido
 * \param intentos: Intentos totales que quiero dejar al usuario ingresar un valor no valido.
 * \return retorno: 0: si esta OK. -1: Si hubo un error
 */

int utn_getFloat(float* pValor, char* msj, char* msjError, int intentos)
{
	int retorno = -1;
	float num;
	int retornoScanf;

	if(pValor != NULL && msj != NULL && msjError != NULL)
	{
		do
		{
			printf("%s", msj);
			__fpurge(stdin);
			retornoScanf = scanf( "%f" ,&num);
			if(retornoScanf == 1)
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
			printf("%s te quedan %d reintentos.", msjError,intentos);
		}while(intentos > 0);
	}
	return retorno;
}

/*
 * \brief utn_getFloatConRango : Pide al usuario un numero con decimales dentro de un rango determinado
 * \param pValor: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param min: Valor minimo valido (inclusive)
 * \param max: Valor maximo valido (inclusive)
 * \param msg: El mensaje que imprime para pedir un valor
 * \param msgError: El mensaje que imprime si el rango no es valido
 * \param intentos: Intentos totales que quiero dejar al usuario ingresar un valor no valido.
 * \return retorno: 0: si esta OK. -1: Si hubo un error
 */

int utn_getFloatConRango(float* pValor, int min, int max, char* msj, char* msjError, int intentos)
{
	int retorno = -1;
	float num;
	int retornoScanf;

	if(pValor != NULL && msj != NULL && msjError != NULL && min <= max)
	{
		do
		{
			printf("%s", msj);
			__fpurge(stdin);
			retornoScanf = scanf( "%f" ,&num);
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

/*
 * \brief utn_getChar : Pide al usuario una letra.
 * \param pValor: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param msg: El mensaje que imprime para pedir un valor
 * \param msgError: El mensaje que imprime si el rango no es valido
 * \param intentos: Intentos totales que quiero dejar al usuario ingresar un valor no valido.
 * \return retorno: 0: si esta OK. -1: Si hubo un error
 */

int utn_getChar(char* pValor,char* msj, char* msjError, int intentos)
{
	int retorno = -1;
	char letra;

	if(pValor != NULL && msj != NULL && msjError != NULL)
	{
		do
		{
			printf("%s", msj);
			__fpurge(stdin);
			scanf( "%c" ,&letra);
			if(isalpha(letra) != 0)
			{
				*pValor = letra;
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

	if(resultado != NULL && array != NULL)
	{
		for(int i = 0;i != '\n';i++)
		{
			if(array[i] == caracterBuscado)
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

int utn_sortArrayEnteros(int array[], int elementos)
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

	if(array != NULL)
	{
		for(i = 0; array[i] != '\0' ;i++)
		{
			printf("%c\n", array[i]);
		}
		retorno = 0;
	}
	return retorno;
}

/*
 * \brief utn_getNombre : .
 * \param msj:
 * \param msjError: Direccion de memoria de la variable donde escribe el valor del factorial.
 * \param nombre:
 * \param intentos:
 * \param limite:
 * \return retorno: 0: si esta OK. -1: Si hubo un error o se intento calcular el factorial de un numero negativo
 */

int utn_getString(char* msj, char* msjError, char string[], int intentos, int limite)
{
	int retorno = -1;
	char bufferString[4000];

	if(msj != NULL && msjError != NULL && string != NULL && intentos > 0 && limite > 0)
	{
		do
		{
			printf("%s", msj);
			if(myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
			   strnlen(bufferString, sizeof(bufferString)-1) <= limite &&
			   utn_getValidarNombre(bufferString, limite) != 0)
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

/*
 * \brief utn_getValidarNombre:
 * \param cadena:
 * \param limite:
 * \return (0) No es un nombre valido. (1)Es un nombre valido
 */

int utn_getValidarNombre(char cadena[],int limite)
{
	int respuesta = 1;

	for(int i = 0; i <= limite && cadena[i] != '\0';i++)
	{
		if((cadena[i] < 'A' || cadena [i] > 'Z') &&
		   (cadena[i] < 'a' || cadena [i] > 'z'))
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}





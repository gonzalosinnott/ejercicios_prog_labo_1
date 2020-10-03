/**
 ============================================================================
 Name        : utn.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Library mi_biblioteca.c
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "mi_biblioteca.h"
#include "pantalla.h"

#define BUFFER_STRING_LEN 1000

static int getInt(int* pValue);
static int isInt(char* string);
static int getFloat(float* pValue);
static int isFloat(char* string);
static int checkString(char* string,int len);
static int myGets(char *string, int len);
static int checkAlphaNum(char* string, int len);


/**
 * \brief getEmployeeMenu: Menu for choosing options of the program,
 * \param choosenOption* list: Pointer to variable that stores choosen option
 * \return (-1) Error / (0) Ok
 */

int getMenu(int* choosenOption)
{
	int retorno = -1;
	if(utn_getIntNumber("\nIngrese una opcion:"
					   "\n 1-Alta de Pantalla."
					   "\n 2-Modificar datos de Pantalla."
					   "\n 3-Baja de Pantalla."
					   "\n 4-Contratacion Publicidad."
					   "\n 5-Modificar contratacion."
					   "\n 6-Cancelar contratacion."
					   "\n 7-Consulta facturacion."
					   "\n 8-Listar contrataciones."
					   "\n 9-Listar pantallas."
					   "\n 10-Generar informes."
					   "\nOpcion:", "\nError.", choosenOption, 3, 6, 1)==0)
	{
		retorno =0;
	}
	else
	{
		*choosenOption = 5;
	}
	return retorno;
}

/**
 * \brief utn_getIntNumber: Asks the user for an int value
 * \param char* msj: Message for the user
 * \param char* errorMsj: Error message
 * \param int* pValue: Pointer to store value given by user
 * \param int retries: amount of retries permitted
 * \param int max: max value admitted
 * \param int min: min value admitted
 * \return (-1) Error / (0) Ok
 */

int utn_getIntNumber(char* msj, char* errorMsj, int* pValue,int retries,int max,int min)
{
	int retorno = -1;
	int bufferInt;

	if(msj != NULL && errorMsj != NULL && pValue != NULL && retries >= 0 && min <= max)
	{
		do
		{
			printf("%s",msj);
			if(getInt(&bufferInt) == 0 && bufferInt >= min && bufferInt <= max)
			{
				*pValue = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s Quedan %d reintentos\n",errorMsj, retries);
				retries--;
			}
		}while(retries > 0);
	}
	return retorno;
}

/**
 * \brief getInt: Asks the user for an integer number, converts it to string,
 *  then validates said value and returns it as an integer.
 * \param int* pValue: pointer to Value given by user.
 * \return (-1) Error / (0) Ok
 */

static int getInt(int *pValue)
{
	int retorno = -1;
	char buffer[64];
	if(pValue != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && isInt(buffer))
		{
			*pValue = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief isInt:Checks if the string entered by the user is a number
 * \param char *string: string of characters to analize
 * \return (0) Error / (1) Ok
 */

static int isInt(char* string)
{
	int retorno = 1;
	int i = 0;

	if(string[0] == '-')
	{
		i = 1;
	}
	if(string != NULL && strlen(string) > 0)
	{
		while(string[i] != '\0')
		{
			if(string[i] < '0' || string[i] > '9' )
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

/**
 * \brief utn_getFloat: Asks the user for a float value
 * \param char* msj: Message for the user
 * \param char* errorMsj: Error message
 * \param int* pValue: Pointer to store value given by user
 * \param int retries: amount of retries permitted
 * \return (-1) Error / (0) Ok
 */

int utn_getFloatNumber(char* msj, char* errorMsj, float* pValue,int retries, int max, int min)
{
	int retorno = -1;
	float bufferFloat;

		if(msj != NULL && errorMsj != NULL && pValue != NULL && retries >= 0 && min <= max)
		{
			do
			{
				printf("%s",msj);
				if(getFloat(&bufferFloat) == 0 && bufferFloat >= min && bufferFloat <= max)
				{
					*pValue = bufferFloat;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s Quedan %d reintentos\n",errorMsj, retries);
					retries--;
				}
			}while(retries > 0);
		}
		return retorno;
}

/**
 * \brief getFloat: Asks the user for a float number, converts it to string,
 *  then validates said value and returns it as an float.
 * \param int* pValue: pointer to Value given by user.
 * \return (-1) Error / (0) Ok
 */

static int getFloat(float* pValue)
{
	int retorno = -1;
	char buffer[64];
	if(pValue != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && isFloat(buffer))
		{
			*pValue = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief isFloat:Checks if the string entered by the user is a number
 * \param char *string: string of characters to analize
 * \return (0) Error / (1) Ok
 */
static int isFloat(char* string)
{
	int retorno = 1;
	int i = 0;

	if(string[0] == '-')
	{
		i = 1;
	}
	if(string != NULL && strlen(string) > 0)
	{
		while(string[i] != '\0')
		{
			if((string[i] < '0' || string[i] > '9') && string[i] != '.')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

/**
 * \brief utn_getString Asks the user for an string value
 * \param char* msj: Message for the user
 * \param char* errorMsj: Error message
 * \param int* pValue: Pointer to store value given by user
 * \param int retries: amount of retries permitted
 * \param int len: lenght allowed for the value entered.
 * \return (-1) Error / (0) Ok
 */

int utn_getString(char* msj, char* errorMsj, char* pValue,int retries, int len)
{
	char bufferString[BUFFER_STRING_LEN];
	int retorno = -1;

	if(msj != NULL && errorMsj != NULL && pValue != NULL && retries >= 0 && len > 0)
	{
		do
		{
			printf("%s",msj);
			if(myGets(bufferString,BUFFER_STRING_LEN) == 0 &&
			   strnlen(bufferString,sizeof(bufferString)-1)<= len &&
			   checkString(bufferString,len) == 0 )
			{
				strncpy(pValue,bufferString,len);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s Quedan %d reintentos\n",errorMsj, retries);
				retries--;
			}
		}while(retries >= 0);
	}
	return retorno;
}

/**
 * \brief checkString: Checks the string for invalid characters
 * Allows upper and lower case letters and spaces
 * \param char* string: Pointer to string to check
 * \param int len: max lenght allowed of the string
 * \return (-1) Error / (0) Ok
 */

static int checkString(char* string,int len)
{
	int retorno = 0;

	for(int i=0; i<=len && string[i] != '\0';i++)
	{
		if(	(string[i] < 'A' || string[i] > 'Z') &&
			(string[i] < 'a' || string[i] > 'z') &&
			 string[i] != ' ')
		{
			retorno = -1;
			break;
		}
	}
	return retorno;
}

/**
 * \brief myGets: Reads from stdin until a '\n' (finalization character)
 *  or until it has copied a string of a length of lenght - 1 characters .
 * \param char *string: Pointer to memory space where string will be copied
 * \param int len: String lenght
 * \return (-1) Error / (0) Ok
 */

static int myGets(char *string, int len)
{
	int retorno = -1;
	__fpurge(stdin);
	if(string != NULL && len > 0 && fgets (string, len, stdin) == string)
	{
		if(string[strlen(string)-1]=='\n')
		{
			string[strlen (string) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief utn_getChar : Ask the user to choose between two letters
 * \param char* msj: Message for the user
 * \param char* errorMsj: Error message
 * \param int* pValue: Pointer to store value given by user
 * \param char valueOne: Option one
 * \param char valueTwo: Option two
 * \param int retries: amount of retries permitted
 * \return (-1) Error / (0) Ok
 */

int utn_getChar(char* msj,char* errorMsj,char* pValue,char valueOne,char valueTwo,int retries)
{
	int retorno = -1;
	char bufferChar;
	int resultadoScan;

	if(msj != NULL && errorMsj != NULL &&  pValue != NULL && retries > 0)
	{
		do{
			printf("%s", msj);
			__fpurge(stdin);
			resultadoScan = scanf("%c",&bufferChar);
			if(resultadoScan == 1 && (bufferChar == valueOne || bufferChar == valueTwo))
			{
				*pValue = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s Te quedan %d reintentos.\n", errorMsj,retries);
				retries--;
			}
		}while(retries >= 0);
	}
	return retorno;
}

/**
 * \brief utn_getAlphaNum: Asks the user for an alphanumeric value
 * \param char* msj: Message for the user
 * \param char* errorMsj: Error message
 * \param int* pValue: Pointer to store value given by user
 * \param int retries: amount of retries permitted
 * \param int len: lenght allowed for the value entered.
 * \return (-1) Error / (0) Ok
 */

int utn_getAlphaNum(char* msj, char* errorMsj, char* pValue,int retries, int len)
{
	char bufferString[BUFFER_STRING_LEN];
	int retorno = -1;

	if(msj != NULL && errorMsj != NULL && pValue != NULL && retries >= 0 && len > 0)
	{
		do
		{
			printf("%s",msj);
			if(myGets(bufferString,BUFFER_STRING_LEN) == 0 &&
			   strnlen(bufferString,sizeof(bufferString)-1)<= len &&
			   checkAlphaNum(bufferString,len) == 0 )
			{
				strncpy(pValue,bufferString,len);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s Quedan %d reintentos\n",errorMsj, retries);
				retries--;
			}
		}while(retries >= 0);
	}
	return retorno;
}

/**
 * \brief checkAlphaNum: Checks the string for invalid characters
 * Allows upper and lower case letters, numbers and spaces
 * \param char* string: Pointer to string to check
 * \param int len: max lenght allowed of the string
 * \return (-1) Error / (0) Ok
 */

static int checkAlphaNum(char* string, int len)
{
	int retorno = 0;

	if(string != NULL)
	{
		for(int i=0; i<=len && string[i] != '\0';i++)
		{
			if((string[i] != ' ') &&
			   (string[i] < 'a' || string[i] > 'z') &&
			   (string[i] < 'A' || string[i] > 'Z') &&
			   (string[i] < '0' || string[i] > '9'))
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}





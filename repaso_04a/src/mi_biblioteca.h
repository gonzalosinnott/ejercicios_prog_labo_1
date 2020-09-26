/*
 ============================================================================
 Name        : mi_biblioteca.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Header de la biblioteca mi_biblioteca.c - Created on: 3 sept. 2020
 ============================================================================
 */

#ifndef MI_BIBLIOTECA_H_
#define MI_BIBLIOTECA_H_

int utn_getEntero(int* pNumero, char* msj, char* msjError, int reintentos);
int utn_getEnteroConRango(int* pValor, int min, int max, char* msj, char* msjError, int intentos);
int utn_getFloat(float* pValor, char* msj, char* msjError, int intentos);
int utn_getFloatConRango(float* pValor, int min, int max, char* msj, char* msjError, int intentos);
int utn_getChar(char* pValor,char* msj, char* msjError, int intentos);

int utn_getSuma (float numeroUno, float numeroDos, float *resultado);
int utn_getResta (float numeroUno, float numeroDos, float *resultado);
int utn_getMultiplicacion (float numeroUno, float numeroDos, float *resultado);
int utn_getDivision (float numeroUno, float numeroDos, float *resultado);
int utn_getFactorial(float numero,float* resultado);

int utn_getMaxEntero(int* resultado, int pArray[],int elementos);
int utn_getMinEntero(int* resultado, int pArray[],int elementos);
int utn_getPromedioEntero(float* resultado, int pArray[],int elementos);
int utn_getCantidadValorInt(int* resultado, int array[],int elementos, int valorBuscado);
int utn_getCantidadValorChar(int* resultado, char array[], char caracterBuscado);
int utn_sortArrayEnteros(int array[], int elementos);
int utn_printArrayInt(int array[], int elementos);
int utn_printArrayChar(char array[]);

int utn_getString(char* msj, char* msjError, char string[], int intentos, int limite);
int utn_getValidarArrayChar(char array[]);
int utn_getValidarArrayInt(int array[]);


#endif /* MI_BIBLIOTECA_H_ */

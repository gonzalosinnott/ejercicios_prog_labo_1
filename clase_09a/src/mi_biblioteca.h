/*
 ============================================================================
 Name        : mi_biblioteca.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Header de la biblioteca mi_biblioteca.c - Created on: 3 sept. 2020
 ============================================================================
 */

#ifndef MI_BIBLIOTECAB_H_
#define MI_BIBLIOTECAB_H_

//Operaciones Matematicas
int utn_getSuma (float numeroUno, float numeroDos, float *resultado);
int utn_getResta (float numeroUno, float numeroDos, float *resultado);
int utn_getMultiplicacion (float numeroUno, float numeroDos, float *resultado);
int utn_getDivision (float numeroUno, float numeroDos, float *resultado);
int utn_getFactorial(float numero,float* resultado);
//Ingreso de Datos
int utn_getEntero(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,char valorUno,char valorDos,int reintentos);
int utn_getString(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int validarString(char* cadena,int limite);
//Operacioes con Arrays
int utn_getMaxEntero(int* resultado, int pArray[],int elementos);
int utn_getMinEntero(int* resultado, int pArray[],int elementos);
int utn_getPromedioEntero(float* resultado, int pArray[],int elementos);
int utn_getCantidadValorInt(int* resultado, int array[],int elementos, int valorBuscado);
int utn_getCantidadValorChar(int* resultado, char array[], char caracterBuscado);
int utn_sortArrayEnteros(int array[], int elementos);
int utn_printArrayInt(int array[], int elementos);
int utn_printArrayChar(char array[]);
int validarString(char* cadena,int limite);


#endif /* MI_BIBLIOTECAB_H_ */

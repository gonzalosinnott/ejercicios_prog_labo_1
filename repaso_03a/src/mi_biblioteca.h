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

int getEntero(int* pNumero, char* msj, char* msjError, int reintentos);
int getEnteroConRango(int* pValor, int min, int max, char* msj, char* msjError, int intentos);
int getFloat(float* pValor, char* msj, char* msjError, int intentos);
int getFloatConRango(float* pValor, int min, int max, char* msj, char* msjError, int intentos);
int getChar(char* pValor,char* msj, char* msjError, int intentos);

int getSuma (float numeroUno, float numeroDos, float *resultado);
int getResta (float numeroUno, float numeroDos, float *resultado);
int getMultiplicacion (float numeroUno, float numeroDos, float *resultado);
int getDivision (float numeroUno, float numeroDos, float *resultado);
int getFactorial(float numero,float* resultado);

int getMaxEntero(int* resultado, int pArray[],int elementos);
int getMinEntero(int* resultado, int pArray[],int elementos);
int getPromedioEntero(float* resultado, int pArray[],int elementos);
int sortArrayEnteros(int array[], int indice);
int printArray(int array[], int elementos);


#endif /* MI_BIBLIOTECA_H_ */

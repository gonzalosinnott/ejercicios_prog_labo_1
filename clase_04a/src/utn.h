/*
 ============================================================================
 Name        : utn.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Header de la biblioteca utn.c - Created on: 3 sept. 2020
 ============================================================================
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getEntero(int* pNumero, int min, int max, char* msj, char* msjError, int reintentos);
int utn_getFloat(float* pValor, int min, int max, char* msj, char* msjError, int intentos);
int utn_getChar(char* pValor,char* msj, char* msjError, int intentos);

#endif /* UTN_H_ */

/*
 * utn.h
 *
 *  Created on: 3 sept. 2020
 *      Author: Gonzalo Sinnott Segura
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getEntero(int* pNumero, int min, int max, char* msj, char* msjError, int reintentos);
int utn_getFloat(float* pValor, int min, int max, char* msj, char* msjError, int intentos);
int utn_getChar(char* pValor,char* msj, char* msjError, int intentos);

#endif /* UTN_H_ */

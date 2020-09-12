/*
 ============================================================================
 Name        : clase_06b.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Cadena de Caracteres
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "mi_biblioteca.h"

int main(void) {

	char texto [10];

	texto[0] = 'H';
	texto[1] = 'O';
	texto[2] = 'L';
	texto[3] = 'A';

	printArrayChar(texto);
}

/*
 ============================================================================
 Name        : clase_02b.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Solicitar al usuario que ingrese una serie de números la cual
 finaliza al introducir el 999 (el 999 no debe ser tenido en cuenta para dicho
 cálculo). Una vez finalizado el ingreso de números el programa deberá mostrar
 el promedio de dichos números por pantalla.
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

int main(void) {

	int contador = 0;
	int acumulador = 0;
	int numeroIngresado = 0;
	float promedio = 0;
	int respuestaScanf;

	while(numeroIngresado != 999)
	{
		printf("ingrese un numero (el numero 999 corta el ingreso):");
		__fpurge(stdin);
		respuestaScanf = scanf("%d", &numeroIngresado);
		while(respuestaScanf == 0)
		{
			printf("Error, ingrese un numero: ");
			__fpurge(stdin);
			respuestaScanf = scanf("%d", &numeroIngresado);
		}

		if(numeroIngresado != 999)
		{
			contador++;
			acumulador = acumulador + numeroIngresado;
		}
	}

	if(promedio != 0)
	{
		promedio = (float)acumulador / contador;
		printf("El promedio de los numeros ingresados es: %.2f",promedio);
	}
	else
	{
		printf("No se ingresaron numeros validos.");
	}
}

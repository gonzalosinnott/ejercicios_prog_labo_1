/*
 ============================================================================
 Name        : repaso_02a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Sin funciones: para realizar un pedido, solicitar tres datos, iterar 5 veces:
 -código de tipo int , validar entre 100 y 200
 -cantidad de tipo entero(int), validar entre 1 y 20
 -una talle de tipo char validad entre('S' , 'M' , 'L')

 a-mostrar el código y el talle  del que mas cantidad solicito
 b-el promedio del total  de cantidades de talle 'M' con decimales
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int codigoProducto;
	int cantidadProducto;
	char talleProducto;
	int cantidadMaxima;
	char talleMasPedido;
	int codigoMasPedido;
	int contadorTalleM = 0;
	int acumuladorTalleM = 0;
	float promedioTalleM;

	for(i=0; i<5; i++)
	{
		printf("\nIngrese codigo valido (100 a 200):");
		__fpurge(stdin);
		scanf("%d", &codigoProducto);
		while(codigoProducto < 100 || codigoProducto > 200)
		{
			printf("\nError, Ingrese codigo valido (100 a 200):");
			__fpurge(stdin);
			scanf("%d", &codigoProducto);
		}

		printf("\nIngrese cantidad valida (1 a 20):");
		__fpurge(stdin);
		scanf("%d", &cantidadProducto);
		while(cantidadProducto < 1 || cantidadProducto > 20)
		{
			printf("\nError, ingrese cantidad valida (1 a 20):");
			__fpurge(stdin);
			scanf("%d", &cantidadProducto);
		}

		printf("\nIngrese talle valido (s , m , l):");
		__fpurge(stdin);
		scanf("%c", &talleProducto);
		while(talleProducto != 's' && talleProducto != 'm' && talleProducto != 'l')
		{
			printf("\nError, ingrese talle valido (s , m , l):");
			__fpurge(stdin);
			scanf("%c", &talleProducto);
		}

		//codigo y  talle  del que mas cantidad solicito
		if(i == 0 || cantidadProducto > cantidadMaxima)
		{
			cantidadMaxima = cantidadProducto;
			talleMasPedido = talleProducto;
			codigoMasPedido = codigoProducto;
		}

		//promedio del total  de cantidades de talle 'M' con decimales
		if(talleProducto == 'm')
		{
			contadorTalleM++;
			acumuladorTalleM = acumuladorTalleM + cantidadProducto;
		}
	}

	promedioTalleM = (float)acumuladorTalleM / contadorTalleM;

	printf("\nEl talle mas pedido es %c, con el codigo %d",talleMasPedido,codigoMasPedido);
	if(contadorTalleM ==0)
	{
		printf("\nNo se compraron productos de talle M");
	}
	else
	{
		printf("\nEl promedio de compra de talle M es %.2f",promedioTalleM);
	}
}

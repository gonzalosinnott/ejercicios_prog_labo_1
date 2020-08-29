/*
 ============================================================================
 Name        : repaso_01b.c
 Author      : Gonzalo Sinnott
 Version     :
 Copyright   : 
 Description : Ademas de la edad ingresar:
 - el estado civil de la persona ('s' para soltera , 'c' para casada, 'd' divorciada)

 Ademas de informar lo anterior ....informar:
 -la persona mas joven de las casadas
 -la persona mas Vieja de las solteras
 -de los estados civiles , cual fue el mas ingresado
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

int main(void)
{
	//Declaro variables
	int edad;
	char estadoCivil;
	int maximo;
	int minimo;
	int acumulador = 0;
	int contador = 0;
	float promedio;
	char respuesta;
	int respuestaScanf;
	int casadoMasJoven;
	int solteroMasViejo;
	int contadorSolteros = 0;
	int contadorCasados = 0;
	int contadorDivorciados = 0;

	//Bucle para ingresar valores indeterminados
	do
	{
		//Ingreso edad con validación
		printf("\nIngrese edad:");
		__fpurge(stdin);
		respuestaScanf = scanf("%d", &edad);
		while(respuestaScanf == 0 && (edad < 1 || edad > 100))
		{
			printf("Error, ingrese una edad valida:");
			__fpurge(stdin);
			respuestaScanf = scanf("%d", &edad);
		}

		//Ingreso estado civil con validación
		do
		{
			printf("\nIngrese un estado civil valido ('s' para soltera , 'c' para casada, 'd' divorciada):");
			__fpurge(stdin);
			respuestaScanf = scanf("%c", &estadoCivil);
		}while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'd');

		// el máximo ingresado y el mínimo ingresado
		if(contador == 0 || edad > maximo)
		{
			maximo = edad;
		}
		if(contador == 0 || edad < minimo)
		{
			minimo = edad;
		}

		// la persona mas joven de las casadas y la persona mas Vieja de las solteras,
		switch(estadoCivil)
		{
			case 's':
				contadorSolteros++;
				if(contador == 0 || edad > solteroMasViejo)
				{
					solteroMasViejo = edad;
				}
				break;
			case 'c':
				contadorCasados++;
				if(contador == 0 || edad < casadoMasJoven)
				{
					casadoMasJoven = edad;
				}
				break;
			case 'd':
				contadorDivorciados++;
				break;
		}

		// la cantidad de edades ingresadas
		acumulador = acumulador + edad;
		contador++;

		do
		{
			printf("\n¿Desea continuar? (s/n)");
			__fpurge(stdin);
			scanf("%c", &respuesta);
		}while(respuesta !='s' && respuesta !='n');

	}while(respuesta == 's');

	// el promedio
	promedio = (float)acumulador / contador;

	// de los estados civiles , cual fue el mas ingresado


	//Muestro resultados en pantalla.
	printf("\nLa edad maxima es: %d",maximo);
	printf("\nLa edad minima es: %d",minimo);
	printf("\nEl promedio de edad es %.2f", promedio);
	printf("\nLa cantidad de edades ingresadas es %d", contador);
	printf("\nLa persona casada mas joven tiene %d años",casadoMasJoven);
	printf("\nLa persona soltera mas vieja tiene %d años,",solteroMasViejo);

	// de los estados civiles , cual fue el mas ingresado
	if(contadorSolteros > contadorCasados && contadorSolteros > contadorDivorciados)
	{
		printf("\nEl estado civil mas ingresado es Soltero.");
	}
	else
	{
		if(contadorCasados > contadorSolteros && contadorCasados > contadorDivorciados)
		{
			printf("\nEl estado civil mas ingresado es Casado.");
		}
		else
		{
			if(contadorDivorciados > contadorSolteros && contadorDivorciados > contadorCasados)
			{
				printf("\nEl estado civil mas ingresado es Divorciado.");
			}
		}
	}
}

//alumno.c

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "mi_biblioteca.h"
#include "alumno.h"

/**
 * \brief alumno_alta: Realiza el alta de un alumno solo si el indice corresponde a un Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 */

int alumno_alta(Alumno arrayAlumnos[],int limite,int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(	arrayAlumnos != NULL &&
		limite > 0 &&
		indice >=0 &&
		indice < limite &&
		arrayAlumnos[indice].isEmpty == TRUE)
	{
		if(	utn_getEntero("\nLegajo:","\nError(50 A 9999)",&bufferAlumno.legajo,2,MAX_LEGAJO,MIN_LEGAJO) == 0 &&
			utn_getString("\nNombre:","\nError, no es un nombre",bufferAlumno.nombre,2,LONG_NOMBRE) == 0)
		{
			bufferAlumno.isEmpty = FALSE;
			arrayAlumnos[indice] = bufferAlumno;
			retorno = 0;
		}

	}
	else
	{
		if(arrayAlumnos[indice].isEmpty == 0)
		{
			printf("YA HAY DATOS CARGADOS EN DICHO INDICE\n");
		}
	}
	return retorno;
}

/*
 * \brief alumno_modificar: Modifica los datos de un alumno solo si el indice corresponde a un NO Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 */

int alumno_modificar(Alumno arrayAlumnos[],int limite,int indice)
{
	//RECONOCE SI EL INDICE ESTA VACIO PERO NO SOBREESCRIBE EL INDICE YA CARGADO
	int retorno = -1;
	Alumno bufferAlumno;

	if(	arrayAlumnos != NULL &&
		limite > 0 &&
		indice >=0 &&
		indice < limite &&
		arrayAlumnos[indice].isEmpty == FALSE)
	{
		if(	utn_getEntero("\nLegajo:","\nError",&bufferAlumno.legajo,2,MAX_LEGAJO,MIN_LEGAJO) == 0 &&
		utn_getString("\nNombre:","\nError",bufferAlumno.nombre,2,LONG_NOMBRE) == 0)
		{
			bufferAlumno.isEmpty = FALSE;
			arrayAlumnos[indice] = bufferAlumno;
			retorno = 0;
		}
	}
	else
	{
		printf("NO SE ENCUENTRAN DATOS CARGADOS EN DICHO INDICE\n");
	}
	return retorno;
}

/*
 * \brief alumno_baja: Realiza la baja de un alumno solo si el indice corresponde a un Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int indice, es el indice de donde se dara de baja el alumno
 * \return (-1) Error / (0) Ok
 */

int alumno_baja(Alumno arrayAlumnos[],int limite,int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(arrayAlumnos != NULL &&
	   limite > 0 &&
	   indice >=0 &&
	   indice < limite &&
	   arrayAlumnos[indice].isEmpty == FALSE)
	{

			bufferAlumno.isEmpty = TRUE;
			arrayAlumnos[indice] = bufferAlumno;
			retorno = 0;
			printf("Alumno %s dado de baja.\n", arrayAlumnos[indice].nombre);
	}
	else
	{
		printf("NO SE ENCUENTRAN DATOS CARGADOS EN DICHO INDICE\n");
	}
	return retorno;
}

/*
 * \brief alumno_ordenarPorNombre: Ordena el struct por el  parametro nombre
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite del array
 * \return (-1) Error / (0) Ok
 */

int alumno_ordenarPorNombre(Alumno arrayAlumnos[],int limite)
{
	int retorno = -1;
	int indice;
	int ordenado;

	Alumno bufferAlumno;

	if(arrayAlumnos != NULL && limite > 0 )
	{
		do
		{
			ordenado = 0;
			for(indice = 0; indice < limite-1;indice++)
			{
				if(strcmp(arrayAlumnos[indice].nombre,arrayAlumnos[indice+1].nombre)==1)
					{
						ordenado = 1;
						bufferAlumno = arrayAlumnos[indice];
						arrayAlumnos[indice] = arrayAlumnos[indice+1];
						arrayAlumnos[indice+1] = bufferAlumno;
					}
			}
			retorno = 0;
		}while(ordenado == 1);
		printf("Ordenando....\n");
	}
	return retorno;
}

int alumno_ordenarPorLegajo(Alumno arrayAlumnos[],int limite)
{
	int retorno = -1;
	int indice;
	int ordenado;

	Alumno bufferAlumno;

	if(arrayAlumnos != NULL && limite > 0 )
	{
		do
		{
			ordenado = 0;
			for(indice = 0; indice < limite-1;indice++)
			{
				if(arrayAlumnos[indice].legajo > arrayAlumnos[indice+1].legajo)
					{
						ordenado = 1;
						bufferAlumno = arrayAlumnos[indice];
						arrayAlumnos[indice] = arrayAlumnos[indice+1];
						arrayAlumnos[indice+1] = bufferAlumno;
					}
			}
			retorno = 0;
		}while(ordenado == 1);
		printf("Ordenando....\n");
	}
	return retorno;
}

/*
 * \brief alumno_imprimir: Imprime los alumnos cargados
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 */

int alumno_imprimir(Alumno arrayAlumnos[], int limite)
{
	int retorno = -1;
	if(arrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(arrayAlumnos[i].isEmpty == FALSE)
			{
				printf("Nombre: %s - Legajo: %d\n",arrayAlumnos[i].nombre,arrayAlumnos[i].legajo);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/*
 * \brief Inicializa el array de alumnos
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 */

int alumno_initArray(Alumno arrayAlumnos[], int limite)
{
	int retorno = -1;
	if(arrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			arrayAlumnos[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}


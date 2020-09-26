//alumno.c

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "mi_biblioteca.h"
#include "alumno.h"

static int generarNuevoId(void);

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
		indice < limite)
	{
		if(	utn_getEntero("\nLegajo:","\nError(1 A 9999).",&bufferAlumno.legajo,2,MAX_LEGAJO,MIN_LEGAJO) == 0 &&
			utn_getString("\nNombre:","\nError, no es un nombre.",bufferAlumno.nombre,2,LONG_NOMBRE) == 0)
		{
			bufferAlumno.id = generarNuevoId();
			bufferAlumno.isEmpty = FALSE;
			arrayAlumnos[indice] = bufferAlumno;
			retorno = 0;
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

int alumno_modificar(Alumno arrayAlumnos[],int limite,int indice, int id)
{
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
			bufferAlumno.id = id;
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

	retorno = 0;

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
				printf("Indice: %d ID: %d Nombre: %s - Legajo: %d\n",i, arrayAlumnos[i].id, arrayAlumnos[i].nombre,arrayAlumnos[i].legajo);
			}
			else
			{
				printf("EL INDICE %d NO POSEE DATOS.\n", i);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int alumno_imprimirIndice(Alumno arrayAlumnos[], int limite,int indice)
{
	int retorno = -1;

	if(arrayAlumnos != NULL &&
	   limite > 0 &&
	   indice >=0 &&
	   indice < limite &&
	   arrayAlumnos[indice].isEmpty == FALSE)
	{

		printf("\nID: %d Nombre: %s - Legajo: %d\n",arrayAlumnos[indice].id, arrayAlumnos[indice].nombre,arrayAlumnos[indice].legajo);
	}
	else
	{
		printf("\nNO SE ENCUENTRAN DATOS CARGADOS EN DICHO INDICE\n");
	}

	retorno = 0;

	return retorno;
}

int alumno_checkPrimerIndiceVacio(Alumno pArrayAlumnos[], int limite, int *indice)
{
	int retornar = -1;
	if(pArrayAlumnos != NULL && indice != NULL && limite >0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayAlumnos[i].isEmpty == TRUE)
			{
				*indice = i;
				retornar = 0;
				break;
			}
		}
	}
	return retornar;
}

int alumno_listPrimerIndiceVacio(Alumno arrayAlumnos[],int limite)
{
	int retorno = -1;

	if(arrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(arrayAlumnos[i].isEmpty == TRUE)
			{
				printf("\nEl primer indice vacio es el %d.\n", i);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int alumno_listIndiceVacio(Alumno arrayAlumnos[],int limite,int indice)
{
	int retorno = -1;

	if(arrayAlumnos != NULL && limite > 0 && indice >=0 && indice < limite)
	{
		if(arrayAlumnos[indice].isEmpty == TRUE)
		{
			printf("\nEl indice %d esta vacio.\n", indice);
			retorno = 0;
		}
		else
		{
			printf("\nEl indice %d esta ocupado.\n", indice);
		}
	}
	return retorno;
}

int alumno_buscarId(Alumno arrayAlumnos[], int limite, int* indice, int id)
{
    int retorno = -1;

    if (arrayAlumnos != NULL && limite > 0)
    {
        for (int i = 0; i < limite; i++)
        {
            if(arrayAlumnos[i].isEmpty == FALSE )
            {
                if(arrayAlumnos[i].id == id)
                {
                   *indice = i;
                   retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int alumno_printById(Alumno arrayAlumnos[],int limite,int *id)
{
	int retorno = -1;


	if(arrayAlumnos != NULL && limite > 0 && id != NULL)
	{
		for(int i=0;i<limite;i++)
		{
			if(arrayAlumnos[i].id == *id)
			{
				printf("\nID: %d Posicion: %d Nombre: %s - Legajo: %d\n",arrayAlumnos[i].id,i, arrayAlumnos[i].nombre,arrayAlumnos[i].legajo);
				retorno = 0;
				break;
			}
		}
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


static int generarNuevoId(void)
{
	static int id;

	id = id+1;
	return id;
}


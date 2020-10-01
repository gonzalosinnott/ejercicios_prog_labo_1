/*
 ============================================================================
 Name        : clase_10a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description : Estructuras III (continuacion)
 1-Generar una nueva entidad

 ============================================================================
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "mi_biblioteca.h"
#include "alumno.h"
#include "nacion.h"

int main(void){

	int choosenOption;
	int firstLoad = FALSE;

	Alumno arrayAlumnos[QTY_ALUMNOS];
	initStudent(arrayAlumnos, QTY_ALUMNOS);

	do
	{
		getMenu(&choosenOption);
		switch(choosenOption)
		{
			case 1://ALTA
				altaAlumno(arrayAlumnos, QTY_ALUMNOS, &firstLoad);
				break;
			case 2://MODIFICAR
				modifyEntry(arrayAlumnos, QTY_ALUMNOS,firstLoad);
				break;
			case 3://BAJA
				removeEntry(arrayAlumnos, QTY_ALUMNOS, &firstLoad);
				break;
			case 4:
				break;
			case 5://INFORME
				getStudentReport(arrayAlumnos, QTY_ALUMNOS, firstLoad);
				break;

		}
	}while(choosenOption!=6);
	printf("PROGRAMA TERMINADO");
	return EXIT_SUCCESS;
}


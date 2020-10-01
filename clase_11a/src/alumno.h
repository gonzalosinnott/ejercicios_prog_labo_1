/**
 ============================================================================
 Name        : mi_biblioteca.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Header for library alumno.c
 ============================================================================
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MIN_LEGAJO 1
#define MAX_LEGAJO 9999

typedef struct
{
	int id;
	char apellido[LONG_NOMBRE];
	char nombre[LONG_NOMBRE];
	int legajo;
	int isEmpty;
}Alumno;

int getMenu(int* choosenOption);
int initStudent(Alumno* list, int len);
int altaAlumno(Alumno* list,int len, int *firstLoad);
int modifyEntry(Alumno* list, int len, int firstLoad);
int removeEntry(Alumno* list, int len,int *firstLoad);
int getStudentReport(Alumno* list, int len, int firstLoad);

#endif /* ALUMNO_H_ */

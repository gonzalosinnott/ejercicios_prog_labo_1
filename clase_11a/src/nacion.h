/**
 ============================================================================
 Name        : mi_biblioteca.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Header for library alumno.c
 ============================================================================
 */

#ifndef NACION_H_
#define NACION_H_

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_NACIONALIDAD 5
#define MIN_CODIGOINT 1
#define MAX_CODIGOINT 9999

typedef struct
{
	int id;
	char pais[LONG_NOMBRE];
	char provincia[LONG_NOMBRE];
	int codigoInt;
	int isEmpty;
}Nacionalidad;

int nacionalidad_getMenu(int* choosenOption);
int nacionalidad_initNacionalidad(Nacionalidad* list, int len);
int nacionalidad_alta(Nacionalidad* list,int len, int *firstLoad);
int nacionalidad_modifyEntry(Nacionalidad* list, int len, int firstLoad);
int nacionalidad_removeEntry(Nacionalidad* list, int len,int *firstLoad);
int nacionalidad_getReport(Nacionalidad* list, int len, int firstLoad);

#endif /* NACION_H_ */

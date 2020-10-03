/**
 ============================================================================
 Name        : pantalla.h
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Header for library pantalla.c
 ============================================================================
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_PANTALLAS 5


typedef struct
{
	int id;
	char name[LONG_NOMBRE];
	char address[LONG_NOMBRE];
	int pantallaType;
	float pricePerDay;
	int isEmpty;
}Pantalla;

//INICIALIZAR
int initPantalla(Pantalla* list, int len);

//ALTA
int pantalla_alta(Pantalla* list,int len, int *firstLoad);
int publicidad_publicidad_checkFirstEmptyIndex(Pantalla* list, int len, int *emptyIndex);
int pantalla_getForm(char *name, char *address, int *type,float *pricePerDay);
int pantalla_addData(Pantalla* list,int len,int id,char name[], char address[], int pantallaType,float pricePerDay);
//MODIFICAR Y BAJA
int pantalla_findById(Pantalla* list, int len,int id);
//MODIFICAR
int pantalla_modifyMenu(Pantalla* list, int len, int firstLoad);
int pantalla_modify(Pantalla* list, int len,int id);
//BAJA
int pantalla_removeMenu(Pantalla* list, int len,int *firstLoad);
int pantalla_remove(Pantalla* list, int len,int id);
//INFORME
int pantalla_getReport(Pantalla* list, int len, int firstLoad);
int pantalla_sort(Pantalla* list, int len, int order);
int pantalla_sortByLastName(Pantalla* list, int len, int order);
int pantalla_sortByFileNumber(Pantalla* list, int len, int order);
int pantalla_print(Pantalla* list, int len);

#endif /* PANTALLA_H_ */

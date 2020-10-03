/**
 ============================================================================
 Name        : publicidad.h
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Header for library publicidad.c
 ============================================================================
 */
#ifndef PUBLICIDAD_H_
#define PUBLICIDAD_H_

#define TRUE 1
#define FALSE 0
#define MAX_CUIL 1
#define MIN_CUIL 9999999
#define LONG_NOMBRE 50
#define QTY_PUBLICIDADES 1000


typedef struct
{
	int id;
	int cuit;
	char publicidadName[LONG_NOMBRE];
	int publicidadDuracion;
	int isEmpty;
}Publicidad;

//INICIALIZAR
int initPublicidad(Publicidad* list, int len);

//ALTA
int publicidad_alta(Publicidad* list,int len, int *firstLoad);
int publicidad_checkFirstEmptyIndex(Publicidad* list, int len, int *emptyIndex);
int publicidad_getForm(int *cuit,char publicidadName[],int *publicidadDuracion);
int publicidad_addData(Publicidad* list,int len,int id,int cuit, char publicidadName[], int publicidadDuracion);
//MODIFICAR Y BAJA
int publicidad_findById(Publicidad* list, int len,int id);
//MODIFICAR
int publicidad_modifyMenu(Publicidad* list, int len, int firstLoad);
int publicidad_modify(Publicidad* list, int len,int id);
//BAJA
int publicidad_removeMenu(Publicidad* list, int len,int *firstLoad);
int publicidad_remove(Publicidad* list, int len,int id);
//INFORME
int publicidad_getReport(Publicidad* list, int len, int firstLoad);
int publicidad_sort(Publicidad* list, int len, int order);
int publicidad_sortByLastName(Publicidad* list, int len, int order);
int publicidad_sortByFileNumber(Publicidad* list, int len, int order);
int publicidad_print(Publicidad* list, int len);


#endif /* PUBLICIDAD_H_ */

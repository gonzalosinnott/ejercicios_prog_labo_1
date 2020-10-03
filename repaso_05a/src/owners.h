/**
 ============================================================================
 Name        : PETS.h
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Header for library owners.c
 ============================================================================
 */

#ifndef OWNERS_H_
#define OWNERS_H_


#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_OWNERS 50

typedef struct
{
	int owner_id;
	char owner_name[LONG_NOMBRE];
	int owner_isEmpty;
}Owners;

//INICIALIZAR
int initOwners(Owners* owner_list, int owner_len);
int owner_addHardcode(Owners* owner_list, int owner_len, int *owner_firstLoad);
//ALTA
int owner_alta(Owners* owner_list,int owner_len, int *owner_firstLoad);
int owner_checkFirstEmptyIndex(Owners* owner_list, int owner_len, int *owner_emptyIndex);
int owner_getForm(char *owner_name);
int owner_addData(Owners* owner_list,int owner_len,int owner_id,char owner_name[]);
//MODIFICAR Y BAJA
int owner_findById(Owners* owner_list, int owner_len,int owner_id);
//MODIFICAR
int owner_modifyMenu(Owners* owner_list, int owner_len, int owner_firstLoad);
int owner_modify(Owners* owner_list, int owner_len,int owner_id);
//BAJA
int owner_removeMenu(Owners* owner_list, int owner_len,int *owner_firstLoad);
int owner_remove(Owners* owner_list, int owner_len,int owner_id);
//INFORME
int owner_getReport(Owners* owner_list, int owner_len, int owner_firstLoad);
int owner_sort(Owners* owner_list, int owner_len, int order);
int owner_sortByLastName(Owners* owner_list, int owner_len, int order);
int owner_sortByFileNumber(Owners* owner_list, int owner_len, int order);
int owner_print(Owners* owner_list, int owner_len);




#endif /* OWNERS_H_ */

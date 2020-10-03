/**
 ============================================================================
 Name        : PETS.h
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Header for library pets.c
 ============================================================================
 */

#ifndef PETS_H_
#define PETS_H_

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50


typedef struct
{
	int pet_id;
	char pet_name[LONG_NOMBRE];
	char pet_breed[LONG_NOMBRE];
	int pet_age;
	int pet_IdOwner;
	int pet_isEmpty;
}Pets;

//INICIALIZAR
int initPets(Pets* pet_list, int pet_len);
int pet_addHardcode(Pets* pet_list, int pet_len, int *pet_firstLoad);
//ALTA
int pet_alta(Pets* pet_list,int pet_len, int *pet_firstLoad);
int pet_checkFirstEmptyIndex(Pets* pet_list, int pet_len, int *pet_emptyIndex);
int pet_getForm(char *pet_name, char *pet_breed, int *pet_age, int *pet_IdOwner);
int pet_addData(Pets* pet_list,int pet_len, int pet_id, char pet_name[], char pet_breed[], int pet_age, int pet_IdOwner);
//MODIFICAR Y BAJA
int pet_findById(Pets* pet_list, int pet_len,int pet_id);
//MODIFICAR
int pet_modifyMenu(Pets* pet_list, int pet_len, int pet_firstLoad);
int pet_modify(Pets* pet_list, int pet_len,int pet_id);
//BAJA
int pet_removeMenu(Pets* pet_list, int pet_len,int *pet_firstLoad);
int pet_remove(Pets* pet_list, int pet_len,int pet_id);
//INFORME
int pet_getReport(Pets* pet_list, int pet_len, int pet_firstLoad);
int pet_sort(Pets* pet_list, int pet_len, int order);
int pet_print(Pets* pet_list, int pet_len);





#endif /* PANTALLA_H_ */

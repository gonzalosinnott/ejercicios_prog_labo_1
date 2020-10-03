/**
 ============================================================================
 Name        : mi_biblioteca.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Header for library veterinaria.c
 ============================================================================
 */

#ifndef VETERINARIA_H_
#define VETERINARIA_H_

#include "owners.h"
#include "pets.h"


int veterinaria_getMenu(int* choosenOption);
int veterinaria_getReport(Pets* pet_list, int pet_len, Owners* owner_list, int owner_len, int pet_firstLoad, int owner_firstLoad);

#endif /* VETERINARIA_H_ */

/*
 ============================================================================
 Name        : repaso_05a.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description :Hardcodear las estructuras correspondientes.
	En un menu:
	1. Alta mascota:
	2. Baja de mascota(baja logica)
	3. -
	4. Listar:
    a. Todas las mascotas
    b. Todos los dueños
    c. Todas las mascotas con sus dueños
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utn.h"
#include "veterinaria.h"
#include "owners.h"
#include "pets.h"


#define QTY_PETS 20
#define QTY_OWNERS 50

int main(void){

	int choosenOption;
	int pet_firstLoad = FALSE;
	int owner_firstLoad = FALSE;

	Pets arrayPets[QTY_PETS];
	Owners arrayOwners[QTY_OWNERS];

	initPets(arrayPets, QTY_PETS);
	initOwners(arrayOwners, QTY_OWNERS);

	pet_addHardcode(arrayPets, QTY_PETS, &pet_firstLoad);
	owner_addHardcode(arrayOwners, QTY_OWNERS, &owner_firstLoad);

	do
	{
		veterinaria_getMenu(&choosenOption);
		switch(choosenOption)
		{
			case 1://ALTA MASCOTAS NO FUNCIONA LA EDAD
				pet_alta(arrayPets, QTY_PETS, &pet_firstLoad);
				break;
			case 2://BAJA MASCOTAS
				pet_removeMenu(arrayPets, QTY_PETS, &pet_firstLoad);
				break;
			case 3:
				pet_modifyMenu(arrayPets, QTY_PETS, pet_firstLoad);
				break;
			case 4://INFORME // DARLE FOMRATO
				veterinaria_getReport(arrayPets, QTY_PETS, arrayOwners, QTY_OWNERS, pet_firstLoad, owner_firstLoad);
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;

		}
	}while(choosenOption!=10);
	printf("PROGRAMA TERMINADO");
	return EXIT_SUCCESS;
}

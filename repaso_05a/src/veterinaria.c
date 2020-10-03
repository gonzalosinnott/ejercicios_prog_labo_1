/**
 ============================================================================
 Name        : veterinaria.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Library veterinaria.c
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


int veterinaria_getMenu(int* choosenOption)
{
	int retorno = -1;
	if(utn_getIntNumber("\nIngrese una opcion:"
					   "\n 1-Alta Mascota."
					   "\n 2-Baja Mascota."
					   "\n 3-."
					   "\n 4-Informe."
					   "\n 5-."
					   "\n 6-."
					   "\n 7-."
					   "\n 8-."
					   "\n 9-."
					   "\n 10- Salir."
					   "\nOpcion:", "\nError.", choosenOption, 3, 11, 1)==0)
	{
		retorno =0;
	}
	else
	{
		*choosenOption = 10;
	}
	return retorno;
}

/**
 * \brief getMenu: Menu for choosing options of the program,
 * \param choosenOption* list: Pointer to variable that stores choosen option
 * \return (-1) Error / (0) Ok
 */

int veterinaria_getReport(Pets* pet_list, int pet_len, Owners* owner_list, int owner_len, int pet_firstLoad, int owner_firstLoad)
{
	int retorno = -1;
	int choosenOption;

	if(pet_firstLoad == FALSE || owner_firstLoad == FALSE)
	{

		printf("\nERROR. NO HAY DATOS INGRESADOS.\n");

	}
	else
	{
		if(utn_getIntNumber("\nIngrese una opcion:"
				   	   	   	"\n 1-Informe Mascotas."
				   	        "\n 2-Informe Dueños."
				            "\n 3-Informe Completo."
				            "\n 4-Volver al Menu principal."
				            "\nOpcion:", "\nError.", &choosenOption, 3, 3, 1)==0)
		{
			switch(choosenOption)
			{
				case 1:
					pet_getReport(pet_list, pet_len, pet_firstLoad);
					break;
				case 2:
					owner_getReport(owner_list, owner_len, owner_firstLoad);
					break;
			}
		}
		retorno = 0;
	}
	return retorno;
}

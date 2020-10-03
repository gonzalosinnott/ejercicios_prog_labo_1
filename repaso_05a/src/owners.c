 /**
 ============================================================================
 Name        : owners.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Library owners.c
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

int owner_addHardcode(Owners* owner_list, int owner_len, int *owner_firstLoad)
{
	int retorno = -1;
	if(owner_list != NULL && owner_len >0)
	{
		 int owner_id[]={1,2,3,4,5};
		 char owner_name[][30]={"Juan","Maria","Raquel","Jose","Luisa"};

		for(int i = 0; i < 5; i++)
		{
			owner_addData(owner_list, owner_len, owner_id[i], owner_name[i]);
		}
		*owner_firstLoad = TRUE;
	}
	return retorno;
}


static int generateNewId(void);

/**
 * \brief initOwners: To indicate that all positions in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all position of the array
 * \param sEmployee* owner_list: Pointer to array of employees
 * \param int owner_len: Array owner_length
 * \return (-1) Error / (0) Ok
 */

int initOwners(Owners* owner_list, int owner_len)
{
	int retorno = -1;
	if(owner_list != NULL && owner_len > 0)
	{
		for(int i=0;i<owner_len;i++)
		{
			owner_list[i].owner_isEmpty= TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/**
 *  \brief owner_alta: Asks the user for the owner data
 * \param Owners* owner_list: Pointer to array of owners
 * \param int owner_len: Array owner_length
 * \param int owner_firstLoad: Pointer to space in memory where is the
 *  variable to indicate if an entry is loaded
 * \return (-1) Error / (0) Ok
 */

int owner_alta(Owners* owner_list,int owner_len, int *owner_firstLoad)
{
	int retorno = -1;
	int owner_id;
	char owner_name[LONG_NOMBRE];
	int index;

	if(owner_list != NULL && owner_len > 0 && owner_firstLoad >0 && owner_checkFirstEmptyIndex(owner_list, owner_len, &index)==0)
	{
		if(owner_getForm(owner_name)== 0)
		{
			owner_id=generateNewId();
			if(owner_addData(owner_list, owner_len, owner_id, owner_name)==0)
			{
				*owner_firstLoad = TRUE;
				retorno=0;
			}
		}
		else
		{
			printf("\nERROR EN LA CARGA DEL EMPLEADO.\n");
		}
	}
	else
	{
		printf("\nNO SE PUEDEN CARGAR MAS REGISTROS.\n");
	}
	return retorno;
}

/**
 *  \brief checkFirstEmptyIndex: Checks first empty index in the array
 * this function search the array for the first index with the value TRUE in the isEmpty item
 * \param sEmployee* owner_list: Pointer to array of employees
 * \param int owner_len: Array owner_length
 * \param int *EmptyIndex: Pointer to position of first empty index.
 * \return (-1) Error / (0) Ok
 */

int owner_checkFirstEmptyIndex(Owners* owner_list, int owner_len, int *emptyIndex)
{
	int retorno = -1;
	if(owner_list != NULL && owner_len >0 && emptyIndex != NULL)
	{
		for(int i = 0; i < owner_len; i++)
		{
			if(owner_list[i].owner_isEmpty == TRUE)
			{
				*emptyIndex = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 *  \brief owner_getForm: Brings up a menu for the user to complete with info
 * \param char *owner_name: Pointer to place to store owner_name
 * \param char *lastName: Pointer to place to store last owner_name
 * \param float *salary: Pointer to place to store salary
 * \param int *sector: Pointer to place to store sector
 * \return (-1) Error / (0) Ok
 */

int owner_getForm(char *owner_name)
{
	int retorno = -1;

	if(owner_name != NULL)
	{
		if(utn_getString("Ingrese Nombre deL Dueño:", "Error. ", owner_name, 3, LONG_NOMBRE)==0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

/**
 *  \brief generateNewId: Generates a new ID that's +1 from previous loaded employee ID.
 */

static int generateNewId(void)
{
	static int id;

	id = id+1;
	return id;
}

/**
 *  \brief owner_addData: add in a existing owner_list of employees the values received
 *  as parameters in the first empty position.
 * \param Employee* owner_list: Pointer to array of employees
 * \param int owner_len: Array owner_length
 * \param int id: id generated by generateNewId() function
 * \param char owner_name[]: Input by user from getEmployeeForm
 * \param char lastName[]: Input by user from getEmployeeForm
 * \param float salary: Input by user from getEmployeeForm
 * \param int sector: Input by user from getEmployeeForm
 * \return (-1) Error / (0) Ok
 */

int owner_addData(Owners* owner_list,int owner_len,int owner_id,char owner_name[])
{
	int retorno = -1;
	int emptyIndex;

	if(owner_checkFirstEmptyIndex(owner_list, owner_len, &emptyIndex)==0)
	{
		owner_list[emptyIndex].owner_id=owner_id;
		strcpy(owner_list[emptyIndex].owner_name,owner_name);
		owner_list[emptyIndex].owner_isEmpty=FALSE;
		retorno=0;
	}

    return retorno;
}

/**
 *  \brief owner_findById: find an Employee by Id then returns the index position in array.
 * \param Employee* owner_list: Pointer to array of employees
 * \param int owner_len: Array owner_length
 * \param int id: id to search
 * \return Return employee index position or (-1) if ERROR
 */

int owner_findById(Owners* owner_list, int owner_len,int id)
{
	int retorno;

	if (owner_list != NULL && owner_len > 0 && id > 0)
	{
		for (int i = 0; i < owner_len; i++)
		{
			if(owner_list[i].owner_isEmpty == FALSE && owner_list[i].owner_id == id )
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;;
}

/**
 * \brief owner_modifyMenu: Modifies the data of an Employee by given Id.
 * Allows to modify individual fields of the employee by a switch
 * \param Employee* owner_list: Pointer to array of employees
 * \param int owner_len: Array owner_length
 * \param int owner_firstLoad: variable to check if there is even one entry loaded
 * \return (-1) Error / (0) Ok
 */

int owner_modifyMenu(Owners* owner_list, int owner_len, int owner_firstLoad)
{
	int retorno = -1;
	int idToSearch;

	if(owner_firstLoad == FALSE)
	{
		printf("\nERROR. NO HAY DATOS INGRESADOS.\n");
	}
	else
	{
		if(utn_getIntNumber("Ingrese el ID a modificar:","Error, no es un ID valido. ",&idToSearch,3,INT_MAX,1)==0 &&
		   owner_modify(owner_list,owner_len,idToSearch)== 0)
		{
			retorno = 0;
		}
		else
		{
			printf("\nERROR, ID INEXISTENTE.\n");
		}
	}
	return retorno;
}

/**
 * \brief owner_modify: Modifies the data of an Employee by given Id.
 * Allows to modify individual fields of the employee by a switch
 * \param Employee* owner_list: Pointer to array of employees
 * \param int owner_len: Array owner_length
 * \param int owner_firstLoad: variable to check if there is even one entry loaded
 * \return (-1) Error / (0) Ok
 */

int owner_modify(Owners* owner_list, int owner_len,int id)
{
	int retorno = -1;
	int choosenOption;
	char answer;
	int indexToModify;

	Owners bufferOwners;

	indexToModify = owner_findById(owner_list, owner_len, id);

	if(owner_list != NULL && owner_len>0 && id > 0 && indexToModify > -1)
	{
		do
		{
			printf("Owners a modificar\n");
			printf("Nombre del Dueño: %s\n",
					owner_list[indexToModify].owner_name);
			if(utn_getIntNumber("\nQue campo desea modificar:"
								"\n 1-Nombre."
								"\nOpcion:", "\nError.", &choosenOption, 3, 1, 1)==0)
		{
			switch(choosenOption)
			{
				case 1:
					if(utn_getString("\nNombre:","\nError. ",bufferOwners.owner_name,2,LONG_NOMBRE)==0)
					{
						strcpy(owner_list[indexToModify].owner_name,bufferOwners.owner_name);
					}
			}
		}
		utn_getChar("¿Desea seguir modificando este ID?(Y/N)", "Error. ", &answer, 'Y', 'N', 3);
		}while(answer!='N');
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief owner_removeMenu: Remove a Employee by Id (put isEmpty Flag in TRUE)
 * \param Employee* owner_list: Pointer to array of employees
 * \param int owner_len: Array owner_length
 * \param int *owner_firstLoad: variable to check if there is even one entry loaded and
 *  safeguard to prevent errors if all data is erased
 * \return (-1) Error / (0) Ok
 */

int owner_removeMenu(Owners* owner_list, int owner_len,int *owner_firstLoad)
{
	int retorno = -1;
	int idToSearch;

	if(*owner_firstLoad == FALSE)
	{
		printf("\nERROR. NO HAY DATOS INGRESADOS.\n");
	}
	else
	{
		if(utn_getIntNumber("Ingrese el ID a eliminar:","Error, no es un ID valido. ",&idToSearch,3,INT_MAX,1)==0 &&
		   owner_remove(owner_list,owner_len,idToSearch)== 0)
		{
			for(int i = 0; i < owner_len; i++)
			{
				if(owner_list[i].owner_isEmpty == TRUE)
				{
					*owner_firstLoad = FALSE;
				}
				else
				{
					*owner_firstLoad = TRUE;
					break;
				}
			}
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief owner_remove: Remove a Employee by Id (put isEmpty Flag in TRUE)
 * \param Employee* owner_list: Pointer to array of employees
 * \param int owner_len: Array owner_length
 * \param int id: id value of entry to remove
 *  safeguard to prevent errors if all data is erased
 * \return (-1) Error / (0) Ok
 */

int owner_remove(Owners* owner_list, int owner_len,int id)
{
	int retorno = -1;
	int indexToModify;
	char answer;

	indexToModify = owner_findById(owner_list, owner_len, id);

	if(owner_list != NULL && owner_len>0 && id > 0 && indexToModify > -1)
	{
		printf("Owners a eliminar\n");
		printf("Nombre: %s \n", owner_list[indexToModify].owner_name);
		utn_getChar("¿Desea eliminar este ID?(Y/N)", "Error. ", &answer, 'Y', 'N', 3);
		switch(answer)
		{
			case 'Y':
				owner_list[indexToModify].owner_isEmpty = TRUE;
				printf("REGISTRO DE EMPLEADO BORRADO CON EXITO.");
				break;
			case'N':
				printf("REGISTRO NO BORRADO");
				break;
			default:
				printf("ERROR, INGRESE 'Y' PARA BORRAR EL REGISTRO.");
		}
		retorno = 0;
	}
	else
	{
		printf("\nERROR, ID INEXISTENTE.\n");
	}
	return retorno;
}

/**
 *  \brief owner_getReport: Reports employees by alphabetical order and numerical order
 *  of sector. Also gives info about total money spend on salaries, average salary and
 *  how many employees have a salary above the average.
 * \param Employee* owner_list: Pointer to array of employees
 * \param int owner_len: Array owner_length
 * \param int owner_firstLoad: variable to check if there is even one entry loaded
 * \return (-1) Error / (0) Ok
 */

int owner_getReport(Owners* owner_list, int owner_len, int owner_firstLoad)
{
	int retorno = -1;
	int sortOrder;

	if(owner_firstLoad == FALSE)
	{

		printf("\nERROR. NO HAY DATOS INGRESADOS.\n");

	}
	else
	{
		if(utn_getIntNumber("\n1- Orden Descendente"
						    "\n2- Orden Ascendente"
						    "\nOpcion:","Error. ",&sortOrder,3,2,1)==0)
		{
			if(owner_list!= NULL && owner_len > 0)
			{
				owner_sort(owner_list, owner_len, sortOrder);
				owner_print(owner_list, owner_len);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 *  \brief owner_sort: Sort the elements in the array of employees, the argument order
 * indicate UP or DOWN order
 * \param Employee* owner_list: Pointer to array of employees
 * \param int owner_len: Array owner_length
 * \param int order: [2] indicate UP (order Z->A) - [1] indicate DOWN (order A->Z)
 * \return (-1) Error / (0) Ok
 */

int owner_sort(Owners* owner_list, int owner_len, int order)
{
	int retorno = -1;
	int sorted;
	Owners bufferOwners;

	if(owner_list != NULL && owner_len > 0 && (order == 1 || order == 2))
	do
	{
		sorted = TRUE;
		for(int i = 0; i < (owner_len-1); i++)
		{
			if((order == 1 &&
				strncmp(owner_list[i].owner_name, owner_list[i + 1].owner_name,LONG_NOMBRE)>0) ||
			   (order == 2 &&
				strncmp(owner_list[i].owner_name, owner_list[i + 1].owner_name,LONG_NOMBRE)<0))
			{
				bufferOwners = owner_list[i];
				owner_list[i] = owner_list[i + 1];
				owner_list[i + 1] = bufferOwners;
				sorted = FALSE;
			}
		}
	}while(sorted == FALSE);
	retorno = 0;
	return retorno;
}

/**
 * \brief owner_print: print the content of employees array
 * \param Employee* owner_list: Pointer to array of employees
 * \param int owner_len: Array owner_length
 * \return (-1) Error / (0) Ok*
 */

int owner_print(Owners* owner_list, int owner_len)
{
	int retorno = -1;
	if(owner_list != NULL && owner_len > 0)
	{
		printf("\nID |Nombre\n");
		for(int i=0;i< owner_len ;i++)
		{
			if(owner_list[i].owner_isEmpty == FALSE)
			{
				printf("%d %-15s\n",owner_list[i].owner_id,owner_list[i].owner_name);
			}
		}
		retorno = 0;
	}
	return retorno;
}
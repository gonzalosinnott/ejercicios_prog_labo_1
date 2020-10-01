 /**
 ============================================================================
 Name        : utn.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Library alumno.c
 ============================================================================
 */

#include "nacion.h"

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "mi_biblioteca.h"

static int nacionalidad_checkFirstEmptyIndex(Nacionalidad* list, int len, int *emptyIndex);
static int nacionalidad_getForm(char *name, char *lastName, int *fileNumber);
static int nacionalidad_generateNewId(void);
static int nacionalidad_addData(Nacionalidad* list,int len,int id,char name[],char lastName[],int fileNumber);
static int nacionalidad_findById(Nacionalidad* list, int len,int id);
static int nacionalidad_modify(Nacionalidad* list, int len,int id);
static int nacionalidad_remove(Nacionalidad* list, int len,int id);
static int nacionalidad_sort(Nacionalidad* list, int len, int order);
static int nacionalidad_sortByCountry(Nacionalidad* list, int len, int order);
static int nacionalidad_print(Nacionalidad* list, int len);

/**
 * \brief nacionalidad_getMenu: Menu for choosing options of the program,
 * \param choosenOption* list: Pointer to variable that stores choosen option
 * \return (-1) Error / (0) Ok
 */

int nacionalidad_getMenu(int* choosenOption)
{
	int retorno = -1;
	if(utn_getIntNumber("\nIngrese una opcion:"
					   "\n 1-Ingreso de datos."
					   "\n 2-Modificar datos."
					   "\n 3-Baja de datos."
					   "\n 4-Informe individual "
					   "\n 5-Informe Global."
					   "\n 6-Salir"
					   "\nOpcion:", "\nError.", choosenOption, 3, 6, 1)==0)
	{
		retorno =0;
	}
	else
	{
		*choosenOption = 5;
	}
	return retorno;
}

/**
 * \brief nacionalidad_initStudent: To indicate that all positions in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all position of the array
 * \param sEmployee* list: Pointer to array of employees
 * \param int len: Array length
 * \return (-1) Error / (0) Ok
 */

int nacionalidad_initStudent(Nacionalidad* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/**
 *  \brief nacionalidad_altaAlumno: Asks the user for the nationality data
 * \param Alumno* list: Pointer to array of employees
 * \param int len: Array length
 * \param int firstLoad: Pointer to space in memory where is the
 *  variable to indicate if an entry is loaded
 * \return (-1) Error / (0) Ok
 */

int nacionalidad_alta(Nacionalidad* list,int len, int *firstLoad)
{
	int retorno = -1;
	int id;
	char country[LONG_NOMBRE];
	char province[LONG_NOMBRE];
	int codigoInt;
	int index;

	if(list != NULL && len > 0 && firstLoad >0 && nacionalidad_checkFirstEmptyIndex(list, QTY_NACIONALIDAD, &index)==0)
	{
		if(nacionalidad_getForm(country, province, &codigoInt)== 0)
		{
			id=nacionalidad_generateNewId();
			if(nacionalidad_addData(list,QTY_NACIONALIDAD,id,country,province,codigoInt)==0)
			{
				*firstLoad = TRUE;
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
 *  \brief nacionalidad_checkFirstEmptyIndex: Checks first empty index in the array
 * this function search the array for the first index with the value TRUE in the isEmpty item
 * \param sEmployee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int *EmptyIndex: Pointer to position of first empty index.
 * \return (-1) Error / (0) Ok
 */

static int nacionalidad_checkFirstEmptyIndex(Nacionalidad* list, int len, int *emptyIndex)
{
	int retorno = -1;
	if(list != NULL && len >0 && emptyIndex != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
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
 *  \brief getEmployeeForm: Brings up a menu for the user to complete with info
 * \param char *name: Pointer to place to store name
 * \param char *lastName: Pointer to place to store last name
 * \param float *salary: Pointer to place to store salary
 * \param int *sector: Pointer to place to store sector
 * \return (-1) Error / (0) Ok
 */

static int nacionalidad_getForm(char *country, char *province, int *codigoInt)
{
	int retorno = -1;

	if(country != NULL && province != NULL && codigoInt > 0)
	{
		if((utn_getString("Ingrese Pais:", "Error. ", country, 3, LONG_NOMBRE)==0) &&
		   (utn_getString("Ingrese Nombre:", "Error. ", province, 3, LONG_NOMBRE)==0) &&
		   (utn_getIntNumber("Ingrese Codigo Internacional(1-9999): ", "\nError. ", codigoInt, 3, MAX_CODIGOINT, MIN_CODIGOINT)== 0))
		{
			retorno = 0;
		}
	}
	return retorno;
}

/**
 *  \brief nacionalidad_generateNewId: Generates a new ID that's +1 from previous loaded employee ID.
 */

static int nacionalidad_generateNewId(void)
{
	static int id;

	id = id+1;
	return id;
}

/**
 *  \brief nacionalidad_addData: add in a existing list of employees the values received
 *  as parameters in the first empty position.
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int id: id generated by generateNewId() function
 * \param char name[]: Input by user from getEmployeeForm
 * \param char lastName[]: Input by user from getEmployeeForm
 * \param float salary: Input by user from getEmployeeForm
 * \param int sector: Input by user from getEmployeeForm
 * \return (-1) Error / (0) Ok
 */
static int nacionalidad_addData(Nacionalidad* list,int len,int id,char country[],char province[],int codigoInt)
{
	int retorno = -1;
	int emptyIndex;

	if(nacionalidad_checkFirstEmptyIndex(list, QTY_NACIONALIDAD, &emptyIndex)==0)
	{
		list[emptyIndex].id=id;
		strcpy(list[emptyIndex].pais,country);
		strcpy(list[emptyIndex].provincia,province);
		list[emptyIndex].codigoInt=codigoInt;
		list[emptyIndex].isEmpty=FALSE;
		printf("\nEl ID para %s %s es: %d\n",list[emptyIndex].pais,list[emptyIndex].provincia,list[emptyIndex].id);
		retorno=0;
	}

    return retorno;
}

/**
 *  \brief nacionalidad_findById: find an Employee by Id then returns the index position in array.
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int id: id to search
 * \return Return employee index position or (-1) if ERROR
 */

static int nacionalidad_findById(Nacionalidad* list, int len,int id)
{
	int retorno;

	if (list != NULL && len > 0 && id > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id )
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;;
}

/**
 * \brief nacionalidad_modifyEntry: Modifies the data of an Employee by given Id.
 * Allows to modify individual fields of the employee by a switch
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int firstLoad: variable to check if there is even one entry loaded
 * \return (-1) Error / (0) Ok
 */

int nacionalidad_modifyEntry(Nacionalidad* list, int len, int firstLoad)
{
	int retorno = -1;
	int idToSearch;

	if(firstLoad == FALSE)
	{
		printf("\nERROR. NO HAY DATOS INGRESADOS.\n");
	}
	else
	{
		if(utn_getIntNumber("Ingrese el ID a modificar:","Error, no es un ID valido. ", &idToSearch,3,INT_MAX,1)==0 &&
		   nacionalidad_modify(list,QTY_NACIONALIDAD,idToSearch)== 0)
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
 * \brief modifyEmployee: Modifies the data of an Employee by given Id.
 * Allows to modify individual fields of the employee by a switch
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int firstLoad: variable to check if there is even one entry loaded
 * \return (-1) Error / (0) Ok
 */

static int nacionalidad_modify(Nacionalidad* list, int len,int id)
{
	int retorno = -1;
	int choosenOption;
	char answer;
	int indexToModify;

	Nacionalidad bufferNacionalidad;

	indexToModify = nacionalidad_findById(list, QTY_NACIONALIDAD, id);

	if(list != NULL && len>0 && id > 0 && indexToModify > -1)
	{
		do
		{
			printf("Alumno a modificar\n");
			printf("Apellido y Nombre: %s %s Codigo Internacional: %d.\n", list[indexToModify].pais,list[indexToModify].provincia,list[indexToModify].codigoInt);
			if(utn_getIntNumber("\nQue campo desea modificar:"
								"\n 1-Pais."
								"\n 2-Provincia."
								"\n 3-Codigo Internacional."
								"\nOpcion:", "\nError.", &choosenOption, 3, 3, 1)==0)
		{
			switch(choosenOption)
			{
				case 1:
					if(utn_getString("\nApellido:","\nError. ",bufferNacionalidad.pais,2,LONG_NOMBRE)==0)
					{
						strcpy(list[indexToModify].pais,bufferNacionalidad.pais);
					}
					break;
				case 2:
					if(utn_getString("\nNombre:","\nError. ",bufferNacionalidad.provincia,2,LONG_NOMBRE)==0)
					{
						strcpy(list[indexToModify].provincia,bufferNacionalidad.provincia);
					}
					break;
				case 3:
					if(utn_getIntNumber("Legajo(1-9999): ", "\nError. ", &bufferNacionalidad.codigoInt, 3, MAX_CODIGOINT, MIN_CODIGOINT)==0)
					{
						list[indexToModify].codigoInt=bufferNacionalidad.codigoInt;
					}
					break;
			}
		}
		utn_getChar("¿Desea seguir modificando este ID?(Y/N)", "Error. ", &answer, 'Y', 'N', 3);
		}while(answer!='N');
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief removeEntry: Remove a Employee by Id (put isEmpty Flag in TRUE)
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int *firstLoad: variable to check if there is even one entry loaded and
 *  safeguard to prevent errors if all data is erased
 * \return (-1) Error / (0) Ok
 */

int nacionalidad_removeEntry(Nacionalidad* list, int len,int *firstLoad)
{
	int retorno = -1;
	int idToSearch;

	if(*firstLoad == FALSE)
	{
		printf("\nERROR. NO HAY DATOS INGRESADOS.\n");
	}
	else
	{
		if(utn_getIntNumber("Ingrese el ID a eliminar:","Error, no es un ID valido. ",&idToSearch,3,INT_MAX,1)==0 &&
		   nacionalidad_remove(list,QTY_NACIONALIDAD,idToSearch)== 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == TRUE)
				{
					*firstLoad = FALSE;
				}
				else
				{
					*firstLoad = TRUE;
					break;
				}
			}
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief removeEmployee: Remove a Employee by Id (put isEmpty Flag in TRUE)
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int id: id value of entry to remove
 *  safeguard to prevent errors if all data is erased
 * \return (-1) Error / (0) Ok
 */

static int nacionalidad_remove(Nacionalidad* list, int len,int id)
{
	int retorno = -1;
	int indexToModify;
	char answer;

	indexToModify = nacionalidad_findById(list, QTY_NACIONALIDAD, id);

	if(list != NULL && len>0 && id > 0 && indexToModify > -1)
	{
		printf("Entrada a eliminar\n");
		printf("Pais y Provincia: %s %s COdigo Internacional: %d.\n", list[indexToModify].pais,list[indexToModify].provincia,list[indexToModify].codigoInt);
		utn_getChar("¿Desea eliminar este ID?(Y/N)", "Error. ", &answer, 'Y', 'N', 3);
		switch(answer)
		{
			case 'Y':
				list[indexToModify].isEmpty = TRUE;
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
 *  \brief getEmployeeReport: Reports employees by alphabetical order and numerical order
 *  of sector. Also gives info about total money spend on salaries, average salary and
 *  how many employees have a salary above the average.
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int firstLoad: variable to check if there is even one entry loaded
 * \return (-1) Error / (0) Ok
 */

int nacionalidad_getReport(Nacionalidad* list, int len, int firstLoad)
{
	int retorno = -1;
	int sortOrder;

	if(firstLoad == FALSE)
	{

		printf("\nERROR. NO HAY DATOS INGRESADOS.\n");

	}
	else
	{
		if(utn_getIntNumber("\n1- Orden Descendente"
						    "\n2- Orden Ascendente"
						    "\nOpcion:","Error. ",&sortOrder,3,2,1)==0)
		{
			if(list!= NULL && len > 0)
			{
				nacionalidad_sort(list, QTY_NACIONALIDAD, sortOrder);
				nacionalidad_print(list, QTY_NACIONALIDAD);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 *  \brief sortEmployees: Sort the elements in the array of employees, the argument order
 * indicate UP or DOWN order
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int order: [2] indicate UP (order Z->A) - [1] indicate DOWN (order A->Z)
 * \return (-1) Error / (0) Ok
 */

static int nacionalidad_sort(Nacionalidad* list, int len, int order)
{
	int retorno = 0;

	if (list != NULL && len > 0 && order >0)
	{
		nacionalidad_sortByCountry(list, QTY_NACIONALIDAD, order);
		retorno = 0;
	}
	return retorno;
}

/**
 *  \brief sortEmployeeByLastName:sort the elements in the array by last name and name
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int order: [2] indicate UP (order Z->A) - [1] indicate DOWN (order A->Z)
 * \return (-1) Error / (0) Ok
 */

static int nacionalidad_sortByCountry(Nacionalidad* list, int len, int order)
{
	int retorno = -1;
	int sorted;
	Nacionalidad bufferNacionalidad;

	if(list != NULL && len > 0 && (order == 1 || order == 2))
	do
	{
		sorted = TRUE;
		for(int i = 0; i < (len-1); i++)
		{
			if((order == 1 &&
			((strncmp(list[i].pais, list[i + 1].pais,LONG_NOMBRE)>0 ||
			  (strncmp(list[i].pais, list[i + 1].pais,LONG_NOMBRE)==0 &&
			   strncmp(list[i].provincia, list[i + 1].provincia,LONG_NOMBRE)<0)) &&
			   list[i].codigoInt < list[i + 1].codigoInt)) ||
			   (order == 2 &&
			 ((strncmp(list[i].pais, list[i + 1].pais,LONG_NOMBRE)<0 ||
			  (strncmp(list[i].pais, list[i + 1].pais,LONG_NOMBRE)==0 &&
			   strncmp(list[i].provincia, list[i + 1].provincia,LONG_NOMBRE)>0)) &&
			   list[i].codigoInt > list[i + 1].codigoInt)))
			{
				bufferNacionalidad = list[i];
				list[i] = list[i + 1];
				list[i + 1] = bufferNacionalidad;
				sorted = FALSE;
			}

		}
	}while(sorted == FALSE);
	retorno = 0;
	return retorno;
}

/**
 * \brief printEmployees: print the content of employees array
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \return (-1) Error / (0) Ok*
 */

static int nacionalidad_print(Nacionalidad* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		printf("Pais        Provincia          Codigo Internacional  ID\n");
		for(int i=0;i< len ;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("%-15s %-15s %-6d  %-6d\n",list[i].pais,list[i].provincia,list[i].codigoInt, list[i].id);
			}
		}
		retorno = 0;
	}
	return retorno;
}

 /**
 ============================================================================
 Name        : utn.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   :
 Description : Library alumno.c
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "mi_biblioteca.h"
#include "alumno.h"

static int checkFirstEmptyIndex(Alumno* list, int len, int *emptyIndex);
static int getStudentForm(char *name, char *lastName, int *fileNumber);
static int generateNewId(void);
static int addStudent(Alumno* list,int len,int id,char name[],char lastName[],int fileNumber);
static int findStudentById(Alumno* list, int len,int id);
static int modifyStudent(Alumno* list, int len,int id);
static int removeStudent(Alumno* list, int len,int id);
static int sortStudents(Alumno* list, int len, int order);
static int sortStudentsByLastName(Alumno* list, int len, int order);
static int sortStudentsByFileNumber(Alumno* list, int len, int order);
static int printStudent(Alumno* list, int len);

/**
 * \brief getEmployeeMenu: Menu for choosing options of the program,
 * \param choosenOption* list: Pointer to variable that stores choosen option
 * \return (-1) Error / (0) Ok
 */

int getMenu(int* choosenOption)
{
	int retorno = -1;
	if(utn_getIntNumber("\nIngrese una opcion:"
					   "\n 1-Alta de alumno."
					   "\n 2-Modificar datos del alumno."
					   "\n 3-Baja de alumno."
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
 * \brief initEmployees: To indicate that all positions in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all position of the array
 * \param sEmployee* list: Pointer to array of employees
 * \param int len: Array length
 * \return (-1) Error / (0) Ok
 */

int initStudent(Alumno* list, int len)
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
 *  \brief altaAlumno: Asks the user for the student data
 * \param Alumno* list: Pointer to array of employees
 * \param int len: Array length
 * \param int firstLoad: Pointer to space in memory where is the
 *  variable to indicate if an entry is loaded
 * \return (-1) Error / (0) Ok
 */

int altaAlumno(Alumno* list,int len, int *firstLoad)
{
	int retorno = -1;
	int id;
	char name[LONG_NOMBRE];
	char lastName[LONG_NOMBRE];
	int fileNumber;
	int index;

	if(list != NULL && len > 0 && firstLoad >0 && checkFirstEmptyIndex(list, QTY_ALUMNOS, &index)==0)
	{
		if(getStudentForm(name, lastName, &fileNumber)== 0)
		{
			id=generateNewId();
			if(addStudent(list,QTY_ALUMNOS,id,name,lastName,fileNumber)==0)
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
 *  \brief checkFirstEmptyIndex: Checks first empty index in the array
 * this function search the array for the first index with the value TRUE in the isEmpty item
 * \param sEmployee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int *EmptyIndex: Pointer to position of first empty index.
 * \return (-1) Error / (0) Ok
 */

static int checkFirstEmptyIndex(Alumno* list, int len, int *emptyIndex)
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

static int getStudentForm(char *name, char *lastName, int *fileNumber)
{
	int retorno = -1;

	if(name != NULL && lastName != NULL && fileNumber > 0)
	{
		if((utn_getString("Ingrese Apellido:", "Error. ", lastName, 3, LONG_NOMBRE)==0) &&
		   (utn_getString("Ingrese Nombre:", "Error. ", name, 3, LONG_NOMBRE)==0) &&
		   (utn_getIntNumber("Ingrese Legajo(1-9999): ", "\nError. ", fileNumber, 3, MAX_LEGAJO, MIN_LEGAJO)== 0))
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
 *  \brief addEmployees: add in a existing list of employees the values received
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
static int addStudent(Alumno* list,int len,int id,char name[],char lastName[],int fileNumber)
{
	int retorno = -1;
	int emptyIndex;

	if(checkFirstEmptyIndex(list, QTY_ALUMNOS, &emptyIndex)==0)
	{
		list[emptyIndex].id=id;
		strcpy(list[emptyIndex].nombre,name);
		strcpy(list[emptyIndex].apellido,lastName);
		list[emptyIndex].legajo=fileNumber;
		list[emptyIndex].isEmpty=FALSE;
		printf("\nEl ID para %s %s es: %d\n",list[emptyIndex].apellido,list[emptyIndex].nombre,list[emptyIndex].id);
		retorno=0;
	}

    return retorno;
}

/**
 *  \brief findEmployeeById: find an Employee by Id then returns the index position in array.
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int id: id to search
 * \return Return employee index position or (-1) if ERROR
 */

static int findStudentById(Alumno* list, int len,int id)
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
 * \brief modifyEntry: Modifies the data of an Employee by given Id.
 * Allows to modify individual fields of the employee by a switch
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int firstLoad: variable to check if there is even one entry loaded
 * \return (-1) Error / (0) Ok
 */

int modifyEntry(Alumno* list, int len, int firstLoad)
{
	int retorno = -1;
	int idToSearch;

	if(firstLoad == FALSE)
	{
		printf("\nERROR. NO HAY DATOS INGRESADOS.\n");
	}
	else
	{
		if(utn_getIntNumber("Ingrese el ID a modificar:","Error, no es un ID valido. ",&idToSearch,3,INT_MAX,1)==0 &&
		   modifyStudent(list,QTY_ALUMNOS,idToSearch)== 0)
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

static int modifyStudent(Alumno* list, int len,int id)
{
	int retorno = -1;
	int choosenOption;
	char answer;
	int indexToModify;

	Alumno bufferAlumno;

	indexToModify = findStudentById(list, QTY_ALUMNOS, id);

	if(list != NULL && len>0 && id > 0 && indexToModify > -1)
	{
		do
		{
			printf("Alumno a modificar\n");
			printf("Apellido y Nombre: %s %s Legajo: %d.\n", list[indexToModify].apellido,list[indexToModify].nombre,list[indexToModify].legajo);
			if(utn_getIntNumber("\nQue campo desea modificar:"
								"\n 1-Apellido."
								"\n 2-Nombre."
								"\n 3-Legajo."
								"\nOpcion:", "\nError.", &choosenOption, 3, 3, 1)==0)
		{
			switch(choosenOption)
			{
				case 1:
					if(utn_getString("\nApellido:","\nError. ",bufferAlumno.apellido,2,LONG_NOMBRE)==0)
					{
						strcpy(list[indexToModify].apellido,bufferAlumno.apellido);
					}
					break;
				case 2:
					if(utn_getString("\nNombre:","\nError. ",bufferAlumno.nombre,2,LONG_NOMBRE)==0)
					{
						strcpy(list[indexToModify].nombre,bufferAlumno.nombre);
					}
					break;
				case 3:
					if(utn_getIntNumber("Legajo(1-9999): ", "\nError. ", &bufferAlumno.legajo, 3, MAX_LEGAJO, MIN_LEGAJO)==0)
					{
						list[indexToModify].legajo=bufferAlumno.legajo;
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

int removeEntry(Alumno* list, int len,int *firstLoad)
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
		   removeStudent(list,QTY_ALUMNOS,idToSearch)== 0)
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

static int removeStudent(Alumno* list, int len,int id)
{
	int retorno = -1;
	int indexToModify;
	char answer;

	indexToModify = findStudentById(list, QTY_ALUMNOS, id);

	if(list != NULL && len>0 && id > 0 && indexToModify > -1)
	{
		printf("Alumno a eliminar\n");
		printf("Apellido y Nombre: %s %s Legajo: %d.\n", list[indexToModify].apellido,list[indexToModify].nombre,list[indexToModify].legajo);
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

int getStudentReport(Alumno* list, int len, int firstLoad)
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
				printStudent(list, QTY_ALUMNOS);
				sortStudents(list, QTY_ALUMNOS, sortOrder);
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

static int sortStudents(Alumno* list, int len, int order)
{
	int retorno = 0;

	if (list != NULL && len > 0 && order >0)
	{
		sortStudentsByFileNumber(list, QTY_ALUMNOS, order);
		sortStudentsByLastName(list, QTY_ALUMNOS, order);
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

static int sortStudentsByLastName(Alumno* list, int len, int order)
{
	int retorno = -1;
	int sorted;
	Alumno bufferStudent;

	if(list != NULL && len > 0 && (order == 1 || order == 2))
	do
	{
		sorted = TRUE;
		for(int i = 0; i < (len-1); i++)
		{
			if((order == 1 &&
			  (strncmp(list[i].apellido, list[i + 1].apellido,LONG_NOMBRE)>0 ||
			  (strncmp(list[i].apellido, list[i + 1].apellido,LONG_NOMBRE)==0 &&
			   strncmp(list[i].nombre, list[i + 1].nombre,LONG_NOMBRE)>0))) ||
			   (order == 2 &&
			  (strncmp(list[i].apellido, list[i + 1].apellido,LONG_NOMBRE)<0 ||
			  (strncmp(list[i].apellido, list[i + 1].apellido,LONG_NOMBRE)==0 &&
			   strncmp(list[i].nombre, list[i + 1].nombre,LONG_NOMBRE)<0))))
			{
				bufferStudent = list[i];
				list[i] = list[i + 1];
				list[i + 1] = bufferStudent;
				sorted = FALSE;
			}

		}
	}while(sorted == FALSE);
	retorno = 0;
	return retorno;
}


/**
 *  \brief sortEmployeeByLastName:sort the elements in the array by last name and name
 * \param Employee* list: Pointer to array of employees
 * \param int len: Array length
 * \param int order: [2] indicate UP (order Z->A) - [1] indicate DOWN (order A->Z)
 * \return (-1) Error / (0) Ok
 */

static int sortStudentsByFileNumber(Alumno* list, int len, int order)
{
	int retorno = -1;
	int sorted;
	Alumno bufferStudent;

	if(list != NULL && len > 0 && (order == 1 || order == 2))
	do
	{
		sorted = TRUE;
		for(int i = 0; i < (len-1); i++)
		{
			if((order == 1 && list[i].legajo < list[i + 1].legajo) ||
			   (order == 2 && list[i].legajo < list[i + 1].legajo))
			{
				bufferStudent = list[i];
				list[i] = list[i + 1];
				list[i + 1] = bufferStudent;
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

static int printStudent(Alumno* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		printf("\nApellido        Nombre          Legajo  ID\n");
		for(int i=0;i< len ;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("%-15s %-15s %-6d  %-6d\n",list[i].apellido,list[i].nombre,list[i].legajo, list[i].id);
			}
		}
		retorno = 0;
	}
	return retorno;
}

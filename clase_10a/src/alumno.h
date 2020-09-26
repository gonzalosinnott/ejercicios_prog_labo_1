
#ifndef ALUMNO_H_
#define ALUMNO_H_

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MIN_LEGAJO 1
#define MAX_LEGAJO 9999

typedef struct
{
	int id;
	char nombre[LONG_NOMBRE];
	int legajo;
	int isEmpty;
}Alumno;

int alumno_alta(Alumno arrayAlumnos[],int limite,int indice);
int alumno_modificar(Alumno arrayAlumnos[],int limite,int indice, int id);
int alumno_baja(Alumno arrayAlumnos[],int limite,int indice);
int alumno_ordenarPorNombre(Alumno arrayAlumnos[],int limite);
int alumno_ordenarPorLegajo(Alumno arrayAlumnos[],int limite);
int alumno_imprimir(Alumno arrayAlumnos[], int limite);
int alumno_imprimirIndice(Alumno arrayAlumnos[], int limite,int indice);
int alumno_checkPrimerIndiceVacio(Alumno pArrayAlumnos[], int limite, int *indice);
int alumno_listPrimerIndiceVacio(Alumno arrayAlumnos[],int limite);
int alumno_listIndiceVacio(Alumno arrayAlumnos[],int limite,int indice);
int alumno_printById(Alumno arrayAlumnos[],int limite,int *id);
int alumno_buscarId(Alumno arrayAlumnos[], int limite, int* indice, int id);
int alumno_initArray(Alumno arrayAlumnos[], int limite);


#endif /* ALUMNO_H_ */

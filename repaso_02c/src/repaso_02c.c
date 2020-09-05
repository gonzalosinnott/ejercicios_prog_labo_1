/*
 ============================================================================
 Name        : repaso_02c.c
 Author      : Gonzalo Sinnott Segura
 Version     :
 Copyright   : 
 Description :Bibliotecas:

función
//retorna 1 si el sexo es correcto 'f' o 'm'
int validarSexo(char sexoParametro)
en la biblioteca "validacion.h", hacer el ".c"

función
//retorna un sexo valido ('f' o 'm'), pide el dato por "scanf" y lo //validad usando la funcion "validarSexo"
char pedirSexo()
en la bilioteca "funciones.h", hacer el ".c"

##llamar a la funcion en el Main y mostrar el sexo ingresado
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

char pedirSexo();
int validarSexo(char sexoParametro);

int main(void)
{
	char sexo;
	sexo= pedirSexo();
	printf("El sexo ingresado es : %c",sexo);
	return 0;
}

char pedirSexo()
{
    char sexoIngresado;

    printf("Ingrese un sexo valido ('m' o 'f'):");
    __fpurge(stdin);
    scanf("%c",&sexoIngresado);

    while(validarSexo(sexoIngresado)==0)
    {
         printf("Error , reingrese sexo :");
        //fflush(stdin);//solo para windows
        __fpurge(stdin);// solo para linux, aca estamos en linux
        scanf("%c",&sexoIngresado);
    }

    return sexoIngresado;
}

int validarSexo(char sexoParametro)
{
    int retorno;
    retorno =0;
    if (sexoParametro=='f'|| sexoParametro=='m')
    {
     retorno=1;
    }
    return retorno;
}



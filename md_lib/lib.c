#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "slre.h"

int confirmacion(char* mensaje, char op1, char op2,int cantidadIntentos)
{
    char c;
    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%c",&c);
        cantidadIntentos--;
    }while(tolower(c) != tolower(op1) && tolower(c)!= tolower(op2) &&  cantidadIntentos > 0);
    return c == op1;
}

int confirmacionSinReintentos(char* mensaje, char op1, char op2)
{
    return confirmacion(mensaje,op1,op2,0);
}

void swap(void *vp1,void *vp2,int size)
{
  void *buf = malloc(size);
  memcpy(buf,vp1,size);
  memcpy(vp1,vp2,size);
  memcpy(vp2,buf,size);  //memcpy ->inbuilt function in std-c
}

int pedirInt(int *dato,char* msg, int max, int min, char* errorMsg)
{
    char buff[4000];
    long datoAuxiliar;
    short int hayError = 0;
    short int continuar = 1;
    char *charError = NULL;

    do
    {
        hayError = 0;
        printf("%s",msg);
        scanf("%s",buff);
        datoAuxiliar = strtol(buff,&charError,10);
        //VALIDAR datoAuxliar dentro del rango de un INT
        if(*charError != '\0')
        {
            hayError = 1;
            printf("El caracter | %c | no es valido\n",*charError);
        }
        if(!hayError && ( (max != 0 && datoAuxiliar > max)  || datoAuxiliar < min) )
        {
            hayError = 1;
        }

        if(hayError)
        {
            printf("%s",errorMsg);
            continuar = confirmacionSinReintentos("Desea intentar otra vez (s/n)?\n",'s','n');
        }
    }while(continuar && hayError);
    if(!hayError)
    {
        *dato = (int)datoAuxiliar;
        return 0;
    }
    return -1;
}

int pedirLong(long *dato,char* msg, int max, int min, char* errorMsg)
{
    char buff[4000];
    short int hayError = 0;
    short int continuar = 1;
    char *charError = NULL;

    do
    {
        hayError = 0;
        printf("%s",msg);
        scanf("%s",buff);
        *dato = strtol(buff,&charError,10);

        if(*charError != '\0')
        {
            hayError = 1;
            printf("El caracter %c no es valido\n",*charError);
        }

        if(hayError)
        {
            printf("%s",errorMsg);
            continuar = confirmacionSinReintentos("Desea intentar otra vez (s/n)?\n",'s','n');
        }
    }while(continuar && hayError);
    if(!hayError)
    {
        return 0;
    }
    return -1;
}

int pedirString(char* dato,char* msg, int max, int min, char*errorMsg)
{
    char buff[4000];
    short int hayError = 0;
    short int continuar = 1;
    do
    {
        hayError = 0;
        printf("%s",msg);
        fflush(stdin);
        scanf("%[^\n]s",buff);
        if(strlen(buff) > max)
        {
            hayError = 1;
        }
        if(!hayError && strlen(buff) < min)
        {
            hayError = 1;
        }

        if(hayError)
        {
            printf("%s",errorMsg);
            continuar = confirmacionSinReintentos("Desea intentar otra vez?\n",'s','n');
        }
    }while(continuar && hayError);
    if(!hayError)
    {
        strcpy(dato,buff);
        return 0;
    }
    return -1;
}


int pedirStringConFormato(char* dato,char* formato,char* msg, int max, int min, char*errorMsg)
{
    char buff[4000];
    struct slre_cap caps[4];
    short int hayError = 0;
    short int continuar = 1;
    do
    {
        hayError = 0;
        printf("%s",msg);
        fflush(stdin);
        scanf("%[a-zA-Z0-9 ]",buff);

        if (slre_match(formato,buff, strlen(buff), caps, 4, 0) == SLRE_NO_MATCH)
        {
            printf("No cumple el formato\n");
            hayError = 1;
        }

        if(strlen(buff) > max)
        {
            hayError = 1;
        }
        if(!hayError && strlen(buff) < min)
        {
            hayError = 1;
        }

        if(hayError)
        {
            printf("%s",errorMsg);
            continuar = confirmacionSinReintentos("Desea intentar otra vez?\n",'s','n');
        }
    }while(continuar && hayError);
    if(!hayError)
    {
        strcpy(dato,buff);
        return 0;
    }
    return -1;
}


int pedirFloat(float *dato, char* mensaje , char* errorMensaje)
{
    char buff[4000];
    short int hayError = 0;
    short int continuar = 1;
    char *charError = NULL;

    do
    {
        hayError = 0;
        printf("%s",mensaje);
        scanf("%s",buff);
        *dato = strtof(buff,&charError);

        if(*charError != '\0')
        {
            hayError = 1;
            printf("El caracter %c no es valido\n",*charError);
        }

        if(hayError)
        {
            printf("%s",errorMensaje);
            continuar = confirmacionSinReintentos("Desea intentar otra vez (s/n)?\n",'s','n');
        }
    }while(continuar && hayError);
    if(!hayError)
    {
        return 0;
    }
    return -1;
}

void ordenar(void **lista, int size, int (*cmp)(void* ,void*),char order)
{
    int i,j;
    void *auxSwap;
    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if( order == 'a')
            {
                if(cmp(lista[i],lista[j]) > 0)
                {
                    auxSwap = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxSwap;
                }
            }
            if(order == 'd')
            {
                if(cmp(lista[i],lista[j]) < 0)
                {
                    auxSwap = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxSwap;
                }
            }
        }
    }
}

void pausa(char *msg)
{
    char aux;
    printf("%s",msg);
    fflush(stdin);
    scanf("%c",&aux);
    fflush(stdin);
}


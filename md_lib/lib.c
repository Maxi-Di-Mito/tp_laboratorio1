#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int confirmacion(char* mensaje, char op1, char op2,int cantidadIntentos)
{
    char c;
    do
    {
        printf("%s\n",mensaje);
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
  char buf[size];
  memcpy(buf,vp1,size);
  memcpy(vp1,vp2,size);
  memcpy(vp2,buf,size);  //memcpy ->inbuilt function in std-c
}

int pedirInt(int *dato,char* msg, int max, int min, char* errorMsg)
{
    long buff;
    short int error = 0;
    short int continuar = 1;
    do
    {
        if(!error)
        {
            printf("%s",msg);
        }
        error = scanf("%ld",&buff);
        if((buff > max && max !=-1) || (buff < min) || error)
        {
            error = 1;
            printf("%s",errorMsg);
            continuar = confirmacionSinReintentos("Desea continuar S/N\n",'s','n');
        }
    }while(continuar && !error);
    if(!error)
    {
        *dato = (int)buff;
    }
    return continuar;
}

int pedirLong(long *dato,char* msg, int max, int min, char* errorMsg)
{
    long buff;
    short int error = 0;
    short int continuar = 1;
    do
    {
        if(!error)
        {
            printf("%s",msg);
        }
        error = scanf("%ld",&buff);
        if((buff > max && max !=-1) || (buff < min) || error)
        {
            error = 1;
            printf("%s",errorMsg);
            continuar = confirmacionSinReintentos("Desea continuar S/N\n",'s','n');
        }
    }while(continuar && !error);
    if(!error)
    {
        *dato = buff;
    }
    return continuar;
}

int pedirString(char* dato,char* msg, int max, int min, char*errorMsg)
{
    char buff[4000];
    short int error = 0;
    short int continuar = 1;
    do
    {
        if(!error)
        {
            printf("%s",msg);
        }
        error = scanf("%s",buff);
        if((strlen(buff) > max && max !=-1) || (strlen(buff) < min) || error)
        {
            error = 1;
            printf("%s",errorMsg);
            continuar = confirmacionSinReintentos("Desea continuar S/N\n",'s','n');
        }
    }while(continuar && !error);
    if(!error)
    {
        strcpy(dato,buff);
    }
    return continuar;
}

#include <stdio.h>
#include <stdlib.h>
#include "../md_lib/lib.h"
#include "structs.h"
#include "string.h"

void iniciarArray(Persona gente[])
{
    int i;
    for(i=0;i<CANTIDAD;i++)
    {
        gente[i].inUseFlag = 0;
    }
}


void mostrarMenuYElegir(int *op)
{
    printf("1- Agregar persona\n2-Borrar persona\n3-Listar por nombre\n4- Graficar\n0- Salir\n");
    scanf("%d",op);
}

Persona *findPlace(Persona gente[])
{
    int i;
    for(i=0;i < CANTIDAD;i++)
    {
        if(gente[i].inUseFlag == 0)
        {
            return &gente[i];
        }
    }
    return NULL;
}

Persona *buscarPorDNI(Persona gente[], long dni)
{
    int i;
    for(i=0;i<CANTIDAD;i++)
    {
        if(gente[i].dni == dni && gente[i].inUseFlag)
            return &gente[i];
    }
    return NULL;
}

void agregarPersona(Persona gente[])
{
    Persona *p = findPlace(gente);
    int retorno;
    if(p != NULL)
    {
        retorno = pedirString(p->nombre,"Ingrese Nombre:\n",30,3,"El nombre de tener entre 3 y 30 caracteres\n");

        if(retorno != -1)
            retorno = pedirInt(&p->edad,"Ingrese edad:\n",120,1,"Ingrese una edad valida\n");
        if(retorno != -1)
            retorno = pedirLong(&p->dni,"Ingrese DNI:\n",0,1,"El DNI debe ser valido\n");
        if(retorno != -1)
            p->inUseFlag = 1;
    }else
    {
        printf("No hay mas espacio\n");
    }
}


void listarPorNombre(Persona gente[])
{
    int cantidadDePersonas = 0;
    int i,j;
    Persona personaAuxiliar;
    for(i = 0; i< CANTIDAD;i++)
    {
        if(gente[i].inUseFlag == 1)
            cantidadDePersonas++;
    }

    if(cantidadDePersonas > 1)
    {
        for(i=0;i<CANTIDAD-1;i++)
        {
            for(j=i+1;j<CANTIDAD;j++)
            {
                if(gente[i].inUseFlag && gente[j].inUseFlag)
                {
                    if(strcmp(gente[i].nombre,gente[j].nombre) > 0)
                    {
                        personaAuxiliar = gente[i];
                        gente[i] = gente[j];
                        gente[j] = personaAuxiliar;
                    }
                }

            }
        }
    }

    for(i = 0; i< CANTIDAD;i++)
    {
        if(gente[i].inUseFlag)
            printf("Nombre: %s | Edad: %d | DNI: %d\n",gente[i].nombre,gente[i].edad,gente[i].dni);
    }
}


void borrarPersona(Persona gente[])
{
    listarPorNombre(gente);
    long dniToDelete;
    Persona *personaABorrar = NULL;
    int hayError = pedirLong(&dniToDelete,"Ingrese DNI de la persona a eliminar\n",0,1,"Ingrese un DNI valido\n");
    if(!hayError)
    {
        personaABorrar = buscarPorDNI(gente,dniToDelete);
        if(personaABorrar != NULL)
        {
            personaABorrar->inUseFlag = 0;
        }else
        {
            printf("El DNI no corresponde a ninguna persona cargada\n");
        }
    }
}


void graficar(Persona gente[])
{
    int i;
    int a = 0;
    int b = 0;
    int c = 0;
    int tope = 0;

    for(i=0;i<CANTIDAD;i++)
    {
        if(gente[i].inUseFlag && gente[i].edad > 35)
            c++;
        else if(gente[i].inUseFlag && gente[i].edad > 18)
            b++;
        else if(gente[i].inUseFlag && gente[i].edad <= 18)
            a++;
    }
    if(a>tope)
        tope= a;
    if(b>tope)
        tope= b;
    if(c>tope)
        tope= c;

    char array[3][20];

    for(i=0;i<20;i++)
    {
        array[0][i] = ' ';
        array[1][i] = ' ';
        array[2][i] = ' ';
    }

    for(i = 0; i < a;i++)
    {
        array[0][i] = '*';
    }
    for(i = 0; i < b;i++)
    {
        array[1][i] = '*';
    }
    for(i = 0; i < c;i++)
    {
        array[2][i] = '*';
    }

    for(i = tope-1; i>=0; i--)
    {
        printf(" %c      %c      %c\n",array[0][i],array[1][i],array[2][i]);
    }
    printf("<18  19-35  >35\n");
}



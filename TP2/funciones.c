#include <stdio.h>
#include <stdlib.h>
#include "../md_lib/lib.h"
#include "structs.h"

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
            for(j=i;j<CANTIDAD;j++)
            {
                if(strcmp(gente[i],gente[j]) > 0)
                {
                    personaAuxiliar = gente[i];
                    gente[i] = gente[j];
                    gente[j] = personaAuxiliar;
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



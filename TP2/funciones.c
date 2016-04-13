#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

char *personaToString(Persona p)
{
    char* ret = NULL;
    sprintf(ret,"Nombre: %s , Edad: %d, DNI: %ld",p.nombre,p.edad,p.dni);
    return ret;
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
        if(!gente[i].inUseFlag)
        {
            return &gente[i];
        }
    }
    return NULL;
}



void agregarPersona(Persona gente[])
{
    Persona *p = findPlace(gente);
    if(p != NULL)
    {
        printf("Ingrese Nombre:\n");
        scanf("%s",p->nombre);

        printf("Ingrese Edad:\n");
        scanf("%d",&p->edad);

        printf("Ingrese DNI:\n");
        scanf("%ld",&p->dni);
    }else
    {
        printf("No hay mas espacio\n");
    }
}




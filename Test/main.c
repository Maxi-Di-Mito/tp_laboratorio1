#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../md_lib/lib.h"
#define CANTIDAD 5

typedef struct Persona
{
    int legajo;
    char nombre[31];
    char apellido[31];
    char activo;
} Persona;

//// PROTOTIPOS

void ordenar(Persona emp[]);
void mostrar(Persona emp[]);
void cargar(Persona emp[]);
void borrar(Persona emp[]);

int buscarPorLegajo(Persona emp[],int l);
int buscarLibre(Persona emp[]);
void iniciarEmpleados(Persona empleados[]);

//////////////////////////////////////// MAIN
int main()
{
    Persona empleados[CANTIDAD];
    int opcion ;
    iniciarEmpleados(empleados);

    do
    {
        printf("1- Mostrar\n2- Cargar\n3- Ordenar\n4- Borrar\n5- Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                system("cls");
                mostrar(empleados);
                break;
            case 2:
                system("cls");
                cargar(empleados);
                system("cls");
                break;
            case 3:
                system("cls");
                ordenar(empleados);
                break;
            case 4:
                system("cls");
                borrar(empleados);
                system("cls");
                break;
        }
    }while(opcion != 5);


    return 0;
}

////////////////////////// FUNCIONES
void iniciarEmpleados(Persona empleados[])
{
    int i;
    empleados[0].activo = 1;
    empleados[0].legajo = 1;
    strcpy(empleados[0].nombre, "Maxi");
    strcpy(empleados[0].apellido, "Di Mito");

    empleados[1].activo = 1;
    empleados[1].legajo = 2;
    strcpy(empleados[1].nombre, "Alex");
    strcpy(empleados[1].apellido, "Artez");
    for(i = 2;i < CANTIDAD;i++)
    {
        empleados[i].activo = 0;
    }
}


void borrar(Persona emp[])
{
    mostrar(emp);
    int legajo;
    int index;
    do
    {
        printf("Ingrese legajo a borrar\n");
        scanf("%d",&legajo);
        index = buscarPorLegajo(emp,legajo);
    }while(index == -1);
    printf("\nLEGAJO: %d\nAPELLIDO: %s\nNOMBRE: %s\n",emp[index].legajo,emp[index].apellido,emp[index].nombre);
    if(confirmacionSinReintentos("Esta seguro que desea eliminar al empleado (s/n)?",'s','n'));
        emp[index].activo = 0;
}


void cargar(Persona emp[])
{
    int index;
    int legajo;
    printf("Ingrese Legajo\n");
    scanf("%d",&legajo);
    index = buscarPorLegajo(emp,legajo);
    if(index != -1)
    {
        if(!confirmacionSinReintentos("Ese legajo ya existe, desea editarlo?",'s','n'))
        {
            return;
        }
    }
    else
    {
        index = buscarLibre(emp);
        if(index == -1)
        {
            printf("No hay lugar");
            return;
        }

    }
    printf("Ingrese Apellido\n");
    scanf("%s",emp[index].apellido);

    printf("Ingrese Nombre\n");
    scanf("%s",emp[index].nombre);
    emp[index].activo = 1;
    emp[index].legajo = legajo;

}

int buscarPorLegajo(Persona emp[],int l)
{
    int i;
    for(i = 0; i < CANTIDAD;i++)
    {
        if(emp[i].legajo == l && emp[i].activo)
            return i;
    }
    return -1;
}

int buscarLibre(Persona emp[])
{
    int i;
    for(i = 0;i < CANTIDAD;i++)
    {
        if(emp[i].activo == 0)
            return i;
    }
}

void ordenar(Persona emp[])
{
    int i, j;
    int ret;
    for(i = 0;i < CANTIDAD-1;i++)
    {
        for(j = i+1;j < CANTIDAD;j++)
        {
            ret = strcmp(emp[i].apellido,emp[j].apellido);
            if( ret> 0)
            {
                swap(&emp[i],&emp[j],sizeof(emp[i]));
            }else if( ret == 0)
            {
                if(strcmp(emp[i].nombre,emp[j].nombre) > 0)
                {
                    swap(&emp[i],&emp[j],sizeof(emp[i]));
                }
            }
        }
    }
}



void mostrar(Persona emp[])
{
    int i = 0;
    Persona p;
    for(i = 0;i< CANTIDAD;i++)
    {
        p = emp[i];
        if(p.activo)
        {
            printf("LEGAJO: %d\n",p.legajo);
            printf("APELLIDO: %s\n",p.apellido);
            printf("NOMBRE: %s\n\n",p.nombre);
        }
    }
}


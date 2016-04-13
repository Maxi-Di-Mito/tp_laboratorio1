#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "../md_lib/lib.h"
void printMenu()
{
    printf("1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-LISTAR\n");
}

Empleado *buscarLugar(Empleado nomina[], int largo)
{
    int i;
    for(i=0;i<largo;i++)
    {
        if(nomina[i].estado == 0)
        {
            return &nomina[i];
        }
    }
    return NULL;
}

int buscarProxLegajo(Empleado nomina[], int largo)
{
    int max = 0;
    int i;
    for(i = 0;i<largo;i++)
    {
        if(nomina[i].legajo > max)
        {
            max = nomina[i].legajo;
        }
    }
    return max+1;
}

void altas(Empleado nomina[], int largo)
{
    char aux[100];
    int proximoLegajo;
    Empleado *l = buscarLugar(nomina, largo);
    if(l != NULL)
    {
        proximoLegajo = buscarProxLegajo(nomina,largo);
        if(!pedirString(aux,"Ingrese nombre\n",2,50,"El nombre debe tener entre 2 y 50 caracteres\n"))
            return;
        strcpy(l->nombre,aux);

        if(!pedirString(aux,"Ingresar apellido\n",2,50,"El apellido debe tener entre 2 y 50 caracteres\n"))
            return;
        strcpy(l->apellido,aux);

        if(!pedirInt(&l->salario,"Ingrese salario\n",-1,0,"El salario ser un numero positivo\n"))
            return;

        printf("Ingrese sector\n1-Contabilidad\n2-Administracion\n3-Compras\n4-Ventas\n");
        if(!pedirInt(&l->sector,"",4,1,"El sector debe estar entre 1 y 4\n"));

        pedirLong(&l->fechaIngreso,"Ingrese fecha en formato YYYYMMDD\n",8,8,"La fecha debe seguir el formato YYYYMMDD\n");

        l->legajo = proximoLegajo;
    }
    else
    {
        printf("No hay espacio para dar una nueva ALTA\n");
    }

}

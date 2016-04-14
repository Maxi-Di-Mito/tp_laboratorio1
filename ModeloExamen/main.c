#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "../md_lib/lib.h"
#define ALTAS 1
#define MODIFICAR 2
#define BAJA 3
#define INFORMAR 4
#define LISTAR 5
#define SALIR 0
#define CANTIDAD 10000

int main()
{
    short int opcion = 0;
    Empleado nomina[CANTIDAD];

    while( opcion != SALIR)
    {
        printMenu();
        scanf("%hd",&opcion);
        switch(opcion)
        {
            case ALTAS:
                altas(nomina,CANTIDAD);
                break;
            case MODIFICAR:
                modificar(nomina, CANTIDAD);
                break;
            case BAJA:
                baja(nomina,CANTIDAD);
                break;
            case INFORMAR:
                //informar(nomina);
                break;
            case LISTAR:
                //listar();
                break;
        }
    }
    return 0;
}

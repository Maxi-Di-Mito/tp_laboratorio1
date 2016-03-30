#include <stdio.h>
#include <stdlib.h>
#include "../md_lib/lib.h"

int main()
{
    float gastos[30],g;
    int i,dia;
    for(i = 0; i<30;i++)
    {
        gastos[i]=0;
    }

    do
    {
        printf("Ingrese dia\n");
        scanf("%d",&dia);
        printf("Ingrese gasto\n");
        scanf("%f",&g);
        gastos[dia-1] +=g;
    }while(confirmacion("Desea ingresar mas datos (s/n)?",'s','n'));

    for(i=0;i<30;i++)
    {
        printf("%.2f\n",gastos[i]);
    }



    return 0;
}

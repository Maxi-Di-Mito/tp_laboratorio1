#include "lib.h"
#define CANTIDAD 1000


//MODIFICAR structuras para que un producto apunte a un proveedor

int main()
{
    Producto productos[CANTIDAD];
    Proveedor proveedores[CANTIDAD];
    int i, opcion;
    for(i = 0; i< CANTIDAD;i++)
    {
        productos[i].enUso = 0;
        proveedores[i].enUso = 0;
    }


    do
    {
        printf("1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-LISTAR\n6-SALIR\n");
        pedirInt(&opcion,"Ingrese una opcion\n",6,1,"Ingrese una opcion valida\n");
        switch(opcion)
        {
            case ALTAS:
                altas(productos,proveedores, CANTIDAD);
                break;
            case BAJA:
                //baja(productos,CANTIDAD);
                break;
            case MODIFICAR:
                //modificar(productos,proveedores,CANTIDAD);
                break;
            case INFORMAR:
                //informar(productos,proveedores,CANTIDAD);
                break;
            case LISTAR:
                //listar(productos,proveedores,CANTIDAD);
                break;
        }
    }while(opcion != SALIR);

}

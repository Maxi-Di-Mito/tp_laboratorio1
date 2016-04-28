#include "lib.h"

Producto *buscarProductoLibre(Producto productos[],int cantidad)
{
    int i;
    for(i = 0; i < cantidad;i++)
    {
        if(!productos[i].enUso)
            return &productos[i];
    }
    return NULL;
}

int existeProveedor(int codigoProveedor,Proveedor proveedores[], int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(proveedores[i].codigoproveedor == codigoProveedor)
            return 1;
    }
    return 0;
}


void altas(Producto productos[], Proveedor proveedores[],int cantidad)
{
    Producto *punteroProductoLibre = NULL;
    Producto productoAuxiliar;
    int hayError = 0;
    punteroProductoLibre = buscarProductoLibre(productos,cantidad);
    if(punteroProductoLibre !=  NULL)
    {
        hayError = pedirInt(&productoAuxiliar.codigoProducto,"Ingrese el codigo de producto\n",0,1,"Ingrese un codigo valido(< 0)\n");

        if(!hayError)
        {
            hayError = pedirInt(&productoAuxiliar.codigoProveedor,"Ingrese el codigo del proveedor\n",0,1,"Ingrese un codigo valido(< 0)\n");
            if(!hayError && !existeProveedor(productoAuxiliar.codigoProveedor,proveedores,cantidad))
            {
                printf("No existe el proveedor\n");
                hayError = 1;
            }
        }

        if(!hayError)
        {
            hayError = pedirString(productoAuxiliar.descripcion,"Ingrese descripcion\n",51,3,"El largo de la descripcion no es correcto\n");
        }

        if(!hayError)
        {
            hayError = pedirFloat(&productoAuxiliar.importe,"Ingrese importe\n","Ingrese un dato valido\n");
        }

        if(!hayError)
        {
            hayError = pedirInt(&productoAuxiliar.cantidad,"Ingrese la cantidad\n",0,0,"Ingrese una cantidad\n");
        }


    }else
    {
        printf("NO HAY LUGAR\n");
        hayError = 1;
    }
    if(hayError)
    {
        printf("Hubo un error. Intente nuevamente\n");
    }

    if(!hayError)
    {
        memccpy(punteroProductoLibre,&productoAuxiliar,sizeof(Producto));
    }

}

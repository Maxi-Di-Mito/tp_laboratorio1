#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "../md_lib/lib.h"
#define ALTAS 1
#define MODIFICAR 2
#define BAJA 3
#define INFORMAR 4
#define LISTAR 5
#define SALIR 6

Producto *buscarProductoLibre(Producto productos[],int cantidad);

int existeProveedor(int codigoProveedor,Proveedor proveedores[], int cantidad);

void altas(Producto[],Proveedor[],int cantidad);

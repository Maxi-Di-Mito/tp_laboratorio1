#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    Persona personas[CANTIDAD];
    int opcion = 1;

    while(opcion != SALIR)
    {
        mostrarMenuYElegir(&opcion);

        switch(opcion)
        {
            case AGREGAR:
                agregarPersona(personas);
                break;
            //case BORRAR:
             //   borrarPersona(personas);
             //   break;
            case LISTAR:
                listarPorNombre(personas);
                break;
           // case GRAFICAR:
            //    graficar(personas);*/
        }
    }
    return 0;
}

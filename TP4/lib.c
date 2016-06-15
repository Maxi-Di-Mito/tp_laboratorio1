#include "lib.h"
#define NUEVO 1
#define CONSULTAR 2
#define MODIFICAR 3
#define ELIMINAR 4
#define EXPORTAR 5
#define SALIR 6

int start()
{
    int opcion = 0;
    ArrayList *calendario = al_newArrayList();

    do
    {
        printMenu();
        pedirInt(&opcion,"Ingrese una opcion:\n",6,1,"Ingrese una opcion valida. Entre 1 y 6\n");

        switch(opcion)
        {
            case NUEVO:
                crearNuevoEvento(calendario);
                break;
            case CONSULTAR:
                break;
            case MODIFICAR:
                break;
            case ELIMINAR:
                break;
            case EXPORTAR:
                exportarCalendario(calendario);
                break;
        }
    }while( opcion != SALIR);

    limpiarMemoria(calendario);
    calendario->deleteArrayList(calendario);
    return 0;
}


void printMenu()
{
    printf("1-Nuevo Evento\n");
    printf("2-Consultar Fecha\n");
    printf("3-Modificar Evento\n");
    printf("4-Eliminar Evento\n");
    printf("5-Exportar Calendario\n");
    printf("6-Salir\n");
}

int crearNuevoEvento(ArrayList *calendario)
{
    int estado = 0;
    Evento auxEvento;
    Evento *nuevoEvento = NULL;

    estado = pedirString(auxEvento.fechaCreacion,"Ingrese la fecha deseada\n",8,8,"Ingrese una fecha con el formato especificado(AAAAMMDD)\n");
    estado = validarFormatoFecha(auxEvento.fechaCreacion);

    if(!estado)
    {
        estado = pedirString(auxEvento.descripcion,"Ingrese la descripcion del evento\n",200,5,"Ingrese un texto entre 200 y 5 caracteres\n");
    }

    if(!estado)
    {
        nuevoEvento = malloc(sizeof(Evento));
        memcpy(nuevoEvento,&auxEvento,sizeof(Evento));
        estado = calendario->add(calendario,nuevoEvento);
    }

    return estado;
}

int consultarFecha()
{
    return 0;
}

int modificarEvento()
{
    return 0;
}

int eliminarEvento()
{
    return 0;
}

int exportarCalendario(ArrayList *calendario)
{
    int i;
    Evento *auxEvento = NULL;
    for(i=0;i<calendario->size;i++)
    {
        auxEvento = (Evento*)calendario->get(calendario,i);
        printf("FECHA: %s - DESC: %s\n",auxEvento->fechaCreacion,auxEvento->descripcion);
    }
    return 0;
}


int limpiarMemoria(ArrayList *list)
{
    int i;
    Evento *aux = NULL;
    for(i = 0;i < list->size;i++)
    {
        aux = list->pop(list,i);
        if(aux == NULL)
            return -1;
        free(aux);
    }
    return 0;
}



int validarFormatoFecha(char fecha[9])
{
    Fecha auxFecha;
    return fechaStringToLong(&auxFecha,fecha);
}

int fechaStringToLong(Fecha *fecha, char charfechaString[9])
{
    Fecha auxFecha;
    char anio[5];
    char mes[3];
    char dia[3];
    char *charError = NULL;

    strncpy(anio, charfechaString, 4);

    printf("ANIO %s\n",anio);
    auxFecha.anio = strtol(anio,&charError,10);
    if(*charError != '\0')
        return -1;

    strncpy(mes, charfechaString+4, 2);
    printf("MES %s\n",mes);
    auxFecha.mes = strtol(mes,&charError,10);
    if(*charError != '\0' && auxFecha.mes > 12)
        return -1;

    strncpy(dia, charfechaString+6, 2);
    printf("DIA %s\n",dia);
    auxFecha.dia = strtol(dia,&charError,10);
    if(*charError != '\0' && auxFecha.dia > 31)
        return -1;

    memcpy(fecha,&auxFecha,sizeof(Fecha));
    return 0;
}



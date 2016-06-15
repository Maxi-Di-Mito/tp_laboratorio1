#include "lib.h"
#define NUEVO 1
#define CONSULTAR_DIA 2
#define MODIFICAR 3
#define ELIMINAR 4
#define EXPORTAR 5
#define LIMPIAR 6
#define SALIR 7

int start()
{
    int opcion = 0;
    ArrayList *calendario = al_newArrayList();
    cargarEventosDeArchivo(calendario);

    do
    {
        system("cls");
        printMenu();
        pedirInt(&opcion,"Ingrese una opcion:\n",7,1,"Ingrese una opcion valida. Entre 1 y 6\n");

        switch(opcion)
        {
            case NUEVO:
                if(crearNuevoEvento(calendario))
                    printf("Hubo un error al intentar crear el evento\n");
                pausa("Presione una tecla para volver\n");
                break;
            case CONSULTAR_DIA:
                if(consultarFecha(calendario))
                    printf("Hubo un error con la consulta\n");
                pausa("Presione una tecla para volver\n");
                break;
            case MODIFICAR:
                if(modificarEvento(calendario))
                    printf("No se pudo completar la modificacion\n");
                break;
            case ELIMINAR:
                if(eliminarEvento(calendario))
                    printf("No fue posible eliminar el evento\n");
                pausa("Presione una tecla para volver\n");
                break;
            case EXPORTAR:
                if(exportarCalendario(calendario))
                    printf("Hubo un error al intentar exportar el calendario\n");
                pausa("Presione una tecla para volver\n");
                break;
            case LIMPIAR:
                if(limpiarCalendario(calendario))
                    printf("No se pudo completar la operacion\n");
                    pausa("Presione una tecla para volver\n");
                break;
        }
    }while( opcion != SALIR);

    guardarEventosEnArchivo(calendario);
    limpiarMemoria(calendario);
    calendario->deleteArrayList(calendario);
    return 0;
}


void printMenu()
{
    printf("1-Nuevo Evento\n");
    printf("2-Consultar dia\n");
    printf("3-Modificar Evento\n");
    printf("4-Eliminar Evento\n");
    printf("5-Exportar Calendario\n");
    printf("6-Limpiar Calendario\n");
    printf("7-Salir\n");
}

int crearNuevoEvento(ArrayList *calendario)
{
    int estado = 0;
    Evento auxEvento;
    Evento *nuevoEvento = NULL;
    system("cls");
    estado = pedirFecha("Ingrese la fecha deseada\n",auxEvento.fechaCreacion);

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

int consultarFecha(ArrayList *calendario)
{
    int i;
    char fechaIngresada[9];
    Evento *auxEvento = NULL;
    system("cls");
    if(calendario->isEmpty(calendario))
    {
        printf("No hay datos\n");
        return 0;
    }
    pedirFecha("Ingrese la fecha deseada\n",fechaIngresada);
    if(calendario->sort(calendario,compararEventosPorFecha,1))
        return -1;

    for(i = 0; i < calendario->len(calendario);i++)
    {
        auxEvento = calendario->get(calendario,i);
        if(strcmp(auxEvento->fechaCreacion,fechaIngresada) == 0)
            printf("FECHA: %s - DESCRIPCION: %s\n",auxEvento->fechaCreacion,auxEvento->descripcion);
    }

    return 0;
}

int modificarEvento(ArrayList *calendario)
{
    int id;
    char auxDescripcion[201];
    Evento *auxEvento = NULL;
    system("cls");
    if(calendario->isEmpty(calendario))
    {
        printf("No hay datos\n");
        return 0;
    }
    imprimirEventos(calendario);
    if(pedirInt(&id,"Ingrese el ID del evento a modificar\n",0,0,"Ingrese un id valido\n"))
        return -1;
    if(calendario->get(calendario,id) == NULL)
    {
        printf("ID fuera de rango\n");
        return -1;
    }
    if(pedirString(auxDescripcion,"Ingrese la descripcion del evento\n",200,5,"Ingrese un texto entre 200 y 5 caracteres\n"))
        return -1;

    auxEvento = calendario->get(calendario,id);
    strcpy(auxEvento->descripcion,auxDescripcion);

    return 0;
}

int eliminarEvento(ArrayList *calendario)
{
    int id;
    Evento *auxEvento = NULL;
    system("cls");
    if(calendario->isEmpty(calendario))
    {
        printf("No hay datos\n");
        return 0;
    }
    imprimirEventos(calendario);
    if(pedirInt(&id,"Ingrese el ID del evento a modificar\n",0,0,"Ingrese un id valido\n"))
        return -1;
    if(calendario->get(calendario,id) == NULL)
    {
        printf("ID fuera de rango\n");
        return -1;
    }
    auxEvento = calendario->get(calendario,id);
    calendario->remove(calendario,id);
    free(auxEvento);
    return 0;
}

int exportarCalendario(ArrayList *calendario)
{
    int opcion,estado,idInicio,idFinal;
    ArrayList *auxCalendario = NULL;
    char fechaInicio[9];
    char fechaFinal[9];
    system("cls");
    if(calendario->isEmpty(calendario))
    {
        printf("No hay datos\n");
        return 0;
    }
    if(calendario->sort(calendario,compararEventosPorFecha,1) == -1)
        return -1;

    printf("1-Exportar todo\n");
    printf("2-Exportar rango de fecha\n");
    printf("3-Exportar rango de ID de eventos\n");
    if(pedirInt(&opcion,"",3,1,"Ingrese una opcion valida\n"))
       return -1;

    if(opcion == 1)
    {
        return exportarEventosAArchivo(calendario);
    }else if( opcion == 2)
    {
        estado = pedirFecha("Ingrse la fecha de inicio\n",fechaInicio);
        if(!estado)
            estado = pedirFecha("Ingrese la fecha final\n",fechaFinal);
        if(!estado)
        {
            auxCalendario = calcularRango(calendario,fechaInicio,fechaFinal);
            estado = exportarEventosAArchivo(auxCalendario);
            auxCalendario->deleteArrayList(auxCalendario);
        }
        return estado;
    }else
    {
        imprimirEventos(calendario);
        estado = pedirInt(&idInicio,"Ingrese el id inicial\n",0,0,"Ingrese un id valido\n");
        if(!estado)
            estado = pedirInt(&idFinal,"Ingrese el id final\n",0,0,"Ingrese un id valido\n");
        if(!estado)
        {
            auxCalendario = calendario->subList(calendario,idInicio,idFinal);
            estado = exportarEventosAArchivo(auxCalendario);
            auxCalendario->deleteArrayList(auxCalendario);
        }
        return estado;
    }
}


int limpiarMemoria(ArrayList *list)
{
    int i;
    Evento *aux = NULL;
    for(i = 0;i < list->len(list);i++)
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
    return fechaStringToFechaStruct(&auxFecha,fecha);
}

int fechaStringToFechaStruct(Fecha *fecha, char charfechaString[9])
{
    Fecha auxFecha;
    char anio[5];
    char mes[3];
    char dia[3];
    char *charError = NULL;

    strncpy(anio, charfechaString, 4);
    anio[4] = '\0';
    auxFecha.anio = strtol(anio,&charError,10);
    if(*charError != '\0')
        return -1;

    strncpy(mes, charfechaString+4, 2);
    mes[2] = '\0';
    auxFecha.mes = strtol(mes,&charError,10);
    if(*charError != '\0' && auxFecha.mes > 12)
        return -1;

    strncpy(dia, charfechaString+6, 2);
    dia[2] = '\0';
    auxFecha.dia = strtol(dia,&charError,10);
    if(*charError != '\0' && auxFecha.dia > 31)
        return -1;

    memcpy(fecha,&auxFecha,sizeof(Fecha));
    return 0;
}

int compararEventosPorFecha(Evento *e1, Evento *e2)
{
    Fecha auxFecha1;
    Fecha auxFecha2;
    long fecha1Long;
    long fecha2Long;
    fecha1Long = fechaStringToFechaStruct(&auxFecha1,e1->fechaCreacion);
    fecha2Long = fechaStringToFechaStruct(&auxFecha2,e2->fechaCreacion);
    fecha1Long = fechaStructToLong(auxFecha1);
    fecha2Long = fechaStructToLong(auxFecha2);

    return fecha1Long - fecha2Long;
}


long fechaStructToLong(Fecha fecha)
{
    return (long)fecha.dia + (fecha.mes*100) + (fecha.anio * 10000);
}


int cargarEventosDeArchivo(ArrayList *calendario)
{
    Evento* pAux = NULL;

    FILE* pArchivo = fopen("calendario.bat","rb");

    if(pArchivo == NULL || feof(pArchivo))
    {
        printf("No fue posible abrir el archivo\n");
        return -1;
    }
    printf("Archivo previo encontrado\nCargando datos....\n");
   while(!feof(pArchivo))
    {
        pAux = malloc(sizeof(Evento));
        if(fread(pAux,sizeof(Evento),1,pArchivo) == 1)
        {
            calendario->add(calendario,pAux);
        }
    }
    fclose(pArchivo);
    return 0;
}

int guardarEventosEnArchivo(ArrayList *calendario)
{
    long bytesGrabados = 0;
    int i;
    Evento * auxEvento = NULL;
    FILE* pArchivo = NULL;
    pArchivo = fopen("calendario.bat","wb");
    if(pArchivo == NULL)
        return -1;

    for(i=0; i < calendario->len(calendario); i++)
    {
        auxEvento = calendario->get(calendario,i);
        fwrite(auxEvento,sizeof(Evento),1,pArchivo);
    }
    fclose(pArchivo);
    if(bytesGrabados != calendario->len(calendario)*sizeof(Evento))
        return -1;

    return 0;
}

int exportarEventosAArchivo(ArrayList *calendario)
{
    FILE *pArchivo = NULL;
    Evento *auxEvento = NULL;
    int i;
    pArchivo = fopen("calendario.txt","w");
    if(pArchivo == NULL)
        return -1;

    for(i = 0; i < calendario->len(calendario);i++)
    {
        auxEvento = calendario->get(calendario,i);
        fprintf(pArchivo,"FECHA: %s - DESCRIPCION: %s\n",auxEvento->fechaCreacion,auxEvento->descripcion);
    }

    fclose(pArchivo);
    return 0;
}

int limpiarCalendario(ArrayList *calendario)
{
    int i;
    Evento *auxEvento = NULL;
    for(i=0; i< calendario->len(calendario);i++)
    {
        auxEvento = calendario->get(calendario,i);
        free(auxEvento);
    }
    calendario->clear(calendario);
    return 0;
}

int pedirFecha(char* msg,char* dato)
{
    int estado = 0;
    estado = pedirString(dato,msg,8,8,"Ingrese una fecha con el formato especificado(AAAAMMDD)\n");
    if(!estado)
        estado = validarFormatoFecha(dato);

    return estado;
}


ArrayList *calcularRango(ArrayList *calendario,char fechaInicio[9],char fechaFinal[9])
{
    int i;
    int indexInicio = -1;
    int indexFinal = -1;
    Evento auxInicio,auxFinal;
    strcpy(auxInicio.fechaCreacion,fechaInicio);
    strcpy(auxFinal.fechaCreacion,fechaFinal);
    for(i = 0; i< calendario->len(calendario);i++)
    {
        printf("IT: %d\n",i);
        if( (compararEventosPorFecha(calendario->get(calendario,i),&auxInicio) >= 0) && indexInicio == -1)
        {
            indexInicio = i;
        }
        if((compararEventosPorFecha(calendario->get(calendario,i),&auxFinal) >= 0) && indexFinal == -1)
        {
            indexFinal = i-1;
            break;
        }
    }
    printf("INICIO %d - FINAL %d\n",indexInicio,indexFinal);
    if(indexInicio == -1)
        return NULL;
    if(indexFinal == -1)
        indexFinal = calendario->len(calendario)-1;
    return calendario->subList(calendario,indexInicio,indexFinal);
}


int imprimirEventos(ArrayList *calendario)
{
    int i;
    Evento *auxEvento = NULL;
    if(calendario->sort(calendario,compararEventosPorFecha,1))
        return -1;
    for(i=0; i< calendario->len(calendario);i++)
    {
        auxEvento = calendario->get(calendario,i);
        printf("ID: %d - FECHA: %s - DESCRIPCION: %s\n",i,auxEvento->fechaCreacion,auxEvento->descripcion);
    }
    return 0;
}



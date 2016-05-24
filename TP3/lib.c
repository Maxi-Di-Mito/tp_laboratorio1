#include "lib.h"
#define AGREGAR 1
#define BORRAR 2
#define MODIFICAR 3
#define WEB 4
#define SALIR 5



int run()
{
    int opcion,i;
    Movie** peliculas = NULL;
    int espacioReservado = 0;
    int cantidadDePeliculas = cargarPeliculasDesdeArchivoAMemoria(&espacioReservado,&peliculas);
    if(cantidadDePeliculas == -1)
        return -1;

    for(i = 0; i < cantidadDePeliculas;i++)
    {
        printf("%s\n",(*peliculas)->titulo);
    }
    do
    {
        if(-1 ==pedirInt(&opcion,"1-AgregarPelicula\n2-BorrarPelicula\n3-ModificarPelicula\n4-GenerarWeb\5-Salir\n",5,1,"Ingrese una opcion valida\n"))
        {

            return -1;
        }

        switch(opcion)
        {
            case AGREGAR:
                agregarPelicula(&peliculas,&cantidadDePeliculas,&espacioReservado);
                break;
            case BORRAR:
                break;
            case MODIFICAR:
                break;
            case WEB:
                break;
        }
    }while(opcion != SALIR);
    return 0;
}


int cargarPeliculasDesdeArchivoAMemoria(int *espacioReservado,Movie ***lista)
{
    Movie **pelis = NULL;
    Movie aux;
    FILE* pArchivo = fopen("pelis.bat","rb");
    int i, cantidadDeEspacio = 10;
    if(pArchivo == NULL)
    {
        return -1;
    }

    for(i = 0;!feof(pArchivo);i++)
    {
        fread(&aux,sizeof(Movie),1,pArchivo);
        fseek(pArchivo,sizeof(Movie),SEEK_CUR);
        if(!i)
        {
            pelis = malloc(sizeof(Movie*)*cantidadDeEspacio);
        }else
        if(i == cantidadDeEspacio-1)
        {
            cantidadDeEspacio += 10;
            pelis = realloc(pelis,sizeof(Movie*)*(cantidadDeEspacio));
        }
        *(pelis+i) = malloc(sizeof(Movie));
        memccpy(&aux,(*(pelis+i)));
    }
    *lista = pelis;
    fclose(pArchivo);
    *espacioReservado = cantidadDeEspacio;
    return i;
}


int agregarPelicula(Movie ***peliculas,int *cantidadDePeliculas,int *espacioReservado)
{
    Movie auxMovie;
    Movie *pAuxMovie = NULL;

    int error = 0;
    error = pedirString(auxMovie.titulo,"Ingrese el titulo:\n",50,3,"El titulo de tener entre 3 y 50 caracteres\n");

    if(!error)
        //retorno = pedirInt(&p->edad,"Ingrese edad:\n",120,1,"Ingrese una edad valida\n");
    if(!error)
        //retorno = pedirLong(&p->dni,"Ingrese DNI:\n",0,1,"El DNI debe ser valido\n");
    if(!error)
        //p->inUseFlag = 1;

    if(error)
    {
        return -1;
    }
    if(cantidadDePeliculas == espacioReservado-1);
    {
        *espacioReservado += 10;
        realloc(*peliculas,sizeof(Movie*)*(*espacioReservado));
    }
    pAuxMovie = *((*peliculas)+*cantidadDePeliculas);

    memccpy(&auxMovie, pAuxMovie);
    *cantidadDePeliculas++;
    return 0;
}


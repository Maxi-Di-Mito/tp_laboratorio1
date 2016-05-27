#include "lib.h"
#define AGREGAR 1
#define BORRAR 2
#define MODIFICAR 3
#define WEB 4
#define SALIR 5



int run()
{
    int opcion;
    Movie* peliculas = NULL;
    if(cargarPeliculasDesdeArchivoAMemoria(&peliculas))
    {
        printf("No se pudo cargar datos de archivo\n");
    }

    do
    {
        if(-1 ==pedirInt(&opcion,"1-AgregarPelicula\n2-BorrarPelicula\n3-ModificarPelicula\n4-GenerarWeb\n5-Salir\n",5,1,"Ingrese una opcion valida\n"))
        {
            return -1;
        }

        switch(opcion)
        {
            case AGREGAR:
                agregarPelicula(&peliculas);
                salvarArchivoBinario(peliculas);
                printf("archivo binario salvado\n");
                break;
            case BORRAR:
                break;
            case MODIFICAR:
                break;
            case WEB:
                break;
        }
    }while(opcion != SALIR);
    liberarMemoria(&peliculas);
    return 0;
}


int cargarPeliculasDesdeArchivoAMemoria(Movie **pelis)
{
    Movie* pAux = NULL;
    Movie aux;
    FILE* pArchivo = fopen("pelis.bat","rb");
    int i;
    if(pArchivo == NULL || feof(pArchivo))
    {
        printf("No fue posible abrir el archivo\n");
        return -1;
    }
    printf("Archivo previo encontrado\nCargando datos....\n");
    for(i = 0;!feof(pArchivo);i++)
    {
        fread(&aux,sizeof(Movie),1,pArchivo);
        fseek(pArchivo,sizeof(Movie),SEEK_CUR);
        if(i == 0)
        {
            *pelis = malloc(sizeof(Movie));
            memcpy((*pelis),&aux,sizeof(Movie));
            (*pelis)->next = NULL;
            pAux = *pelis;
        }else
        {
            pAux->next = malloc(sizeof(Movie));
            memcpy((pAux->next),&aux,sizeof(Movie));
            pAux = pAux->next;
        }

    }
    fclose(pArchivo);
    return 0;
}


int agregarPelicula(Movie **peliculas)
{
    Movie auxMovie;
    Movie *pAuxMovie = NULL;

    int error = 0;
    error = pedirString(auxMovie.titulo,"Ingrese el titulo:\n",50,3,"El titulo de tener entre 3 y 50 caracteres\n");

    if(!error)
        error = pedirString(auxMovie.genero,"Ingrese el genero:\n",50,3,"El genero de tener entre 3 y 50 caracteres\n");
    if(!error)
        error = pedirString(auxMovie.duracion,"Ingrese la duracion(hh:mm):\n",50,3,"la duracion debe tener 5 caracteres\n");
    if(!error)
        error = pedirString(auxMovie.descripcion,"Ingrese la descripcion:\n",300,3,"la descripcion debe tener entre 3 y 300 caracteres\n");
    if(!error)
        error = pedirInt(&auxMovie.puntaje,"Ingrese el puntaje:\n",10,1,"ingrese un puntaje valido");
    if(!error)
        error = pedirString(auxMovie.linkImagen,"Ingrese el link a la imagen:\n",200,1,"ingrese la direccion debe tener al menos 1 caracter valido");

    if(error)
    {
        return -1;
    }

    if(*peliculas == NULL)
    {
        *peliculas = malloc(sizeof(Movie));
        memcpy((*peliculas),&auxMovie,sizeof(Movie));
        (*peliculas)->next = NULL;
        pAuxMovie = *peliculas;
    }else
    {
        while(pAuxMovie->next != NULL)
            pAuxMovie = pAuxMovie->next;

        pAuxMovie->next = malloc(sizeof(Movie));
        memcpy((pAuxMovie->next),&auxMovie,sizeof(Movie));
    }
    return 0;
}


int salvarArchivoBinario(Movie *peliculas)
{
    long bytesGrabados = 0;
    int contadorDePelis = 0;
    FILE* pArchivo = NULL;
    pArchivo = fopen("pelis.bat","wb");
    if(pArchivo == NULL)
        return -1;

    while(peliculas != NULL)
    {
        printf("Titulo: %s\n",peliculas->titulo);
        fwrite(peliculas,sizeof(Movie),1,pArchivo);
        printf("GRABADO\n");
        peliculas = peliculas->next;
        contadorDePelis++;
    }
    fclose(pArchivo);
    if(bytesGrabados != contadorDePelis*sizeof(Movie))
        return -1;

    return 0;
}


void liberarMemoria(Movie **peliculas)
{
    //Movie *pAux = *peliculas->next;
    //while(*peliculas != NULL)
    //    free(peliculas);
    //W}
}


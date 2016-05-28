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
                borrarPelicula(&peliculas);
                salvarArchivoBinario(peliculas);
                break;
            case MODIFICAR:
                modificar(peliculas);
                salvarArchivoBinario(peliculas);
                break;
            case WEB:
                generarWeb(peliculas);
                break;
        }
    }while(opcion != SALIR);
    salvarArchivoBinario(peliculas);
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
        if(fread(&aux,sizeof(Movie),1,pArchivo) == 1)
        {
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
                pAux = (Movie*)pAux->next;
            }
            printf("Titulo Cargado: %s\n",pAux->titulo);
        }

    }
    fclose(pArchivo);
    return 0;
}


int agregarPelicula(Movie **peliculas)
{
    Movie auxMovie;
    Movie *pAuxMovie = *peliculas;

    int error = 0;
    error = pedirString(auxMovie.titulo,"Ingrese el titulo:\n",50,3,"El titulo de tener entre 3 y 50 caracteres\n");

    if(!error)
        error = pedirString(auxMovie.genero,"Ingrese el genero:\n",50,3,"El genero de tener entre 3 y 50 caracteres\n");
    if(!error)
        error = pedirString(auxMovie.duracion,"Ingrese la duracion(hh:mm):\n",5,5,"la duracion debe tener 5 caracteres\n");
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
    auxMovie.next = NULL;

    if(*peliculas == NULL)
    {

        *peliculas = malloc(sizeof(Movie));
        memcpy((*peliculas),&auxMovie,sizeof(Movie));
        (*peliculas)->next = NULL;
        pAuxMovie = *peliculas;
    }else
    {
        while(pAuxMovie->next != NULL)
        {
            pAuxMovie = (Movie*)pAuxMovie->next;
        }
        pAuxMovie->next = malloc(sizeof(Movie));
        pAuxMovie = (Movie*)pAuxMovie->next;

        memcpy(pAuxMovie,&auxMovie,sizeof(Movie));
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
        fwrite(peliculas,sizeof(Movie),1,pArchivo);
        peliculas = (Movie*)peliculas->next;
        contadorDePelis++;
    }
    fclose(pArchivo);
    if(bytesGrabados != contadorDePelis*sizeof(Movie))
        return -1;

    return 0;
}


void liberarMemoria(Movie **peliculas)
{
    /*Movie *pAux = *peliculas->next;
    while(*peliculas != NULL)
    {
        free(peliculas);
        *peliculas = paux;
    }
*/

}

int generarWeb(Movie *peliculas)
{
    FILE *pArchivo = NULL;

    pArchivo = fopen("webGenerada/index.html","w");
    if(pArchivo == NULL)
        return -1;
    fprintf(pArchivo,"<html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>");
    fprintf(pArchivo,"<![endif]--></head><body><div class='container'><div class='row'>");
    while(peliculas != NULL)
    {
        fprintf(pArchivo,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s'alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%s</li></ul><p>%s</p></article>",peliculas->linkImagen,peliculas->titulo,peliculas->genero,peliculas->puntaje,peliculas->duracion,peliculas->descripcion);
        peliculas = (Movie*)peliculas->next;
    }
    fprintf(pArchivo,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");

    fclose(pArchivo);
    return 0;
}

int borrarPelicula(Movie **peliculas)
{
    char tituloAEliminar[51];
    Movie *auxMovie = *peliculas;
    Movie *auxDelete = NULL;
    while(auxMovie != NULL)
    {
        printf("TITULO: %s\n",auxMovie->titulo);
        auxMovie = (Movie*)auxMovie->next;
    }
    if(pedirString(tituloAEliminar,"Ingrese el titulo que desea eliminar\n",50,3,"El titulo debe tener entre 50 y 3 caracteres\n") == -1)
    {
        return -1;
    }
    auxMovie = *peliculas;
    if(!strcmp((*peliculas)->titulo,tituloAEliminar))
    {
        *peliculas = (Movie*)(*peliculas)->next;
        free(auxMovie);
    }else
    {
        while(auxMovie!= NULL)
        {
            auxDelete = (Movie*)auxMovie->next;
            if(!strcmp(  auxDelete->titulo  ,tituloAEliminar))
            {
                break;
            }
        }
        if(auxDelete == NULL)
        {
            printf("No se encontro la pelicula\n");
            return -1;
        }
        auxMovie->next = auxDelete->next;
        free(auxDelete);

    }

    return 0;
}


int modificar(Movie *peliculas)
{
    char tituloAModificar[51];
    Movie auxMovie;
    Movie *pAuxMovie = peliculas;
    while(pAuxMovie != NULL)
    {
        printf("TITULO: %s\n",pAuxMovie->titulo);
        pAuxMovie = (Movie*)pAuxMovie->next;
    }
    if(pedirString(tituloAModificar,"Ingrese el titulo a modificar\n",50,3,"El titulo de tener entre 3 y 50 caracteres\n") == -1)
    {
        return -1;
    }
    pAuxMovie = peliculas;
    while(pAuxMovie != NULL)
    {
        if(!strcmp(pAuxMovie->titulo,tituloAModificar))
        {
            break;
        }
        pAuxMovie = (Movie*)pAuxMovie->next;
    }
    if(pAuxMovie == NULL)
    {
        printf("No se encontro la pelicular\n");
        return -1;
    }

    int error = 0;
    error = pedirString(auxMovie.titulo,"Ingrese el titulo:\n",50,3,"El titulo de tener entre 3 y 50 caracteres\n");

    if(!error)
        error = pedirString(auxMovie.genero,"Ingrese el genero:\n",50,3,"El genero de tener entre 3 y 50 caracteres\n");
    if(!error)
        error = pedirString(auxMovie.duracion,"Ingrese la duracion(hh:mm):\n",5,5,"la duracion debe tener 5 caracteres\n");
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
    auxMovie.next = pAuxMovie->next;
    memcpy(pAuxMovie,&auxMovie,sizeof(Movie));
    return 0;
}

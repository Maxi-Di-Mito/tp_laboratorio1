#include <stdio.h>
#include <stdlib.h>
#include "../md_lib/lib.h"
typedef struct
{
    char titulo[51];
    char genero[51];
    char duracion[11];
    char descripcion[301];
    int puntaje;
    char linkImagen[201];
}Movie;

/** \brief Maneja la ejecucion de todo el programa
 *
 * \return devuelve 0 si la ejecucion fue exitosa o -1 si hubo un error
 *
 */
int run();



/** \brief Carga las MOVIE de un archivo binario a memoria

 * \param un puntero a la lista de punteros a MOVIE
 * \return cantidad de Movie cargados
 *
 */
int cargarPeliculasDesdeArchivoAMemoria(int *espacioReservado,Movie ***lista);



/** \brief Pide el ingreso de los datos, valida y carga la nueva pelicula en memoria
 *
 * \param peliculas
 * \param cantidadDePeliculas
 * \param espacioReservado
 * \return 0 OK , -1 ERROR
 *
 */
int agregarPelicula(Movie ***peliculas,int *cantidadDePeliculas,int *espacioReservado);


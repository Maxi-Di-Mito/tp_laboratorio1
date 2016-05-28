#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../md_lib/lib.h"

typedef struct
{
    char titulo[51];
    char genero[51];
    char duracion[11];
    char descripcion[301];
    int puntaje;
    char linkImagen[201];
    struct Movie *next;
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
int cargarPeliculasDesdeArchivoAMemoria(Movie **lista);



/** \brief Pide el ingreso de los datos, valida y carga la nueva pelicula en memoria
 *
 * \param peliculas
 * \return 0 OK , -1 ERROR
 *
 */
int agregarPelicula(Movie **peliculas);


/** \brief Salva las peliculas en memoria a un archivo binario.
 *
 * \param peliculas Movie**: array de pelculas
 * \param peliculas int cantidad de peliculas.
 * \return int 0 OK, -1 error
 *
 */
int salvarArchivoBinario(Movie *peliculas);


/** \brief Libera la memoria usada;
 *
 * \param peliculas Movie**
 * \param cantidadDePeliculas int
 * \return void
 *
 */
void liberarMemoria(Movie **peliculas);


/** \brief Genera un archivo html con la informacion de las peliculas.
 *
 * \param peliculas Movie*
 * \return int 0 OK, -1 ERROR
 *
 */
int generarWeb(Movie *peliculas);



/** \brief Lista las peliculas y permite eliminar una
 *
 * \param peliculas Movie**
 * \return int 0 OK, -1 ERROR
 *
 */
int borrarPelicula(Movie **peliculas);





/** \brief Lsita las peliculas y permite modificar los datos de una
 *
 * \param peliculas Movie*
 * \return int 0 OK, -1 ERROR
 *
 */
int modificar(Movie *peliculas);

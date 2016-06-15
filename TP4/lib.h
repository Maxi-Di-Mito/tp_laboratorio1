#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../md_lib/lib.h"
#include "../md_lib/ArrayList.h"


typedef struct
{
    char fechaCreacion[9];
    char descripcion[201];

}Evento;


typedef struct
{
    int anio;
    int mes;
    int dia;
}Fecha;


/** \brief Maneja el loop principal del programa
 *
 * \return int. 0 OK - -1 ERROR
 *
 */
int start();


/** \brief Imprime el menu de opciones
 *
 * \return void
 *
 */
void printMenu();



/** \brief permite ingresar los datos para un nuevo evento
 *
 * \return int 0 OK, -1 ERROR
 *
 */
int crearNuevoEvento(ArrayList *calendario);


/** \brief Imprime todos los eventos de la fecha ingresada
 *
 * \return int 0 OK, -1 ERROR
 *
 */
int consultarFecha();


/** \brief Permite buscar y modificar un evento.
 *
 * \return int 0 OK, -1 ERROR
 *
 */
int modificarEvento();


/** \brief Permite buscar y eliminar un evento.
 *
 * \return int
 *
 */
int eliminarEvento();


/** \brief Exporta a un archivo de texto todos los eventos del calendario dentro del rango especificado.
 *
 * \return int
 *
 */
int exportarCalendario(ArrayList *calendario);



/** \brief Vacia el array liberando la memoria de cada elemento contenido en el.
 *
 * \param list ArrayList*
 * \return int 0 OK, -1 ERROR
 *
 */
int limpiarMemoria(ArrayList *list);




/** \brief Valida que la cadena ingresada sea con formato de fecha AAAAMMDD
 *
 * \param fecha[9] char
 * \return int 0 OK, -1 NO MATCH
 *
 */
int validarFormatoFecha(char fecha[9]);




/** \brief Convierne un string en una structura FECHA
 *
 * \param fecha Fecha*
 * \param charfechaString[9]
 * \return int 0 OK, -1, ERROR
 *
 */
int fechaStringToLong(Fecha *fecha, char charfechaString[9]);


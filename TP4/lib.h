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
int consultarFecha(ArrayList *calendario);


/** \brief Permite buscar y modificar un evento.
 *
 * \return int 0 OK, -1 ERROR
 *
 */
int modificarEvento(ArrayList *calendario);


/** \brief Permite buscar y eliminar un evento.
 *
 * \return int
 *
 */
int eliminarEvento(ArrayList *calendario);


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
int fechaStringToFechaStruct(Fecha *fecha, char charfechaString[9]);



/** \brief Compara dos structuras evento por fecha de creacion
 *
 * \param e1 Evento*
 * \param e2 Evento*
 * \return int 0 IGUALES, positivo f1 > f2, negativo f1 < f2
 *
 */
int compararEventosPorFecha(Evento *e1, Evento *e2);



/** \brief devuelve un long que representa la fecha contenida en la structura
 * en un formato comparable numericamente
 *
 * \param fecha Fecha
 * \return long
 *
 */
long fechaStructToLong(Fecha fecha);



/** \brief Buscar el archivo binario previo y carga sus datos en memoria.
 *
 * \param calendario ArrayList*
 * \return int
 *
 */
int cargarEventosDeArchivo(ArrayList *calendario);




/** \brief Graba los eventos en memoria en un archivo binario
 *
 * \param calendario ArrayList*
 * \return int
 *
 */
int guardarEventosEnArchivo(ArrayList *calendario);





/** \brief Genera un archivo txt con todos los eventos
 *
 * \param calendario ArrayList*
 * \return int
 *
 */
int exportarEventosAArchivo(ArrayList *calendario);





/** \brief Limpiar todos los datos del calendario en memoria
 *
 * \param calendario ArrayList*
 * \return int
 *
 */
int limpiarCalendario(ArrayList *calendario);





/** \brief Pide el ingreso de una fecha con formato AAAAMMDD y valida
 *
 * \param dato char*
 * \return int
 *
 */
int pedirFecha(char* msg,char* dato);



/** \brief Calcula una sublista de eventos con un rango de fechas
 *
 * \param calendario ArrayList*
 * \param fechaInicio[9] char
 * \param fechaFinal[9] char
 * \return ArrayList*
 *
 */
ArrayList *calcularRango(ArrayList *calendario,char fechaInicio[9],char fechaFinal[9]);




/** \brief Imprime todos los eventos ordenados por fecha y con un id segun su posicion
 *
 * \param calendario ArrayList*
 * \return int 0 OK, -1 ERROR
 *
 */
int imprimirEventos(ArrayList *calendario);





/** \brief Remueve los elementos del calendario que no correspondan con el anio de la fecha indicada
 *
 * \param auxCalendario ArrayList*
 * \param anio[9] char
 * \return int
 *
 */
int filtrarCalendarioPorAnio(ArrayList *auxCalendario,char anio[9]);


/** \brief Compara dos eventos por el anio
 *
 * \param e1 Evento*
 * \param e2 Evento*
 * \return int
 *
 */
int compararEventoPorAnio(Evento *e1,Evento *e2);

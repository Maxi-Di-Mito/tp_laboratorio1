
/** \brief Pide confirmacion con un mensaje y dos opciones posibles,ofrece una cantidad de intentos
 *
 * \param mensaje char*
 * \param op1 char
 * \param op2 char
 * \param cantidadIntentos int
 * \return 1 si se eligio la primera opcion, 0 si fue la segunda
 *
 */
int confirmacion(char* mensaje, char op1, char op2,int cantidadIntentos);

/** \brief Pide confirmacion con un mensaje y dos opciones posibles
 *
 * \param mensaje char*
 * \param op1 char
 * \param op2 char
 * \return int
 *
 */
int confirmacionSinReintentos(char* mensaje, char op1, char op2);

/** \brief Intercambiar dos datos de lugar
 *
 * \param vp1 void* puntero al primer dato
 * \param vp2 void* puntero al segundo dato
 * \param size int tamaño en bytes de dato
 * \return void
 *
 */
void swap(void *vp1,void *vp2,int size);

/** \brief Pide el ingreso de un dato de tipo int y valida.Muestra un mensaje de prompt y un munsaje en caso de error. Ofrece posibilidad de reintentar
 *
 * \param dato int* puntero a donde guardar el dato
 * \param msg char* mensaje
 * \param max int maximo permitido
 * \param min int minimo permitido
 * \param errorMsg char* mesaje de error
 * \return int 0 si se pude obtener el dato, -1 en caso de error
 *
 */
int pedirInt(int *dato,char* msg, int max, int min, char* errorMsg);

/** \brief Pide el ingreso de un dato de tipo long y valida.Muestra un mensaje de prompt y un munsaje en caso de error. Ofrece posibilidad de reintentar
 *
 * \param dato long* puntero a donde guardar el dato
 * \param msg char* mensaje
 * \param max long maximo permitido
 * \param min long minimo permitido
 * \param errorMsg char* mesaje de error
 * \return long 0 si se pude obtener el dato, -1 en caso de error
 *
 */
int pedirLong(long *dato,char* msg, int max, int min, char* errorMsg);

/** \brief Pide el ingreso de un dato de tipo String y valida.Muestra un mensaje de prompt y un munsaje en caso de error. Ofrece posibilidad de reintentar
 *
 * \param dato char* puntero a donde guardar el dato
 * \param msg char* mensaje
 * \param max int maximo cantidad de caracteres
 * \param min int minimo cantidad de caracteres
 * \param errorMsg char* mesaje de error
 * \return long 0 si se pude obtener el dato, -1 en caso de error
 *
 */
 int pedirString(char* dato,char* msg, int max, int min, char*errorMsg);




 /** \brief Pide el ingreso de un dato de tipo String con formato que responsa a una regex usando una libreria externa y valida.Muestra un mensaje de prompt y un munsaje en caso de error. Ofrece posibilidad de reintentar
 *  LIB de regex -> https://github.com/cesanta/slre
 * \param dato char* puntero a donde guardar el dato
 * \param char* formato
 * \param msg char* mensaje
 * \param max int maximo cantidad de caracteres
 * \param min int minimo cantidad de caracteres
 * \param errorMsg char* mesaje de error
 * \return long 0 si se pude obtener el dato, -1 en caso de error
 *
 */int pedirStringConFormato(char* dato,char* formato,char* msg, int max, int min, char*errorMsg);

 /** \brief Pide el ingreso de un dato de tipo float y valida.Muestra un mensaje de prompt y un munsaje en caso de error. Ofrece posibilidad de reintentar
 *
 * \param dato long* puntero a donde guardar el dato
 * \param msg char* mensaje
 * \param errorMsg char* mesaje de error
 * \return long 0 si se pude obtener el dato, -1 en caso de error
 *
 */
int pedirFloat(float *dato, char* mensaje , char* errorMensaje);




/** \brief Ordenar una lista de elementos de cualquier tipo
 * \param lista  puntero a la lista de elementos
 * \param datasize  tamaño del dato que se va a ordenar
 * \param size  cantidad de elementos en la lista
 * \param cmp puntero a la funcion que compara
 * \param order  un char 'a' para orden ascendente y 'd' para descendente
 *
 * \return void
 */
void ordenar(void **lista, int size, int (*cmp)(void* ,void*),char order);


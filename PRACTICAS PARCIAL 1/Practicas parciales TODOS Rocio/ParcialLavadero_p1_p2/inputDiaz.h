/** \brief valida que se ingresen solo letras en array
 *
 * \param array que se desea validar
 * \param mensaje para imprimir en pantalla
 * \return 1 sino se ingresan letras
 *
 */
int validarCararteres(char letra[], char mensaje[]);


/** \brief valida que se ingresen solo numeros en array
 *
 * \param array que se desea validar
 * \param mensaje para imprimir en pantalla
 * \return 1 sino se ingresan numeros
 *
 */
int validarNumeros(char numero[],char mensaje[]);

/** \brief valida que se ingresen numeros y letras en array
 *
 * \param array que se desea validar
 * \param mensaje para imprimir en pantalla
 * \return 1 sino se ingresan numeros y letras
 *
 */
int validarAlphaNumeric(char letra[], char mensaje[]);

/** \brief obtiene array de letras
 *
 * \param array donde se va a asignar la validacion
 * \param tamanio maximo del array
 * \param mensaje para imprimir en pantalla
 * \return nada
 *
 */
void obtenerCadenaChar(char dondeAsginar[], int tamMax, char mensaje[]);

/** \brief obtiene array de letras y numeros
 *
 * \param array donde se va a asignar la validacion
 * \param tamanio maximo del array
 * \param mensaje para imprimir en pantalla
 * \return nada
 *
 */
void obtenerCadenaAlpaNumerica(char dondeAsginar[], int tamMax, char mensaje[]);

/** \brief valida mail
 *
 * \param array donde se va a asignar la validacion
 * \param tamanio maximo del array
 * \param mensaje para imprimir en pantalla
 * \return nada
 *
 */
void obtenerEmail(char dondeAsignar[], int tamMax, char mensaje []);


/** \brief valida telefono
 *
 * \param array donde se va a asignar la validacion
 * \param tamanio maximo del array
 * \param mensaje para imprimir en pantalla
 * \return nada
 *
 */
void obtenerTelefono(char dondeAsignar[], int tamMax, char mensaje[]);


/** \brief valida telefono
 *

 * \param mensaje para imprimir en pantalla
 * \return sexo validado
 *
 */
char obtenerSexo(char mensaje[]);

/** \brief valida numeros entre dos parametros
 *
 * \param int donde se va a asignar la validacion
 * \param tamanio maximo a validar
 * \param tamanio minimo a validar
 * \param mensaje para imprimir en pantalla
 * \return nada
 *
 */
int obtenerNumeroEntre(int tamMax, int tamMin, char mensaje[]);

/** \brief valida que un numero sea igual al que se asigne
 *
 * \param numero al que sea desea igualar
 * \param mensaje para imprimir en pantalla
 * \return numero validado
 *
 */
int obtenerNumeroIgualA(int numReferencia, char mensaje[]);

/** \brief genera id aleatorio
 *
 * \param tamanio maximo del aletario
 * \param tamanio minimo del aletario
 * \return id generado
 *
 */
int generarIdAletatorio(int tamMax, int tamMin);



void validarPatente(char dondeAsignar[], char mensaje[]);



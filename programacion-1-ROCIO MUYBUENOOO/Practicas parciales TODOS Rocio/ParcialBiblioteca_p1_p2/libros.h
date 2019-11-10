#include <stdio.h>
#include <stdlib.h>
#include "inputElian.h"

typedef struct
{
    int dia;
    int mes;
    int anyo;

} STR_Fecha;

typedef struct
{
    int id; //incremental
    char nombre[31];
    char apellido[31];
} STR_Autores;

typedef struct
{
    int id; //incremental
    char nombre[51];
    int idAutor; // debe existir
} STR_Libros;

typedef struct
{
    int id;
    char nombre[31];
    char apellido[31];
    char sexo;
    char telefono[16];
    char email [31];
    STR_Fecha fecha_Asociado;
    int isEmpty;
} STR_Socios;


typedef struct
{
    int id; //incremental
    int idLibro; // debe existir
    int idSocio; // debe existir
    STR_Fecha fecha_Prestamo;
    int isEmpty;
} STR_Prestamos;



//*Inicializacion*//
/**\brief Recibe un array de STR_Socios y asiga un numero al parametro "isEmpty de c/u de los elementos.
 * \param "cantidadElementos" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "iniciando" es el array de socios
 * \param "numeroQueSeAsigna" es el valor que se le da al parametro isEmpty
 * \return void
 */
void iniciarSociosIsEmpty ( STR_Socios iniciando[],int cantidadElementos,int numeroQueSeAsigna );

/**\brief Recibe un array de STR_Socios y asiga numeros de manera incremental al parametro ID , empezando desde el 1
 * \param "cantidadElementos" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "iniciando" es el array de socios
 * \return void
 */
void inciarIncrementalIdSocios (STR_Socios iniciando[], int cantidadElementos );

/**\brief Recibe un array de STR_Prestamos y asiga un numero al parametro "isEmpty de c/u de los elementos.
 * \param "cantidadElementos" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "iniciando" es el array de prestamos
 * \param "numeroQueSeAsigna" es el valor que se le da al parametro isEmpty
 * \return void
 */
void iniciarPrestamosIsEmpty ( STR_Prestamos iniciando[],int cantidadElementos,int numeroQueSeAsigna );

/**\brief Recibe un array de STR_Prestamos y asiga numeros de manera incremental al parametro ID , empezando desde el 1
 * \param "cantidadElementos" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "iniciando" es el array de prestamos
 * \return void
 */
void iniciarIncrementalIdPrestamos (STR_Prestamos iniciando[], int cantidadElementos );

//*Busqueda*//

/**\brief Recibe un array de STR_Socios y lo recorre hasta encontrar un lugar con parametro isEmpty == 1.
 * \param "cantidadSocios" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "socio" es el array de socios
 * \return el indice del primer lugar vacio en el array , o -1 si no se encuentra
 */
int buscarIdVacioSocio (STR_Socios socio[], int cantidadSocios);

/**\brief Recibe un array de STR_Socios y un Id, recorre el array hasta encontrar el indice del array correspondiente
 a ese id .
 * \param "cantidadSocios" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "socio" es el array de socios
 * \param "id" es el id que se busca
 * \return el indice correspondiente al id dado , o -1 si no se encuentra
 */
int buscarIndexPorIdSocio (STR_Socios socio[],int cantidadSocios, int id);

/**\brief Recibe un array de STR_Socios , lo recorre en busca de almenos UN elemento con isEmpty == 0.
 * \param "cantidadSocios" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "socio" es el array de socios
 * \return 1 si hay almenos 1 , 0 si no hay ninguno.
 */
int haySocios (STR_Socios socio[], int cantidadSocios);

/**\brief Recibe un array de STR_Prestamos y lo recorre hasta encontrar un lugar con parametro isEmpty == 1.
 * \param "cantidadSocios" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "prestamo" es el array de prestamos
 * \return el indice del primer lugar vacio en el array , o -1 si no se encuentra
 */
int buscarIdVacioPrestamo (STR_Prestamos prestamo[], int cantidadPrestamos);

/**\brief Recibe un array de STR_Prestamos y un Id, recorre el array hasta encontrar el indice del array correspondiente
 a ese id .
 * \param "cantidadPrestamos" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "prestamo" es el array de prestamos
 * \param "id" es el id que se busca
 * \return el indice correspondiente al id dado , o -1 si no se encuentra
 */
int buscarIndexPorIdPrestamo (STR_Prestamos prestamo[],int cantidadPrestamos,int id);

/**\brief Recibe un array de STR_Prestamos , lo recorre en busca de almenos UN elemento con isEmpty == 0.
 * \param "cantidadPrestamos" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "prestamo" es el array de prestamos
 * \return 1 si hay almenos 1 , 0 si no hay ninguno.
 */
int hayPrestamos (STR_Prestamos prestamo [], int cantidadPrestamos);

/**\brief Recibe un array de STR_Prestamos , lo recorre y cuenta los elementos con isEmpty == 0.
 * \param "cantidadPrestamos" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "prestamo" es el array de prestamos
 * \return la cantidad total de prestamos cargados .
 */
int buscarCantidadPrestamosCargados ( STR_Prestamos prestamo[],int cantidadPrestamos);

/**\brief Recibe un array de STR_Prestamos , lo ordena por fecha , y devuelve el promedio del total de
    prestamos y la cantidad de dias en que se realizaron prestamos.
 * \param "cantidadPrestamos" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "prestamo" es el array de prestamos
 * \return el promedio entre total de prestamos y la cantidad de dias en que se realizaron prestamos.
 */
float buscarPromedioDiarioPrestamos (STR_Prestamos prestamo [], int cantidadPrestamos);

/**\brief Recibe un array de STR_Prestamos , lo ordena por fecha , y cuenta cuantos dias diferentes hay
 * \param "cantidadPrestamos" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "prestamo" es el array de prestamos
 * \return la suma de las fechas diferentes
 */
int buscarCantidadDiasUnicosPrestamos(STR_Prestamos prestamo[], int cantidadPrestamos);

/**\brief Recibe un array de STR_Libros y un id, recorre hasta encontrar el elemento que coincida con el id.
 * \param "cantidadLibros" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "libro" es el array de libros
 * \param "id" es el id que se busca
 * \return el indice en el array que coincide con el id , o -1 si no se encuentra.
 */
int buscarIndexPorIdLibro(STR_Libros libro[],int cantidadLibros,int id);

//orden//
/**\brief Recibe un array de STR_Prestamos , lo ordena por fecha , año>mes>dia de menor a mayor.
 * \param "cantidadPrestamos" es la cantidad maxima de elementos que tiene el array de estructuras.
 * \param "prestamo" es el array de prestamos
 * \return void
 */
void ordenarPrestamosPorFecha (STR_Prestamos * prestamo, int cantidadPrestamos);

//*Hardcode*//

/**\brief Recibe un array de STR_Libros , carga 10 elementos con datos inventados.
 * \param "lista" es el array donde se cargan los datos
 * \return void
 */
void hardCodeLibros(STR_Libros lista[]);

/**\brief Recibe un array de STR_Autores , carga 10 elementos con datos inventados.
 * \param "lista" es el array donde se cargan los datos
 * \return void
 */
void hardCodeAutores(STR_Autores lista[]);

/**\brief Recibe un array de STR_Socios , carga 10 elementos con datos inventados.
 * \param "lista" es el array donde se cargan los datos
 * \return void
 */
void hardCodeSocios(STR_Socios lista[]);

/**\brief Recibe un array de STR_Prestamos , carga 10 elementos con datos inventados.
 * \param "lista" es el array donde se cargan los datos
 * \return void
 */
void hardCodePrestamos (STR_Prestamos lista[]);

//*Menu*//

/**\brief Muestra un menu de opciones por pantalla.
 * \return void
 */
void menu (void);

//*Listar*//

/**\brief Lista todos los libros cargados y sus respectivos id y autores.
 * \param "autor" es el array de autores.
 * \param "libro" es el arrray de libros.
 * \param "cantidadAutores" es la cantidad total de autores cargados.
 * \param "cantidadLibros" es la cantidad total de libros cargados.
 * \return void
 */
void listarLibros (STR_Autores autor[],int cantidadAutores,STR_Libros libro[], int cantidadLibros );

/**\brief Lista todos los autores cargados.
 * \param "autor" es el array de autores.
 * \param "cantidadAutores" es la cantidad total de autores cargados.
 * \return void
 */
void listarAutores(STR_Autores autor [],int cantidadAutores);

/**\brief Lista todos los socios cargados.
 * \param "socio" es el array de socios.
 * \param "cantidadSocios" es la cantidad maxima de socios.
 * \return void
 */
void listarSocios (STR_Socios socio [], int cantidadSocios);

/**\brief Lista todos los prestamos cargados y sus respectivos socios y libros.
 * \param "prestamo" es el array de prestamos.
 * \param "libro" es el arrray de libros.
 * \param "socio" es el arrray de socios.
 * \param "cantidadPrestamos" es la cantidad maxima de prestamos
 * \param "cantidadSocios" es la cantidad maxima de socios.
 * \param "cantidadLibros" es la cantidad total de libros cargados.
 * \return void
 */
void listarPrestamos (STR_Prestamos prestamo[], int cantidadPrestamos,STR_Socios socio[], int cantidadSocios, STR_Libros libro[], int cantidadLibros);

/**\brief Lista el total de prestamos , la cantidad de dias en que se realizaron prestamos
    y el promedio entre la cantidad de dias en que se realizaron prestamos.
 * \param "prestamo" es el array de prestamos.
 * \param "cantidadPrestamos" es la cantidad total de prestamos.
 * \return void
 */
void listarTotalYPromedio(STR_Prestamos prestamo[],int cantidadPrestamos);

/**\brief Lista la cantidad de dias en que no se supero el promedio diario de prestamos.
 * \param "prestamo" es el array de prestamos.
 * \param "cantidadPrestamos" es la cantidad total de prestamos.
 * \return void
 */
void listarDiasPorDebajoPromedio(STR_Prestamos prestamos [], int cantidadPrestamos );

/**\brief Muestra y pide al usuario que seleccione un libro, lista todos los prestamos
    realizados de ese libro.
 * \param "prestamo" es el array de prestamos.
 * \param "cantidadPrestamos" es la cantidad total de prestamos.
 * \param "socio" es el array de socios.
 * \param "cantidadSocios" es la cantidad total de socios.
 * \param "libro" es el array de libros.
 * \param "cantidadlibros" es la cantidad de libros cargados.
 * \param "autor" es el array de autores.
 * \param "cantidadAutores" es la cantidad de autores cargados.
 * \return Si no hay prestamos cargados , lo informa por pantalla y vuelve al menu.
 */
void listarPrestamosDeUnLibro(STR_Prestamos prestamo[],int cantidadPrestamos,STR_Socios socio[],int cantidadSocios,STR_Libros libro[],int cantidadLibros,
                              STR_Autores autor[],int cantidadAutores);

/**\brief Lista todos los libros que fueron menos solicitados, e informa la cantidad de prestamos
    realizados a esos libros.
 * \param "prestamo" es el array de prestamos.
 * \param "cantidadPrestamos" es la cantidad total de prestamos.
 * \param "libro" es el array de libros.
 * \param "cantidadlibros" es la cantidad de libros cargados.
 * \return void
 */
void listarLibrosMenosSolicitados (STR_Prestamos*prestamo,int cantidadPrestamos,STR_Libros * libro,int cantidadLibros);

/**\brief Lista todos los socios que realizaron la mayor cantidad de prestamos , e informa la cantidad
    de prestamos que esos socios realizaron.
 * \param "prestamo" es el array de prestamos.
 * \param "cantidadPrestamos" es la cantidad total de prestamos.
 * \param "socio" es el array de socios.
 * \param "cantidadSocios" es la cantidad maxima de socios .
 * \return void
 */
void listarSociosConMasPrestamos (STR_Prestamos*prestamo,int cantidadPrestamos,STR_Socios * socio,int cantidadSocios);

/**\brief Muestra y pide al usuario que seleccione un socio, lista todos los prestamos
    realizados de ese socio.
 * \param "prestamo" es el array de prestamos.
 * \param "cantidadPrestamos" es la cantidad total de prestamos.
 * \param "socio" es el array de socios.
 * \param "cantidadSocios" es la cantidad total de socios.
 * \param "libro" es el array de libros.
 * \param "cantidadlibros" es la cantidad de libros cargados.
 * \return Si no hay prestamos cargados , lo informa por pantalla y vuelve al menu.
 */
void listarPrestamosDeUnSocio(STR_Prestamos prestamo[],int cantidadPrestamos,STR_Socios socio[],int cantidadSocios,STR_Libros libro[],int cantidadLibros);

/**\brief Pide al usuario que ingrese una fecha , lista todos los libros prestados en la fecha
    ingresada
 * \param "prestamo" es el array de prestamos.
 * \param "cantidadPrestamos" es la cantidad total de prestamos.
 * \param "libro" es el array de libros.
 * \param "cantidadlibros" es la cantidad de libros cargados.
 * \return Si no hay prestamos cargados , lo informa por pantalla y vuelve al menu.
 */
void listarLibrosPorFechaPrestamo(STR_Prestamos prestamo [],int cantidadPrestamos, STR_Libros libro[],int cantidadLibros);

/**\brief Pide al usuario que ingrese una fecha , lista todos los socios que realizaron prestamos
 en la fecha ingresada
 * \param "prestamo" es el array de prestamos.
 * \param "cantidadPrestamos" es la cantidad total de prestamos.
 * \param "socio" es el array de socios.
 * \param "cantidadSocios" es la cantidad total de socios.
 * \return Si no hay prestamos cargados , lo informa por pantalla y vuelve al menu.
 */
void listarSociosPorFechaPrestamo (STR_Prestamos prestamo [],int cantidadPrestamos, STR_Socios socio[],int cantidadSocios);


/**\brief Ordena a los socios por apellido con el metodo de insercion y los lista por
    pantalla.
 * \param "socio" es el array de socios.
 * \param "cantidadSocios" es la cantidad total de socios.
 * \return void
 */
void listarSociosInsercion (STR_Socios socio[],int cantidadSocios);

/**\brief Ordena a los libros por nombre con el metodo de burbujeo y los lista por
    pantalla.
 * \param "libro" es el array de socios.
 * \param "cantidadLibros" es la cantidad total de libros cargados.
 * \return void
 */
void listarLibrosBurbujeo(STR_Libros libro[], int cantidadLibros);


//*Altas*//

/**\brief Busca un lugar vacio en el array de socios, si lo encuentra, le pide al usuario
    que ingrese todos los datos de un socio a dar de alta.
 * \param "socio" es el array de socios.
 * \param "cantidadSocios" es la cantidad total de socios .
 * \return Si no queda lugar , informa por pantalla.
 */
void altaSocio (STR_Socios socio [], int cantidadSocios);

/**\brief Busca un lugar vacio en el array de prestamos,verifica que haya socios cargados,
    le pide al usuario que seleccione el socio a quien corresponde el prestamo y que
    cargue todos los datos de un prestamo a dar de alta .
 * \param "prestamo" es el array de prestamos.
 * \param "cantidadPrestamos" es la cantidad total de prestamos.
 * \param "socio" es el array de socios.
 * \param "cantidadSocios" es la cantidad total de socios.
 * \param "libro" es el array de libros.
 * \param "cantidadlibros" es la cantidad de libros cargados.
 * \param "autor" es el array de autores.
 * \param "cantidadAutores" es la cantidad de autores cargados..
 * \return Si no queda lugar , si no hay socios , o si el socio elegido no existe , informa por pantalla.
 */
void altaPrestamo( STR_Prestamos prestamos[], STR_Libros libro [],int cantidadLibros, STR_Socios socio[],int cantidadSocios, STR_Autores autor[],int cantidadAutores);

//*Modificacion*//

/**\brief Lista todos los socios cargados , pide al usuario que seleccione uno y
    se le permite modificar uno de los parametros de ese socio especifico.
 * \param "socio" es el array de socios.
 * \param "cantidadSocios" es la cantidad maxima de socios.
 * \return Si no hay socios cargados, si el socio seleccionado no existe ,
    si el usuario cancela la modificacion , se informa por pantalla y se
    vuelve al menu.
 */
void modificarSocio (STR_Socios socio [], int cantidadSocios);

//*Baja*//

/**\brief Lista todos los socios cargados , pide al usuario que seleccione uno y
    y se da de baja
 * \param "socio" es el array de socios.
 * \param "cantidadSocios" es la cantidad maxima de socios.
 * \return Si no hay socios cargados, si el socio seleccionado no existe ,
    si el usuario cancela la baja , se informa por pantalla y se
    vuelve al menu.
 */
void bajaSocio(STR_Socios socio [], int cantidadSocios);

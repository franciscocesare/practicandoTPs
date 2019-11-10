#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idAl;
    int idJuego;
    int idCliente;
    eFecha alquiler;
    int isEmpty;
}eAlquiler;

#endif // ALQUILERES_H_INCLUDED

/** \brief lista de alquileres precargados para testeo
 *
 * \param estructura alquiler
 * \param tamanio de la estructura
 * \param cantidad de lineas de datos que se desea cargar
 * \return cantidad de lineas de datos que se cargaron
 *
 */
int harcodearAlquileres(eAlquiler vec[], int tam, int cant);


/** \brief inicializa la varible isEmpty de la estructura alquiler en vacio
 *
 * \param estructura alquiler
 * \param tamanio de la estructura
 *
 */
void inicializarAlquiler(eAlquiler vec[], int tam);


/** \brief buscar un indice vacio en la estructura alquiler
 *
 * \param estructura alquiler
 * \param tamanio de la estructura
 * \return -1 sino encuentra lugar libre, de lo contrario devuelve el indice libre que se hayo
 *
 */
int buscarLibreAlquiler(eAlquiler vec[],int tam);


/** \brief muestra un solo dato de la estuctura alquiler
 *
 * \param estructura alquileres
 * \param estructura juegos
 * \param tamanio estructura juegos
 * \param estructura clientes
 * \param tamanio estructura clientes
 * \return sin retorno
 *
 */
void mostrarAlquiler(eAlquiler vec, eJuego juego[], int tamJ, eCliente cliente[], int tamC);


/** \brief muestra todos los datos de la estuctura alquiler
 *
 * \param estructura alquileres
 * \param tamanio estructura alquileres
 * \param estructura juegos
 * \param tamanio estructura juegos
 * \param estructura clientes
 * \param tamanio estructura clientes
 * \return sin retorno
 *
 */
void mostrarAlquileres(eAlquiler vec[], int tam, eJuego juego[], int tamJ, eCliente cliente[], int tamC);


/** \brief carga en el sistema los datos de un alquiler
 *
 * \param estructura alquileres
 * \param tamanio estructura alquileres
 * \param estructura juegos
 * \param tamanio estructura juegos
 * \param estructura clientes
 * \param tamanio estructura clientes
 * \param tamanio estructura categorias
 * \param estructura categorias
 * \param id de alquiler
 * \return 0 sino se pudo dar de alta, 1 si se dio de alta
 *
 */
int altaAlquiler(eAlquiler vec[], int tam, eJuego juego[], int tamJ, eCliente cliente[], int tamC,eCategoria cat[], int tCat, int id);

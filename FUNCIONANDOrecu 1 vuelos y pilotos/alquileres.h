#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

/*typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;
*/

typedef struct
{
    int idVuelo;
    int idDestino;
    int idPiloto;
   /// eFecha alquiler;
   int horaPartida;
   int horaLlegada;
   char estado[51]; ///vhardcodear ACTIVO, SUSPENDIDO, DEMORADO, CANCELADO ES EL ESTADO
   int isEmptyVuelos;

}eVuelo;

#endif // ALQUILERES_H_INCLUDED

/** \brief lista de alquileres precargados para testeo
 *
 * \param estructura alquiler
 * \param tamanio de la estructura
 * \param cantidad de lineas de datos que se desea cargar
 * \return cantidad de lineas de datos que se cargaron
 *
 */
int harcodearVuelos(eVuelo vecVue[], int tamVue, int cant);


/** \brief inicializa la varible isEmpty de la estructura alquiler en vacio
 *
 * \param estructura alquiler
 * \param tamanio de la estructura
 *
 */
void inicializarVuelos(eVuelo vecVue[], int tamVue); ///esta bien???


/** \brief buscar un indice vacio en la estructura alquiler
 *
 * \param estructura alquiler
 * \param tamanio de la estructura
 * \return -1 sino encuentra lugar libre, de lo contrario devuelve el indice libre que se hayo
 *
 */
int buscarLibreVue(eVuelo vecVue[],int tamVue);


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
///void mostrarAlquiler(eAlquiler vec, eJuego juego[], int tamJ, eCliente cliente[], int tamC);
void mostrarVuelo(eVuelo vecVue, eDestino destino[], int tamD, ePiloto piloto[], int tamPil);

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

 ///void mostrarVuelos(eAlquiler vec[], int tam, eJuego juego[], int tamJ, eCliente cliente[], int tamC);
void mostrarVuelos(eVuelo vecVue[], int tamVue, eDestino destino[], int tamD, ePiloto piloto[], int tamPil);


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
///int altaVuelo(eAlquiler vec[], int tam, eJuego juego[], int tamJ, eCliente cliente[], int tamC,eCategoria cat[], int tCat, int id);
int altaVuelo(eVuelo vuelo[], int tamV,ePiloto piloto[], int tamPil, eDestino destino[], int tamD, int idVuelo);

eVuelo newVuelo(int idVuelo,int idDestino,int idPiloto,int partida,int llegada, char estado[]);

void bajaVuelo(eVuelo vecVue[], int tamVue, eDestino vecDest [], int tamD, ePiloto pil [], int tamPil);

int buscarVueloPorId(int idVuelo, eVuelo vecVue[], int tamVue);

int modificarVuelo(eVuelo vec[], int tam, eDestino dest[], int tamD, ePiloto pil[], int tamP);

///void bajaCliente(eCliente vec[], int tam)


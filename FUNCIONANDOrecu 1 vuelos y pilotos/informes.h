#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief muestra menu de infores
 *
 * \param sin parametros
 * \return numero de la opcion elegida
 *
 */
int menuInformes();


/** \brief muestra los alquileres dados de alta por un cliente seleccionado
 *
 * \param estructura cliente
 * \param tamanio de estrcutura cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \param estructura categorias
 * \param tamanio de estrcutura categorias
 * \param estructura juegos
 * \param tamanio de estrcutura juegos
 * \return sin retorno
 *
 */
///void mostrarAlquilerPorCliente(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ);



/** \brief muestra el importe total de los alquileres efectuados por un cliente seleccionado
 *
 * \param estructura cliente
 * \param tamanio de estrcutura cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \param estructura categorias
 * \param tamanio de estrcutura categorias
 * \param estructura juegos
 * \param tamanio de estrcutura juegos
 * \return sin retorno
 *
 */
///void mostrarImporteCliente(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ);


/** \brief listado de juegos solo de mesa
 *
 * \param estructura juegos
 * \param tamanio de estrcutura alquiler
 * \param estructura categorias
 * \param tamanio de estrcutura juegos
 * \return sin retorno
 *
 */
///void mostrarJuegosMesa(eJuego juego[], int tamJ,eCategoria cat[], int tamC);


/** \brief muestra clientes con o sin alquileres efectuados
 *
 * \param id del cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \return 1 para mostrar clientes con alquiler, 0 para mostrar clientes sin alquileres
 *
 */
///int mostrarAlquileresClientes(int idCliente,eAlquiler vec[],int tamAl);


/** \brief muestra clientes sin alquileres efectuados
 *
 * \param estructura cliente
 * \param tamanio de estrcutura cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \return sin retorno
 *
 */
///void clientesSinAlquiler(eCliente vecCl[],int tamCl, eAlquiler vecAl[],int tamAl);


/** \brief muestra juegos con o sin alquileres efectuados
 *
 * \param id del juego
 * \param estructura juegos
 * \param tamanio de estrcutura juegos
 * \return 1 para mostrar juegos con alquiler, 0 para mostrar juegos sin alquileres
 *
 */
///int mostrarJuegosAlquilados(int idJuego,eAlquiler vec[],int tam);

void vuelosPilotoSeleccionado(eVuelo vuelos[], int tamVue, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDest);
void pilotosDestinoSeleccionado (eVuelo vuelos[], int tamVue, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDest);
void recaudacionPilotoSeleccionado(ePiloto piloto [], int tamPil, eVuelo vuelo [], int tamVue, eDestino destino [], int tamD);

///void destinoMasElegido(eVuelo vue[], int tamVue,eDestino des[], int tamD); MIO FUNCIONA MAL

void destinoMasElegido(eDestino destinos[], int tamDes, eVuelo vuelos[], int tamVuelo);///MANU
int cantidadDestinos(int idDestino, eVuelo vuelos[], int tamVuelo);///MANU

///void juegosSinAlquiler(eJuego vecJ[],int tamJ, eAlquiler vecAl[],int tamAl, eCategoria vecCa[], int tamCa);

#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

typedef struct
{
    int iDdestino;
    char descripcion[30];
    float importe;
    ///int idCategoria;

}eDestino;

#endif // JUEGO_H_INCLUDED
#include "categoria.h"

/** \brief lista de juegos precargadas para testeo
 *
 * \param estructura juegos
 * \param tamanio de la juegos
 * \param cantidad de lineas de datos que se desea cargar
 * \return sin retorno
 *
 */
void harcodearDestino(eDestino vecDes[], int tamD);


/** \brief muestra un solo dato de la estuctura juegos
 *
 * \param estructura juegos
 * \return sin retorno
 *
 */
///void mostrarJuego(eJuego juego, eCategoria cat[], int tam);
void mostrarDestino (eDestino destino);


/** \brief muestra todos los datos de la estuctura juegos
 *
 * \param estructura juegos
 * \param tamanio estructura juegos
 * \return sin retorno
 *
 */
///void mostrarJuegos(eJuego juego[],int tamJ, eCategoria cat[], int tamC);
void mostrarDestinos (eDestino destino [], int tamD);


/** \brief obtiene nombre de un juego a traves del id
 *
 * \param estructura juegos
 * \param tamanio estructura juegos
 * \param id del juego a a buscar
 * \param donde asignar nombre obtenido
 * \return sin retorno
 *
 */
///void obtenerNomJuego(eJuego vec[], int tam, int id, char dondeAsignar[]);
void obtenerNomDestino (eDestino vecDes[], int tamD, int idDestino, char dondeAsignar[]);

#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int idPiloto;
    char nombre[51];

}ePiloto;

#endif // CLIENTES_H_INCLUDED

void harcodearPilotos(ePiloto piloto[], int tamPil);

/** \brief inicializa la varible isEmpty de la estructura cliente en vacio
 *
 * \param estructura cliente
 * \param tamanio de la estructura
 *
 */
///void inicializarClientes(eCliente vec[], int tam);


 /** \brief buscar un indice vacio en la estructura cliente
 *
 * \param estructura cliente
 * \param tamanio de la estructura
 * \return -1 sino encuentra lugar libre, de lo contrario devuelve el indice libre que se hayo
 *
 */
///int buscarLibrePiloto(ePiloto[],int tamPil);



/** \brief muestra un solo dato de la estuctura cliente
 *
 * \param estructura cliente
 * \return sin retorno
 *
 */
void mostrarPiloto(ePiloto vecPil);


/** \brief muestra todos los datos de la estuctura cliente
 *
 * \param estructura cliente
 * \param tamanio estructura cliente
 * \return sin retorno
 *
 */
void mostrarPilotos(ePiloto vecPil[], int tamPil);


/** \brief busca cliente por medio del id
 *
 * \param estructura cliente
 * \param tamanio estructura cliente
 * \return -1 sino encuentre indice con ese id, sino devuelve el indice del id
 *
 */
int buscarPilotoId(ePiloto vecPil[], int tamPil, int id);


/** \brief carga en el sistema los datos de un cliente
 *
 * \param estructura clientes
 * \param tamanio estructura clientes
 * \param id de cliente
 * \return 0 sino se pudo dar de alta, 1 si se dio de alta
 *
 */
///int altaCliente(eCliente vec[], int tam,int id);


/** \brief da de baja del sistema a un cliente
 *
 * \param estructura clientes
 * \param tamanio estructura clientes
 * \return sin retorno
 *
 */
///void bajaCliente(eCliente vec[], int tam);


/** \brief ordena lista de clientes por apellido y nombre de manera ascendente
 *
 * \param estructura clientes
 * \param tamanio estructura clientes
 * \return sin retorno
 *
 */
void ordenarPilotos(ePiloto vecPil[], int tamPil);


/** \brief muestra menu de modificacion
 *
 * \param sin parametros
 * \return numero de la opcion elegida
 *
 */
///int menuModificacion();


/** \brief permite modificar algun dato especifico de un cliente
 *
 * \param estructura clientes
 * \param tamanio estructura clientes
 * \return sin retorno
 *
 */
///void modificarCliente(eCliente vec[], int tam);


/** \brief obtiene nombre de un cliente a traves del id
 *
 * \param estructura clientes
 * \param tamanio estructura clientes
 * \param id de la categoria a buscar
 * \param donde asignar nombre obtenido
 * \return sin retorno
 *
 */
void obtenerNomPiloto(ePiloto vecPil[], int tamPil, int id, char dondeAsigar[]);

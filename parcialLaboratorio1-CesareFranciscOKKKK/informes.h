#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
///revisar todasssss

int menuInformes();
void mostrarAlquilerPorCliente(eCliente cliente[],int tam, eAlquileres alq[],int tamAl,
                               eCategoria cat[],int tamC, eJuego juegos[],int tamJ, eLocalidad loc[],int tamLoc);
void mostrarImporteCliente(eCliente cliente[],int tam, eAlquileres alq[],int tamAl,
                           eCategoria cat[],int tamC, eJuego juegos[],int tamJ, eLocalidad loc[], int tamLoc);
void mostrarJuegosMesa(eJuego juego[], int tamJ,eCategoria cat[], int tamC);
int mostrarAlquileresClientes(int idCliente,eAlquileres vec[],int tamAl);
void clientesSinAlquiler(eCliente vecClientes[],int tamCl, eAlquileres vecAlquiler[],int tamAl, eLocalidad loc[], int tamLoc);
int mostrarJuegosAlquilados(int idJuego,eAlquileres vec[],int tam);
void juegosSinAlquiler(eJuego vecJ[],int tamJ, eAlquileres vecAl[],int tamAl, eCategoria vecCa[], int tamCa);
void mostrarDatosAlquilerJuego(eAlquileres alquiler, eCliente clientes[], int tamCl);
void obtenerDatosAlquilerJuego (eJuego juegos[], int tamJuegos, eAlquileres vecAlqui[], int tamAlq, eCategoria cat[], int tamCat,eCliente clientes[], int tamCl);
void clientesDeterminadaLocalidad(eCliente vecClientes[],int tamCl, eLocalidad vecLoc[],int tamLoc);


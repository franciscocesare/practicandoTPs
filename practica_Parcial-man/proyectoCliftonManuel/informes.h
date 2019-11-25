#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "juego.h"
#include "categoria.h"
#include "cliente.h"
#include "alquiler.h"

void mostrarInformes(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat, eJuego juegos[], int tamJuego, eLocalidad localidades[], int tamLoc);
void mostrarJuegosCategoriaMesa(eJuego juegos[], int tamJuego, eCategoria categorias[], int tamCat);
void alquileresPorCliente(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli, eJuego juegos[], int tamJuego, eLocalidad localidades[], int tamLoc);
void deudaPorCliente(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego, eLocalidad localidades[], int tamLoc);
void clientesQueNoAlquilaron(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eLocalidad localidades[], int tamLoc);
int cantidadDeClietePorAlquiler( eAlquiler alquileres[], int tamAlq, int idCliente);
void juegosQueNoAlquilaron(eJuego juegos[], int tamJuego, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat);
int cantidadDeJuegosPorAlquiler( eAlquiler alquileres[], int tamAlq, int idJuego);


void mostrarClientePorLocalidad(eLocalidad localidades[], int tamLoc, eCliente clientes[], int tamCli);
int cantidadJuegosPorLocalidad(eAlquiler alquileres[], int tamAlq, int idJuego);
void juegoPreferidoPorLocalidad(eJuego juegos[], int tamJuego, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamLoc, eCliente clientes[], int tamCli);
void juegosAlquialdosPorMujeres(eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego, eCliente clientes[], int tamCli, eCategoria categorias[], int tamCat);
int menuInformes();


#endif // INFORMES_H_INCLUDED

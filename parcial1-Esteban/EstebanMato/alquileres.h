#include "cliente.h"

#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct
{
    int codigo;
    char descripcion[51];
    int importe;
    int idCategoria;
}eJuego;

typedef struct
{
    int id;
    char descrpcion [51];
}eCategoria;


typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codAlquiler;
    int codJuego;
    int codCliente;
    eFecha fecha;
    int isEmpty;
}eAlquileres;

#endif // ALQUILERES_H_INCLUDED

int altaAlquiler(eAlquileres alquileres[], int tamA, eJuego juegos[], int tamJ, eClientes clientes[], int tamC,int idAlquiler);
int buscarLibreAlquiler(eAlquileres listaA[], int tamA);
int initAlquileres(eAlquileres listaAlq[], int tamA);
void listarAlquileres(eAlquileres alquileres[], int tamA);
void printJuegos(eJuego juegos[], int tamJ);

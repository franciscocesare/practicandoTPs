#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

typedef struct
{
    int codigo;
    char descripcion[21];
    float importe;
    int idCategoria;

}eJuego;

#endif // JUEGO_H_INCLUDED
#include "categoria.h"

void harcodearJuego(eJuego vec[], int tam);
void mostrarJuego(eJuego juego, eCategoria cat[], int tam);
void mostrarJuegos(eJuego juego[],int tamJ, eCategoria cat[], int tamC);
void obtenerNomJuego(eJuego vec[], int tam, int id, char dondeAsignar[]);

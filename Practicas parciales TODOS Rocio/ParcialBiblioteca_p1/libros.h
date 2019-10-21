#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct
{
    int id;
    char titulo [51];
    int idAutor;

} eLibro;

#endif // LIBROS_H_INCLUDED

#include "autores.h"

int hardCodeLibros(eLibro lista[],int tam, int cant);
int buscarLibroId(eLibro vec[], int tam, int id);
void mostrarLibro(eLibro vec, eAutores autor[],int tam);
void mostrarLibros(eLibro vec[], int tam, eAutores autores[],int tAutor);
void ordenarLibros(eLibro vec[], int tam);
void obtenerNomLibro(eLibro vec[],int tam,int id, char dondeAsignar[]);

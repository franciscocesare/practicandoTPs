#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#include "generosActores.h"

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int idPelicula;
    int codigo;
    char titulo[50];
    eFecha fechaEstreno;
    int idActor;
    int idGenero;
    int estado;

} ePeliculas;

#endif // PELICULAS_H_INCLUDED


//FUNCIONES PELICULAS
void inicilizarPeliculas(ePeliculas vec[],int tam);
int buscarLibrePeliculas(ePeliculas vec[],int tam);
void mostrarPelicula(ePeliculas vec,eGenero vecG[], int tamG, eActores vecA[],int tamA);
int mostrarPeliculas(ePeliculas vec[],int tam,eGenero vecG[], int tamG, eActores vecA[],int tamA);
int buscarCodigo(ePeliculas vec[],int tam,int codigo);
int altaPelicula(ePeliculas vec[],int tam,eActores vecA[], int tamA,eGenero vecG[],int tamG,int id);
int menuModificacion();
int modificarPelicula(ePeliculas vec[],int tam,eActores vecA[], int tamA,eGenero vecG[],int tamG);
int bajaPelicula(ePeliculas vec[],int tam,eActores vecA[], int tamA,eGenero vecG[],int tamG);
int hardcodeoPeliculas(ePeliculas vec[],int tam, int cantidad);
int menuPrincipal();

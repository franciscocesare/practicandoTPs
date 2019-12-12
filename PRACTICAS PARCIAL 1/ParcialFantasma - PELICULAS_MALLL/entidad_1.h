#ifndef ENTIDAD_1_H_INCLUDED
#define ENTIDAD_1_H_INCLUDED

#include "entidad_2.h"

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
    int idActor;
    int idGenero;
    eFecha fechaEstreno;
    int estado;


} ePelicula;

#endif // ENTIDAD_1_H_INCLUDED


///void hardcodearPeliculas(ePelicula vec[], int tam); ///SI NO TIENE CAMPO ISEMPTY

int hardcodearPeliculas(ePelicula vec[], int tam, int cant);///SI TIENE CAMPO ISEMPTY

void inicializarPeliculas(ePelicula vec[], int tam);///INICIALIZAR LA ESTRUC QUE TIENE CAMPO ISEMPTY PARA PONERLOS EN 1, INAACTIVOS

int buscarLibre(ePelicula vec[], int tam); ///SE VA A USAR CUANDO DEMOS UN ALTA

void mostrarPelicula(ePelicula peli,eGenero vecGen[], int tamG, eActores vecAc[], int tamAc); ///NOMOBRE DE LA ESTRUCTURA Y DE UN DATO. si van mas estruct voy a tener que obtener los datos de cada una

int buscarCodigo(ePelicula vec[],int tam,int codigo);
///void mostrarVuelo(eVuelo vecVue, eDestino destino[], int tamD, ePiloto piloto[], int tamPil); SI ES UN MOSTRAR CON OBTENER

///void obtenerNomPiloto(ePiloto vecPil[], int tamPil, int id, char dondeAsigar[]);

void mostrarPeliculas(ePelicula vec[], int tam, eGenero vecGen[], int tamG, eActores vecAc[], int tamAc);

int altaPelicula(ePelicula vec[], int tam, eGenero vecGen[], int tamG, eActores vecAc[], int tamAc);

void bajaPelicula(ePelicula vec[], int tam, eGenero vecGen[], int tamG, eActores vecAc[], int tamAc);

int modificarPelicula(ePelicula vec[], int tam, eGenero vecGen[], int tamG, eActores vecAc[], int tamAc); ///ACA VAN LAS ESTRUC QUE INFLUYEN EN LA MODIFICACION,A VACES ES UNA SOLA

int menuModificacion();

int buscarPeliculaPor_id(int id, ePelicula vec[], int tam);

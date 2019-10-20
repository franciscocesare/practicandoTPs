#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idAl;
    int idJuego;
    int idCliente;
    eFecha alquiler;
    int isEmpty;
}eAlquiler;

#endif // ALQUILERES_H_INCLUDED

int harcodearAlquileres(eAlquiler vec[], int tam, int cant);
void inicializarAlquiler(eAlquiler vec[], int tam);
int buscarLibreAlquiler(eAlquiler vec[],int tam);
void mostrarAlquiler(eAlquiler vec, eJuego juego[], int tamJ, eCliente cliente[], int tamC);
void mostrarAlquileres(eAlquiler vec[], int tam, eJuego juego[], int tamJ, eCliente cliente[], int tamC);
int altaAlquiler(eAlquiler vec[], int tam, eJuego juego[], int tamJ, eCliente cliente[], int tamC,eCategoria cat[], int tCat, int id);

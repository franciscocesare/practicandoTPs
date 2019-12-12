#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

typedef struct
{
    int id;
    int idLibro;
    int idSocio;
    eFecha prestamos;
    int isEmpty;

} ePrestamo;


#endif // PRESTAMOS_H_INCLUDED

void iniciarlizarPrestamos(ePrestamo vec[], int tam);
int hardCodePrestamos (ePrestamo lista[],int tam, int cant);
int buscarLibrePrestamo(ePrestamo vec[],int tam);
void mostrarPrestamo(ePrestamo vec, eSocio socio[],int tamS, eLibro libro[],int tamL);
void mostrarPrestamos(ePrestamo vec[], int tam, eSocio socio[],int tamS, eLibro libro[],int tamL);
int altaPrestamo(ePrestamo vec[], int tam, eSocio socio[],int tamS, eLibro libro[],int tamL,eAutores autores[], int tamA, int id);

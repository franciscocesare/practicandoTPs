#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "libros.h"
#include "autores.h"
#include "socios.h"
#include "prestamos.h"
#include "inputDiaz.h"

int hardCodePrestamos (ePrestamo lista[],int tam, int cant)
{
    int cont=0;
    ePrestamo ejemplo[]=
    {
        {1000,4,100,{27,6,2016},0},
        {1001,5,104,{5,7,2014},0},
        {1002,7,101,{8,15,2018},0},
        {1003,10,100,{6,6,2015},0},
        {1004,4,105,{12,5,2013}, 0},
        {1005,5,107,{22,15,2019}, 0},
        {1006,2,109,{26,17,2018},0},
        {1007,6,106,{11,26,2010}, 0},
        {1008,4,104,{20,7,2016}, 0},
        {1009,7,103,{2,10,2013},0}
    };

    if(cant <= tam && cant >=10)
    {
        for(int i=0; i <tam; i++)
        {
            lista[i] = ejemplo[i];
            cont++;
        }
    }

    return cont;
}

void iniciarlizarPrestamos(ePrestamo vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

int buscarLibrePrestamo(ePrestamo vec[],int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice =i;
            break;
        }
    }

    return indice;
}

void mostrarPrestamo(ePrestamo vec, eSocio socio[],int tamS, eLibro libro[],int tamL)
{
    char nomLibro[31];
    char nomSocio[51];

    obtenerNomLibro(libro,tamL,vec.idLibro,nomLibro);
    obtenerNomSocio(socio,tamS,vec.idSocio,nomSocio);

    printf(" %d  %30s  %30s\n",vec.id,nomLibro,nomSocio);
}

void mostrarPrestamos(ePrestamo vec[], int tam, eSocio socio[],int tamS, eLibro libro[],int tamL)
{
    int cont=0;

    system("cls");
    printf("  ID                    LIBRO                           SOCIO\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarPrestamo(vec[i],socio,tamS,libro,tamL);
            cont++;
        }
    }

    if(cont==0)
    {
        printf("\nNo hay prestamos para mostrar\n\n");
    }
}

int altaPrestamo(ePrestamo vec[], int tam, eSocio socio[],int tamS, eLibro libro[],int tamL,eAutores autores[], int tamA, int id)
{
    int indice;
    int idLibro;
    int indiceLibro;
    int idSocio;
    int indiceSocio;
    int todoOk=0;

    system("cls");
    printf("*** MENU ALTA PRESTAMO ***\n\n");

    indice=buscarLibrePrestamo(vec,tam);

    if(indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        system("cls");
        vec[indice].id=id;

        mostrarLibros(libro,tamL,autores,tamA);
        getIntRange(&idLibro,1,20,"Ingrese codigo del libro: ");
        indiceLibro=buscarLibroId(libro,tamL,idLibro);

        while(indiceLibro==-1)
        {
            getIntRange(&idLibro,1,10,"Ingrese codigo del libro valido: ");
            indiceLibro=buscarLibroId(libro,tamL,idLibro);
        }

        vec[indice].idLibro=idLibro;

        ////
        mostrarSocios(socio,tamS);
        getIntRange(&idSocio,100,400,"Ingrese numero de socio: ");
        indiceSocio=buscarSocioId(socio,tamS,idSocio);

        while(indiceSocio==-1)
        {
            getIntRange(&idSocio,100,400,"Ingrese numero de socio valido: ");
            indiceSocio=buscarSocioId(socio,tamS,idSocio);
        }

        vec[indice].idSocio=idSocio;

        getIntRange(&vec[indice].prestamos.dia,1,31,"Ingrese dia de prestamo: ");
        getIntRange(&vec[indice].prestamos.mes,1,12,"Ingrese mes de prestamo: ");
        getIntRange(&vec[indice].prestamos.anio,2019,2020,"Ingrese anio de prestamo: ");

        vec[indice].isEmpty=0;
        todoOk=1;
        printf("\nPrestamo dado de alta con exito\n\n");

    }

    return todoOk;
}


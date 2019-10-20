#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputDiaz.h"
#include "categoria.h"
#include "juego.h"
#include "clientes.h"
#include "alquileres.h"

int harcodearAlquileres(eAlquiler vec[], int tam, int cant)
{
    int cont=0;
    eAlquiler alquileres[]=
    {
        {10000,100,1001,{12,5,2019},0},
        {10001,103,1002,{35,6,2019},0},
        {10002,100,1003,{22,12,2019},0},
        {10003,101,1001,{6,8,2019},0},
        {10004,102,1001,{9,4,2019},0},
        {10005,103,1003,{16,10,2019},0}

    };

   if(cant<= tam && cant<=6)
   {
       for(int i=0; i<tam; i++)
        {
        vec[i]=alquileres[i];
        cont++;
        }
   }

    return cont;
}

void inicializarAlquiler(eAlquiler vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

int buscarLibreAlquiler(eAlquiler vec[],int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void mostrarAlquiler(eAlquiler vec, eJuego juego[], int tamJ, eCliente cliente[], int tamC)
{
    char nomjuego[21];
    char nomCliente[51];

    obtenerNomJuego(juego,tamJ,vec.idJuego,nomjuego);
    obtenerNomCliente(cliente,tamC,vec.idCliente,nomCliente);

    printf(" %d  %10s  %20s       %02d/%02d/%d\n",vec.idAl,nomjuego,nomCliente,
           vec.alquiler.dia,vec.alquiler.mes,vec.alquiler.anio);
}

void mostrarAlquileres(eAlquiler vec[], int tam, eJuego juego[], int tamJ, eCliente cliente[], int tamC)
{
    int cont=0;

    system("cls");
    printf("  ID         JUEGO               CLIENTE           FECHA_ALQUILER\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarAlquiler(vec[i],juego,tamJ,cliente,tamC);
            cont++;
        }
    }

    if(cont==0)
    {
        printf("\nNo hay alquileres en el sistema\n\n");
    }
}

int altaAlquiler(eAlquiler vec[], int tam, eJuego juego[], int tamJ, eCliente cliente[], int tamC,eCategoria cat[], int tCat, int id)
{
    int todoOk=0;
    int indice;

    system("cls");
    printf("  *** MENU ALTA ALQUILER ***  \n\n");

    indice=buscarLibreAlquiler(vec,tam);

    if(indice==-1)
    {
        printf("\nNo hay espacio disponible\n\n");
    }
    else
    {
        vec[indice].idAl=id;

        mostrarJuegos(juego,tamJ,cat,tCat);
        getIntRange(&vec[indice].idJuego,100,103,"\nIngrese codigo de juego: ");

        mostrarClientes(cliente,tamC);
        getIntRange(&vec[indice].idCliente,1000,9999,"\nIngrese id del cliente: ");


        getIntRange(&vec[indice].alquiler.dia,1,31,"Ingrese dia de alquiler: ");
        getIntRange(&vec[indice].alquiler.mes,1,12,"Ingrese mes de alquiler: ");
        getIntRange(&vec[indice].alquiler.anio,1990,2019,"Ingrese anio de alquiler: ");

        vec[indice].isEmpty=0;
        todoOk=1;
        printf("\nAlta realizada con exito\n\n");
    }

    return todoOk;
}


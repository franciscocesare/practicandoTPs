#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sectores.h"

void harcodearSectores(eSector vec[],int tam)
{
    eSector lista[]=
    {
     {1,"RRHH"},
     {2,"Ventas"},
     {3,"Compras"},
     {4,"Sistemas"},
     {5,"Legales"},
    };

    for(int i=0; i<tam; i++)
    {
        vec[i]=lista[i];
    }
}

void mostrarSector(eSector vec)
{
    printf("%2d   %10s\n",vec.id,vec.descripcion);
}

void mostrarSectores(eSector vec[],int tam)
{
    system("cls");
    printf(" ID      SECTOR\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarSector(vec[i]);
    }
}

void obtenerNomSec(eSector vec[], int tam, int id, char dondeAsignar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].id == id)
        {
            strcpy(dondeAsignar,vec[i].descripcion);
        }
    }
}

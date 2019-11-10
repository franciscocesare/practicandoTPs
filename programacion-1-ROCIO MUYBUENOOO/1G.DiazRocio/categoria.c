#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "categoria.h"

void harcodearCategoria(eCategoria vec[], int tam)
{
    eCategoria lista[]=
    {
        {1,"Mesa"},
        {2,"Azar"},
        {3,"Estrategia"},
        {4,"Salon"},
        {5,"Magia"}

    };

    for(int i=0 ;i<tam; i++)
    {
        vec[i] = lista[i];
    }
}

void mostrarCategoria(eCategoria vec)
{
    printf(" %d    %10s\n",vec.id,vec.descripcion);
}

void mostrarCategorias(eCategoria vec[], int tam)
{
    system("cls");
    printf(" ID    CATEGORIA\n\n");

    for(int i=0 ;i<tam; i++)
    {
        mostrarCategoria(vec[i]);
    }
}

void obtenerNomCat(eCategoria vec[], int tam, int id, char dondeAsignar[])
{
    for(int i=0 ;i<tam; i++)
    {
        if(vec[i].id == id)
        {
            strcpy(dondeAsignar,vec[i].descripcion);
        }
    }
}



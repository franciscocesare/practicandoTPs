#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "generosActores.h"
#include "peliculas.h"

void mostrarActor(eActores vec)
{
    printf("  %d  %20s   %10s\n",vec.idActor,vec.nombreActor,vec.paisActor);
}

void mostrarActores(eActores vec[], int tam)
{
    system("cls");
    printf("  ID          NOMBRE              PAIS\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarActor(vec[i]);
    }
}

void nombreActor(eActores vec[], int tam,int id,char* dondeAsignar)
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].idActor == id)
        {
            strcpy(dondeAsignar,vec[i].nombreActor);
        }
    }
}

int validarActor(eActores vec[],int tam)
{
    int opcion;

    system("cls");
    mostrarActores(vec,tam);
    printf("\nIngrese numero de actor: ");
    scanf("%d",&opcion);

    while(opcion < 1 || opcion >5)
    {
        printf("\nIngrese numero de actor valido: ");
        scanf("%d",&opcion);
    }

    return opcion;
}

void mostrarGenero(eGenero vec)
{
    printf("%d  %10s\n",vec.idGenero,vec.nombreGenero);
}

void mostrarGeneros(eGenero vec[], int tam)
{
    system("cls");
    printf(" ID      GENERO\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarGenero(vec[i]);
    }
}

int validarGenero(eGenero vec[], int tam)
{
    int opcion;

    system("cls");
    mostrarGeneros(vec,tam);
    printf("Ingrese numero de genero: ");
    scanf("%d",&opcion);

    while(opcion < 100 || opcion > 103)
    {
        printf("Ingrese numero de genero valido: ");
        scanf("%d",&opcion);
    }

    return opcion;
}

void nombreGenero(eGenero vec[], int tam,int id,char* dondeAsignar)
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].idGenero == id)
        {
            strcpy(dondeAsignar,vec[i].nombreGenero);
        }
    }
}

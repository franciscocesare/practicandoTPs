#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "entidad_1.h"
#include "entidad_2.h"
#include "entidad_3.h"

///VOID SI NO TIENE CAMPO IS EMPTY, SINO ES LA DE INT
void hardcodearGeneros(eGenero vec[], int tam)
{

    eGenero generos[]= ///POR EJEM eVuelos vuelos[]=
    {
        ///ACA RESPETAR EL ORDEN DE LOS DATOS A HARDCODEAR
        {100,"ACCION"},
        {101,"COMEDIA"},
        {102,"TERROR"},
        {103,"DRAMA"},

    };

    for(int i=0; i<tam; i++)
    {
        vec[i]=generos[i];
    }
}



void hardcodearActores(eActores vec[], int tam)
{

    eActores actores[]= ///POR EJEM eVuelos vuelos[]=
    {
        ///ACA RESPETAR EL ORDEN DE LOS DATOS A HARDCODEAR
        {1,"JULIA ROBERTS", "EEUU"},
        {2,"ROBERT DENIRO", "EEUU"},
        {3,"RICARDO DARIN","ARGENTINA"},
        {4,"TITA MERELO","ARGENTINA"},
        {5,"SANDRO","ARGENTINA"},

    };

    for(int i=0; i<tam; i++)
    {
        vec[i]=actores[i];
    }
}

//////////////////////////////////


void mostrarGenero(eGenero genero) ///NOMOBRE DE LA ESTRUCTURA Y DE UN DATO. si van mas estruct voy a tener que obtener los datos de cada una
{

    printf("%d     %10s  \n",
           genero.idGenero,
           genero.nombreGenero);
}

void mostrarActor(eActores actor) ///NOMOBRE DE LA ESTRUCTURA Y DE UN DATO. si van mas estruct voy a tener que obtener los datos de cada una
{

    printf("%d     %10s  %10s\n",
           actor.idActor,
           actor.nombreActor,
           actor.paisActor);
}

/// PARA OBTENER EL DATO QUE VOY A USAR EN MOSTRAR SI SE VINCULAN ESTRUCTURAS

void obtenerNombreActor(eActores vec[], int tam, int id, char dondeAsigar[])
{
    for(int i=0; i<tam; i++) ///RECORRO EL VEC QUE QUIERO OBTNER DATO
    {
        if(vec[i].idActor == id) ///SI EL ID COINCIDE, CARGO EL DATO EN LA VAR DONDE ASGINAR
        {
            strcpy(dondeAsigar,vec[i].nombreActor);
            ///strcat(dondeAsigar,", ");
            ///strcat(dondeAsigar,vec[i].nombre);
        }
    }
}

void obtenerGenero(eGenero vec[], int tam, int id, char dondeAsigar[])
{
    for(int i=0; i<tam; i++) ///RECORRO EL VEC QUE QUIERO OBTNER DATO
    {
        if(vec[i].idGenero == id) ///SI EL ID COINCIDE, CARGO EL DATO EN LA VAR DONDE ASGINAR
        {
            strcpy(dondeAsigar,vec[i].nombreGenero);
            ///strcat(dondeAsigar,", ");
            ///strcat(dondeAsigar,vec[i].nombre);
        }
    }
}



void mostrarGeneros(eGenero vec[], int tam)
{
    int flag = 0;
    system("cls");

    printf("iD genero   GENERO\n");

    for(int i=0; i < tam; i++)
    {
        mostrarGenero(vec[i]);
        flag = 1;
    }

    if( flag == 0)
    {
        printf("\nNo hay GENEROS que mostrar\n");
    }

    printf("\n\n");
}

void mostrarActores(eActores vec[], int tam)
{
    int flag = 0;
    system("cls");

    printf("iD NOMBRE      PAIS\n");

    for(int i=0; i < tam; i++)
    {
        mostrarActor(vec[i]);
        flag = 1;
    }

    if( flag == 0)
    {
        printf("\nNo hay ACTORES que mostrar\n");
    }

    printf("\n\n");
}


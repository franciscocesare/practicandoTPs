#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "autores.h"
#include "inputDiaz.h"


int hardCodeAutores(eAutores lista[],int tam, int cant)
{
    int cont=0;

    eAutores ejemplos[]=
    {
        {1, "Miguel","De Cervantes"},
        {2, "J.R.R","Tolkien"},
        {3, "Antoine","De Saint Exupery"},
        {4, "George","Orwell"},
        {5, "Fiodor","Dostoievski"},
        {6, "Dante","Alighieri"},
        {7, "Gabriel","Garcia Marquez"},
        {8, "Homero"," "},
        {9, "William","Shakespeare"},
        {10,"Mark","Twain"},
    };

    if(cant <= tam && cant >=10)
    {
        for(int i=0; i <tam; i++)
        {
            lista[i] = ejemplos[i];
            cont++;
        }
    }

    return cont;
}

int buscarAutorId(eAutores vec[], int tam, int id)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id == id)
        {
            indice =i;
            break;
        }
    }

    return indice;
}

void mostrarAutor(eAutores vec)
{
    printf(" %02d   %15s   %20s\n",vec.id,vec.apellido,vec.nombre);
}

void mostrarAutores(eAutores vec[], int tam)
{
    int cont=0;

    system("cls");
    printf(" ID         APELLIDO           NOMBRE\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarAutor(vec[i]);
        cont++;
    }

    if(cont == 0)
    {
        printf("\nNo hay autores para mostrar\n\n");
    }
}

void ordenarActores(eAutores vec[], int tam)
{
    eAutores aux;

    for(int i=0; i<tam-1;i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmpi(vec[i].apellido,vec[j].apellido) > 0)
            {

                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
             else
            {
                if(strcmpi(vec[i].apellido,vec[j].apellido)==0 && strcmpi(vec[i].nombre,vec[j].nombre)>0)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;

                }

            }
        }
    }
}

void obtenerNomAutor(eAutores vec[], int tam, int idAutor,char dondeAsigar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].id == idAutor)
        {
            strcpy(dondeAsigar,vec[i].apellido);
            strcat(dondeAsigar,", ");
            strcat(dondeAsigar,vec[i].nombre);
        }
    }

}


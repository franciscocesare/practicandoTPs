#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "libros.h"
#include "autores.h"
#include "inputDiaz.h"


int hardCodeLibros(eLibro lista[],int tam, int cant)
{
    int cont=0;
    eLibro ejemplos[]=
    {
        {1, "Huckleberry Finn", 10},
        {2, "Hamlet", 9},
        {3, "La Iliada", 8},
        {4, "Cien Anyos de Soledad",7},
        {5, "La divina comedia",6},
        {6, "Crimen y Castigo",5},
        {7, "1984",4},
        {8, "El Senyor de los Anillos", 2},
        {9, "Don Quijote de la Mancha", 1},
        {10, "El Principito", 3}
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


int buscarLibroId(eLibro vec[], int tam, int id)
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

void mostrarLibro(eLibro vec, eAutores autor[],int tam)
{
    char nombre[60];

    obtenerNomAutor(autor,tam,vec.idAutor,nombre);

    printf(" %02d   %30s   %30s\n",vec.id,vec.titulo,nombre);
}

void mostrarLibros(eLibro vec[], int tam, eAutores autores[],int tAutor)
{
    int cont=0;

    system("cls");
    printf(" ID                       TITULO                        AUTOR\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarLibro(vec[i],autores,tAutor);
        cont++;
    }

    if(cont == 0)
    {
        printf("\nNo hay libros para mostrar\n\n");
    }
}

void ordenarLibros(eLibro vec[], int tam)
{
    eLibro aux;

    for(int i=0; i<tam-1;i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmpi(vec[i].titulo,vec[j].titulo) > 0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }
}

void obtenerNomLibro(eLibro vec[],int tam,int id, char dondeAsignar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].id == id)
        {
            strcpy(dondeAsignar,vec[i].titulo);
        }
    }

}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "categoria.h"
#include "juego.h"


void harcodearJuego(eJuego vec[], int tam)
{
    eJuego lista[]=
    {
        {100,"Monopoly",500,1},
        {101,"Jenga",300,3},
        {102,"Dados",200,2},
        {103,"Uno",250,1},

    };

    for(int i=0; i<tam; i++)
    {
        vec[i]=lista[i];
    }
}

void mostrarJuego(eJuego juego, eCategoria cat[], int tam)
{
   char nombre[21];

   obtenerNomCat(cat, tam, juego.idCategoria,nombre);

   printf("%d    %10s    %.2f    %10s\n",juego.codigo,juego.descripcion,
          juego.importe,nombre);
}

void mostrarJuegos(eJuego juego[],int tamJ, eCategoria cat[], int tamC){

    system("cls");
    printf(" ID    DESCRIPCION     IMPORTE     CATEGORIA\n\n");

    for(int i=0 ;i<tamJ; i++)
    {
        mostrarJuego(juego[i],cat,tamC);
    }
}

void obtenerNomJuego(eJuego vec[], int tam, int id, char dondeAsignar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].codigo == id)
        {
            strcpy(dondeAsignar,vec[i].descripcion);
        }
    }
}

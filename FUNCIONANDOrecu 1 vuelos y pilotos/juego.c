#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "categoria.h"
#include "juego.h"


void harcodearDestino(eDestino vecDes[], int tamD)
{
    eDestino destinos[]=
    {
        {1,"Cancun",5000},
        {2,"Miami",3000},
        {3,"Rio",2000},
        {4,"Dominicana",6000},
        {5,"Cuba",10000},

    };

    for(int i=0; i<tamD; i++)
    {
        vecDes[i]=destinos[i];
    }
}

///void mostrarJuego(eJuego juego, eCategoria cat[], int tam)
void mostrarDestino (eDestino destino)
{


  printf("%d    %10s       %.2f    \n", destino.iDdestino, destino.descripcion, destino.importe);
  /* printf("%d    %10s       %.2f    %10s\n",juego.codigo,juego.descripcion,
          juego.importe,nombre);*/
}

void mostrarDestinos(eDestino destino[],int tamD){

  ///  system("cls");
    printf("**** DESTINOS ****\n\n");
    printf(" ID    DESTINO          IMPORTE\n\n");

    for(int i=0 ;i<tamD; i++)
    {
        mostrarDestino(destino[i]);
    }
}

///void obtenerNomJuego(eJuego vec[], int tam, int id, char dondeAsignar[])
void obtenerNomDestino(eDestino vecDes [], int tamD, int id, char dondeAsignar[])
{
    for(int i=0; i<tamD; i++)
    {
        if(vecDes[i].iDdestino == id)
        {
            strcpy(dondeAsignar,vecDes[i].descripcion);
        }
    }
}

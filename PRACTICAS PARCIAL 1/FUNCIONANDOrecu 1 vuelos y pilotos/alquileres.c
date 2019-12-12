#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputDiaz.h"
#include "categoria.h"
#include "juego.h"
#include "clientes.h"
#include "alquileres.h"

int harcodearVuelos(eVuelo vecVue[], int tamVue, int cant)///tiene que tener de estado CHAR
{
    int cont=0;
    eVuelo Vuelos[]=
    {
        {1000,1,100,14,19,"activo",0},
        {1001,3,102,12,15,"suspendido",0},
        {1002,2,103,13,23,"cancelado",0},
        {1003,4,103,15,22,"activo",0},
        {1004,4,104,05,10,"demorado",0},
        {1005,4,104,10,19,"suspendido",0},
        {1006,3,102,16,19,"activo",0},
        {1007,2,103,13,15,"activo",1},
        {1008,1,105,14,17,"activo",1},

    };

    if(cant<= tamVue && cant<=9)
    {
        for(int i=0; i<tamVue; i++)
        {
            vecVue[i]=Vuelos[i];
            cont++;
        }
    }

    return cont;
}

void inicializarVuelos(eVuelo vecVue[], int tamVue)
{
    for(int i=0; i<tamVue; i++)
    {
        vecVue[i].isEmptyVuelos=1;
    }
}

int buscarLibreVue(eVuelo vecVue[],int tamVue)
{
    int indice=-1;

    for(int i=0; i<tamVue; i++)
    {
        if(vecVue[i].isEmptyVuelos==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

///void mostrarAlquiler(eAlquiler vec, eJuego juego[], int tamJ, eCliente cliente[], int tamC)
void mostrarVuelo(eVuelo vecVue, eDestino destino[], int tamD, ePiloto piloto[], int tamPil)
{
    char nomDestino[30];
    char nomPiloto[51];

    obtenerNomPiloto(piloto, tamPil,vecVue.idPiloto, nomPiloto);
    obtenerNomDestino(destino, tamD, vecVue.idDestino, nomDestino);

    printf(" %2d  %17s  %10s  %4d   %4d   %10s  \n",vecVue.idVuelo,nomPiloto,nomDestino, vecVue.horaPartida, vecVue.horaLlegada, vecVue.estado);

}

void mostrarVuelos(eVuelo vecVue[], int tamVue, eDestino destino[], int tamD, ePiloto piloto[], int tamPil)
{
    int cont=0;

    ///system("cls");
    printf("  ID         PILOTO        DESTINO   PARTIDA / LLEGADA ESTADO\n\n");

    for(int i=0; i<tamVue; i++)
    {
        if(vecVue[i].isEmptyVuelos==0)
        {
            mostrarVuelo(vecVue[i], destino, tamD, piloto, tamPil);
            cont++;
        }
    }


}
///para dar de alta un vuelo


int altaVuelo(eVuelo vuelo[], int tamV,ePiloto piloto[], int tamPil, eDestino destino[], int tamD, int idVuelo)///agregar la estructura piltos para ver los Id
{


    int todoOk = 0;
    int index;
    //int idVuelo;
    int idDestino;
    int idPiloto;
    int partida;
    int llegada;
    char estado[30];

    system("cls");

    printf("*****ALTA DE UN VUELO*****\n\n");

    index = buscarLibreVue(vuelo, tamV); ///a ver si hay lugar libre, lo guarda en index 1 si hay, -1 sino
    ///printf("%d",index);

    if( index == -1)
    {
        printf("\nEl Sistema Esta Completo\n\n");
        system("pause");
    }
    else
    {
        vuelo[index].idVuelo = idVuelo;

        mostrarPilotos(piloto, tamPil);
        getIntRange(&idPiloto,100, 104, "\nIngrese el Id del Piloto: \n");

        mostrarDestinos(destino, tamD);
       getIntRange(&idDestino, 1, 5, "Ingrese el Id del destino: \n");

        getIntRange(&partida,00,24, "\nIngrese el horario de partida \n");
        getIntRange(&llegada,00,24, "\nIngrese el horario de llegada \n");

        getStringAlpha(30, "\nIngrese el estado del vuelo: \n", estado);
        strlwr(estado);

        vuelo[index] = newVuelo(idVuelo,idDestino,idPiloto,partida,llegada, estado);

        todoOk = 1;
        printf("\nSe ha realizado el alta del vuelo\n\n");
        system("pause");

    }

    return todoOk;
}

eVuelo newVuelo(

    int idVuelo,
    int idDestino,
    int idPiloto,
    int partida,
    int llegada,
    char estado[])

{
    eVuelo vuelo;
    vuelo.idVuelo= idVuelo;
    vuelo.idDestino=idDestino;
    vuelo.idPiloto=idPiloto;
    vuelo.horaPartida= partida;
    vuelo.horaLlegada=llegada;
    strcpy(vuelo.estado ,estado);
    vuelo.isEmptyVuelos = 0;

    return vuelo;
}
///PARA PODER DAR EL ALTA


void bajaVuelo(eVuelo vecVue[], int tamVue, eDestino vecDest [], int tamD, ePiloto pil [], int tamPil)
{
    int confirma;
    int indice;
    int id;

    // mostrarClientes(vec,tam);
    mostrarVuelos(vecVue, tamVue, vecDest, tamD, pil, tamPil);

    getIntRange(&id,1000,1100,"Ingrese id del vuelo: ");

    //indice=buscarClienteId(vec,tam,id);
    indice=buscarVueloPorId(id, vecVue, tamVue);

    if(indice==-1)
    {
        getIntRange(&id,1000,1100,"Ingrese id de vuelo valido: ");

        indice=buscarVueloPorId(id, vecVue, tamVue);

        printf("\nEl id ingresado es incorrecto\n\n");
    }
    if(indice !=-1)
    {
        mostrarVuelo(vecVue[indice], vecDest, tamD, pil, tamPil);
        confirma=confimarSalir("\n\nDar de baja el Vuelo? s/n: ");

        if(confirma==1)
        {
            vecVue[indice].isEmptyVuelos=1;
            printf("\nOperacion realizada\n\n");
        }
        else
        {
            printf("\nOperacion cancelada\n\n");
        }
    }

}


int buscarVueloPorId(int idVuelo, eVuelo vecVue[], int tamVue)
{
    int index = -1;

    for(int i=0; i < tamVue; i++)
    {
        if( vecVue[i].idVuelo == idVuelo && vecVue[i].isEmptyVuelos == 0)
        {
            index = i;
            break;
        }

    }
    return index;
}

int modificarVuelo(eVuelo vec[], int tam, eDestino dest[], int tamD, ePiloto pil[], int tamP)
{
    int indice;
    int todoOk=0;
    int id;

    //mostrarClientes(vec,tam);
    mostrarVuelos(vec, tam, dest,tamD, pil, tamP);

    getIntRange(&id,1000,1100,"Ingrese id del vuelo: ");

    indice=buscarVueloPorId(id, vec, tam);

    while(indice==-1)
    {
        getIntRange(&id,1000,1100,"Ingrese id de vuelo valido: ");

        indice=buscarVueloPorId(id, vec, tam);
    }
    if(indice !=-1)
    {
        getStringAlpha(51,"Ingrese el nuevo estado: ",vec[indice].estado);
    }
    return todoOk=1;
}



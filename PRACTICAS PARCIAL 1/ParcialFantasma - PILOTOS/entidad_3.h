#ifndef ENTIDAD_3_H_INCLUDED
#define ENTIDAD_3_H_INCLUDED

typedef struct
{
    int idVuelo;
    int idDestino;
    int idPiloto;
    int horaPartida;
    int horaLlegada;
    char estado[51];      ///vhardcodear ACTIVO, SUSPENDIDO, DEMORADO, CANCELADO ES EL ESTADO
    int isEmptyVuelos;

}eVuelo;

#endif // ENTIDAD_3_H_INCLUDED
#include "entidad_1.h"

int harcodearVuelos(eVuelo vecVue[], int tamVue, int cant);

void inicializarVuelos(eVuelo vecVue[], int tamVue);

int buscarLibreVue(eVuelo vecVue[],int tamVue);  ///xq para dar el alta necesito saber una pos libre

void mostrarVuelo(eVuelo vecVue, eDestino destino[], int tamD, ePiloto piloto[], int tamPil);
///EN EL CASO DEL MOSTRAR UNO, DE LO QUE TIENE ALTA, INFLUYEN MAS DE UN ARRAY

void mostrarVuelos(eVuelo vecVue[], int tamVue, eDestino destino[], int tamD,ePiloto piloto[], int tamPil);

int altaVuelo(eVuelo vuelo[], int tamV,ePiloto piloto[], int tamPil, eDestino destino[], int tamD, int idVuelo);
///EL ALTA LLEVA LOS ARRAYS DE CADA ESTRUC QUE ESTA INVOLUCRADA IGUAL QUE EL MOSTRAR TODOS

eVuelo newVuelo(int idVuelo,int idDestino,int idPiloto,int partida,int llegada, char estado[]);
///LELVA LOS PARAMETROS QUE TIENE LA ESTRUCTURA.

void bajaVuelo(eVuelo vecVue[], int tamVue, eDestino vecDest [], int tamD, ePiloto pil [], int tamPil);

int buscarVueloPorId(int idVuelo, eVuelo vecVue[], int tamVue);

int modificarVuelo(eVuelo vec[], int tam, eDestino dest[], int tamD, ePiloto pil[], int tamP);



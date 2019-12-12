#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "entidad_1.h"
#include "entidad_2.h"
#include "entidad_3.h"
#include "informes.h"

int menuInformes()
{
    int opcion;

    system("cls");
    printf("  ***  MENU DE INFORMES ***   \n\n");
    printf("1. Todos los Vuelos de un Piloto Seleccionado\n");
    printf("2. Todos los pilotos que volaron a un destino especifico\n");
    printf("3. Recaudacion por cada Piloto\n");
    printf("4. Destino mas elegido\n");
    printf("5. Atras\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}



void vuelosPilotoSeleccionado(eVuelo vuelos[], int tamVue, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDest)
{
    int flag=0;

    int idPiloto;

    mostrarPilotos(pilotos, tamPil);

    getIntRange(&idPiloto,100,110, "INGRESE EL ID PILOTO PARA VER SUS VUELOS\n");
    system("cls");
    printf("\n\nELIGIO: %d \n\n ", idPiloto);

    for (int i=0; i<tamVue; i++)
    {
        if (vuelos[i].idPiloto==idPiloto && vuelos[i].isEmptyVuelos==0)

        {
            printf("\n  ID         PILOTO        DESTINO   PARTIDA / LLEGADA ESTADO\n\n");
            mostrarVuelo(vuelos[i], destinos, tamDest, pilotos, tamPil);
            flag=1;
        }

    }
    if(flag==0)
    {

        printf("NO HAY VUELOS DE ESE PILOTO");
    }


}

//Todos los pilotos que volaron a un destino especifico
void pilotosDestinoSeleccionado(eVuelo vuelos[], int tamVue, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDest)
{
    system("cls");

    int idDestino;
    int idPiloto;
    int flag=0;

    mostrarDestinos(destinos, tamDest);
    getIntRange(&idDestino, 1, 100, "INGRESE EL ID DEL DESTINO PARA VER LOS PILOTOS QUE VOLARON");


    for (int i=0; i<tamVue; i++)
    {
        idPiloto=vuelos[i].idPiloto;
        for (int j=0; j<tamPil; j++)
        {
            if(destinos[i].iDdestino==idDestino&&vuelos[i].idPiloto==pilotos[j].idPiloto)

            {
                printf(" EL PILOTO QUE VIAJO ES: \n\n");
                mostrarPiloto(pilotos[j]);
                flag=1;
            }
        }
    }

    if(flag==0)

    {

        printf("NO HAY VUELOS DE ESE PILOTO");
    }


}



///DESTINO MAS ELEGIDO DE MANU

int cantidadDestinos(int idDestino, eVuelo vuelos[], int tamVuelo){

    int contador = 0;

        for(int j=0; j<tamVuelo; j++){
            if(vuelos[j].idDestino == idDestino && vuelos[j].isEmptyVuelos == 0){
                contador++;
            }
        }

    return contador;
}


void destinoMasElegido(eDestino destinos[], int tamDes, eVuelo vuelos[], int tamVuelo){

///recibe el contador

    int cantidad[tamDes];
    int mayor=0;
    int flag=0;

    system("cls");
    printf("***** DESTINO PREFERIDO ******** \n\n");

    for(int i=0; i<tamDes; i++)
    {
        cantidad[i] = cantidadDestinos(destinos[i].iDdestino, vuelos, tamVuelo);
    }

    for(int i=0; i<tamDes; i++)
    {
            if(cantidad[i] > mayor || flag == 0){
                mayor = cantidad[i];
                flag = 1;
            }
    }

        printf("Destino preferido fue elegido %d veces. \n\n", mayor);

        for(int i=0; i<tamDes; i++)
        {
            if(cantidad[i] == mayor){

                printf("ID    MAS ELEGIDO    IMPORTE\n\n");
                mostrarDestino(destinos[i]);
            }
        }
}


/// Recaudacion por cada Piloto

void recaudacionPilotoSeleccionado(ePiloto piloto [], int tamPil, eVuelo vuelo [], int tamVue, eDestino destino [], int tamD)

{
    system("cls");

    float recauPiloto=0;
    int idPiloto;
    int flag=0;

    mostrarPilotos(piloto, tamPil);
    getIntRange(&idPiloto, 100, 199, "\n\nINGRESE EL ID DEL PILOTO PARA VER RECAUDACION: \n\n");



    for (int j=0; j<tamVue; j++)
    {
        if(vuelo[j].idPiloto == idPiloto && vuelo[j].isEmptyVuelos==0)
        {
            for(int i=0; i<tamD; i++)
            {

                if(destino[i].iDdestino==vuelo[j].idDestino)
                {
                    recauPiloto+=destino[i].importe;
                    flag ++;
                }
            }
        }

    }
    if (flag==0)

        printf("\n\nESE PILOTO NO RECAUDO\n\n");


    else

        printf("\nEL PILOTO RECAUDO: %.2f \n", recauPiloto);


}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "entidad_2.h"
#include "entidad_3.h"
#include "entidad_1.h"



void harcodearPilotos(ePiloto vecPil[], int tamPil)
{
    ePiloto Pilotos[]=
    {
        {100,"LAUTARO ACOSTA"},
        {101,"PEPE SAND"},
        {102,"MARCELINO MORENO"},
        {103,"PEPO DE LA VEGA"},
        {104,"DIEGO VALERI"},

    };

    for(int i=0; i<tamPil; i++)
    {
        vecPil[i]=Pilotos[i];
    }
}



void mostrarPiloto(ePiloto vecPil)

{
        printf(" %2d  %17s  \n",vecPil.idPiloto,vecPil.nombre);

}

void mostrarPilotos(ePiloto vecPil[], int tamPil)
{

    printf(" ID     NOMBRE     \n\n");

    for(int i=0; i<tamPil; i++)
    {
        ordenarPilotos(vecPil, tamPil);
        mostrarPiloto(vecPil[i]);

    }

}



void ordenarPilotos(ePiloto vecPil[], int tamPil)
{
    ePiloto aux;

    for(int i=0; i<tamPil-1; i++)
    {
        for(int j=i+1; j<tamPil; j++)
        {
            if(strcmpi(vecPil[i].nombre,vecPil[j].nombre)>0)
            {
                aux=vecPil[i];
                vecPil[i]=vecPil[j];
                vecPil[j]=aux;
            }
        }
    }
}



void obtenerNomPiloto(ePiloto vecPil[], int tamPil, int id, char dondeAsigar[])
{
    for(int i=0; i<tamPil; i++)
    {
        if(vecPil[i].idPiloto == id)
        {
            strcpy(dondeAsigar,vecPil[i].nombre);
        }
    }
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "entidad_1.h"
#include "entidad_2.h"
#include "entidad_3.h"

///VOID SI NO TIENE CAMPO IS EMPTY, SINO ES LA DE INT
void hardcodearDATOS(eENTIDAD_1 vecDATO[], int tam)
{

    eENTIDAD_1 DATOS[]= ///POR EJEM eVuelos vuelos[]=
    {
        ///ACA RESPETAR EL ORDEN DE LOS DATOS A HARDCODEAR
        {100,"LAUTARO ACOSTA"},
        {101,"PEPE SAND"},
        {102,"MARCELINO MORENO"},
        {103,"PEPO DE LA VEGA"},
        {104,"DIEGO VALERI"},

    };

    for(int i=0; i<tam; i++)
    {
        vecDATO[i]=DATOS[i];
    }
}


//////////////////////////////////


void mostrarDATO(STRUCT_NAME dato) ///NOMOBRE DE LA ESTRUCTURA Y DE UN DATO. si van mas estruct voy a tener que obtener los datos de cada una
{

    ///char DATO_A_OBTENER [30]; ACA VOY A CARGAR LOS DATOS A OBTENER
    ///char DATO_A_OBTENER_2 [30];

   /// obtenerNomPiloto(piloto, tamPil,vecVue.idPiloto, nomPiloto); SI TENGO QUE OBTENER DATOS DE OTRA ESTRUCTURA
   /// obtenerNomDestino(destino, tamD, vecVue.idDestino, nomDestino); SI TENGO QUE OBTENER DATOS DE OTRA ESTRUCTURA

    printf("  %d     %s     %d  %c  %02d/%02d/%d\n",
           dato.legajo,
           dato.nombre,
           dato.edad,
           dato.sexo,
           dato.fecha.dia,
           dato.fecha.mes,
           dato.fecha.anio);
}

/// PARA OBTENER EL DATO QUE VOY A USAR EN MOSTRAR SI SE VINCULAN ESTRUCTURAS

void obtenerNomPiloto(ePiloto vecPil[], int tamPil, int id, char dondeAsigar[])
{
    for(int i=0; i<tamPil; i++) ///RECORRO EL VEC QUE QUIERO OBTNER DATO
    {
        if(vecPil[i].idPiloto == id) ///SI EL ID COINCIDE, CARGO EL DATO EN LA VAR DONDE ASGINAR
        {
            strcpy(dondeAsigar,vecPil[i].nombre);
            ///strcat(dondeAsigar,", ");
            ///strcat(dondeAsigar,vec[i].nombre);
        }
    }
}


void mostrarDatos(STRUCT_NAME vec[], int tam)
{
    int flag = 0;
    system("cls");

    printf(" Legajo Nombre Edad Sexo FIngreso\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarDato(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay alumnos que mostrar\n");
    }

    printf("\n\n");
}


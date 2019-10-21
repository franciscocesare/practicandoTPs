#include <stdio.h>
#include <stdlib.h>
#include "inputDiaz.h"
#include "empleados.h"
#include "sectores.h"
#include "menus.h"
#include "almuerzos.h"

void inicializarAlmuerzos(eAlmuerzo alm[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        alm[i].isEmpty=1;
    }
}

int buscarLibreAlm(eAlmuerzo alm[], int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(alm[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int harcodearAlmuerzos(eAlmuerzo alm[], int tam, int cant)
{
    int cont=0;

    eAlmuerzo lista[]=
    {
        {10000,11,1004,{2,7,2019},0},
        {10002,13,1000,{25,8,2019},0},
        {10003,11,1002,{6,7,2018},0},
        {10004,14,1003,{2,9,2019},0},
        {10005,12,1003,{16,0,2018},0},
        {10006,10,1002,{6,7,2018},0},
        {10007,12,1000,{15,4,2019},0},
        {10008,10,1001,{18,11,2018},0},
        {10009,13,1003,{29,4,2019},0},
        {10010,11,1001,{14,7,2018},0},
        {10011,13,1000,{31,6,2018},0},

    };

    if(cant <= tam && cant<= 11)
    {
        for(int i=0; i<cant; i++)
        {
            alm[i]=lista[i];
            cont++;
        }
    }

    return cont;
}

void mostrarAlmuerzo(eAlmuerzo alm, eMenu menu[], int tamM, eEmpleado emp[], int tamE)
{
    char nomEmp[51];
    char nomMenu[21];

    obtenerNomMenu(menu,tamM,alm.idMenu,nomMenu);
    obtenerNomEmp(emp,tamE,alm.idEmp,nomEmp);

    printf(" %d    %30s   %30s  %02d/%02d/%d\n",alm.id,nomMenu,nomEmp,
           alm.fechaAlmuerzo.dia,alm.fechaAlmuerzo.mes,alm.fechaAlmuerzo.anio);
}

void mostrarAlmuerzos(eAlmuerzo alm[],int tamA, eMenu menu[], int tamM, eEmpleado emp[], int tamE)
{
    int cont=0;

    system("cls");
    printf("  ID               MENU               NOMRE_EMP            FECHA\n\n");

    for(int i=0; i<tamA; i++)
    {
        if(alm[i].isEmpty==0)
        {
            mostrarAlmuerzo(alm[i],menu,tamM,emp,tamE);
            cont++;
        }
    }

    if(cont==0)
    {
        printf("\nNo hay datos para mostrar\n\n");
    }
}



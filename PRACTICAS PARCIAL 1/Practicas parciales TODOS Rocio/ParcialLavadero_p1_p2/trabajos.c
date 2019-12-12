#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "inputDiaz.h"
#include "autos.h"
#include "trabajos.h"
#include "inputDiaz.h"

int buscarLibreTrabajo(eTrabajo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int obtenerServicios(eServicio servicio[], int tamServ, int idServicio, char dondeAsignar[])
{
    int todoOk=-1;

    for(int i= 0 ; i<tamServ;i++)
    {
        if(idServicio == servicio[i].idServicio)
        {
            strcpy(dondeAsignar,servicio[i].nombreServicio);
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServicio)
{
    char nombreSer[25];

    obtenerServicios(servicios,tamServicio,trabajo.idServicio,nombreSer);

    printf("%02d  %10s   %8s    %02d/%02d/%d\n",trabajo.idTrabajo,trabajo.patente,nombreSer,trabajo.fechaTrabajo.dia,trabajo.fechaTrabajo.mes,trabajo.fechaTrabajo.anio);

}

void mostrarTrabajos(eTrabajo vecTrabajo[], int tamTrabajo, eServicio vecServ[], int tamServ)
{
    int cont=0;

    system("cls");
    printf("ID     PATENTE    TRABAJO      FECHA\n");
    printf("--     -------    -------      -----");
    printf("\n\n");

    for(int i=0; i<tamTrabajo; i++)
    {
        if(vecTrabajo[i].ocupado==1)
        {
            mostrarTrabajo(vecTrabajo[i], vecServ, tamServ);
            cont++;
        }
    }
    printf("\n\n");

    if(cont==0)
    {
        printf("\nNo hay trabajos para mostrar!!!\n\n");
    }
}

void mostrarServicio(eServicio vec)
{
    printf("%02d  %10s  %5d\n",vec.idServicio, vec.nombreServicio, vec.precio);
}

void mostrarServicios(eServicio vec[], int tam)
{
    int cont=0;

    system("cls");
    printf("ID      SERVICIO   PRECIO\n");
    printf("--      --------   ------");
    printf("\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarServicio(vec[i]);
        cont++;
    }
    printf("\n\n");
}

void incrementalTrabajo(eTrabajo vec[],int tam)
{
    for (int i=0; i<tam; i++)
    {
        vec[i].idTrabajo=i+1;
    }
}

int buscarServicioPorId(eServicio vec[], int tam, int idServicio)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].idServicio==idServicio)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaTrabajo(eTrabajo vecTrabajo[], int tamTrabajo, eServicio vecServ[], int tamServ, eAuto vecAuto[], int tamAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca)
{
    int indice;
    int indicePatente;
    int indiceServicio;
    int id;
    char auxChar[50];

    indice=buscarLibreTrabajo(vecTrabajo, tamTrabajo);

    if(indice != -1)
    {
        incrementalTrabajo(vecTrabajo, tamTrabajo);

        printf("\n## ID: %d\n\n",vecTrabajo[indice].idTrabajo);
        system("pause");

        //////

        mostrarAutos(vecAuto, tamAuto, vecColor, tamColor, vecMarca, tamMarca);
        validarPatente(auxChar, "Ingrese patente: ");

        while(buscarAutoPorPatente(vecAuto, tamAuto,auxChar)==-1)
        {
            printf("\nNo existe esa patente!!!\n");
            validarPatente(auxChar, "Ingrese patente: ");
        }

        indicePatente=buscarAutoPorPatente(vecAuto, tamAuto, auxChar);

        if(indicePatente != -1)
        {
            strcpy(vecTrabajo[indice].patente, auxChar);

        }
                        /////////////////

        mostrarServicios(vecServ, tamServ);
        printf("\nIngrese Id servicio: ");
        fflush(stdin);
        scanf("%d",&id);

        while(buscarServicioPorId(vecServ, tamServ, id)==-1)
        {
            printf("\nServicio no registrado!!!\n");
            printf("\nIngrese Id servicio: ");
            fflush(stdin);
            scanf("%d",&id);
        }

        indiceServicio=buscarServicioPorId(vecServ, tamServ, id);

        if(indiceServicio == -1)
        {
            vecTrabajo[indice].idServicio=id;
        }

        vecTrabajo[indice].fechaTrabajo.dia=obtenerNumeroEntre(31, 1, "## Ingrese dia: ");
        vecTrabajo[indice].fechaTrabajo.mes=obtenerNumeroEntre(12, 1, "## Ingrese mes: ");
        vecTrabajo[indice].fechaTrabajo.anio=obtenerNumeroIgualA(2019, "## Ingresar anio: ");

        vecTrabajo[indice].ocupado=1;

        printf("\nTrabajo guardado con exito!!!\n\n");
    }
    else
    {
        printf("No hay mas lugar en el sistema!!!\n\n");
        system("pause");
    }
}






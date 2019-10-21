#include "alquileres.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initAlquileres(eAlquileres listaAlq[], int tamA){

    for(int i=0; i<tamA; i++){

        listaAlq[i].isEmpty = 1;
    }

    return 0;
}




int buscarLibreAlquiler(eAlquileres listaA[], int tamA)
{

    int indice = -1;

    for (int i=0; i< tamA; i++){
        if (listaA[i].isEmpty == 1){
            indice = i;
            break;
        }
    }

return indice;
}

int altaAlquiler(eAlquileres alquileres[], int tamA, eJuego juegos[], int tamJ, eClientes clientes[], int tamC, int idAlquiler)
{
    int todoOk=0;
    int indice;
    int codJuego;
    int codCliente;
    int dia;
    int mes;
    int anio;

    indice = buscarLibreAlquiler(alquileres, tamA);

    system("cls");
    printf("***Alta de alquileres***\n");
    if(indice == -1){
        printf("\nSistema de alquileres completo.");
    }else{

        printJuegos(juegos, tamJ);
        printf("\nIngrese codigo de juego: ");
        fflush(stdin);
        scanf("%d", &codJuego);
        while(!validarCodJuego(juegos,tamJ,codJuego))
        {
            printf("\nERROR. Codigo incorrecto de juego, ingrese nuevamente: ");
            fflush(stdin);
            scanf("%d", &codJuego);
        }
        listarClientes(clientes, tamC);
        printf("\nIngrese codigo de cliente: ");
        fflush(stdin);
        scanf("%d", &codCliente);
        while(!validarCodCliente(clientes,tamC,codCliente))
        {
            printf("\nERROR. Codigo incorrecto de cliente, ingrese nuevamente: ");
            fflush(stdin);
            scanf("%d", &codCliente);
        }

        printf("\nIngrese fecha de alquiler(DD/MM/AAAA): ");
        printf("\nDia: ");
        fflush(stdin);
        scanf("%d", &dia);

        printf("\nMes: ");
        fflush(stdin);
        scanf("%d", &mes);

        printf("\nAnio: ");
        fflush(stdin);
        scanf("%d", &anio);

        todoOk=1;
    }

    if(todoOk){
        alquileres[indice].codAlquiler=idAlquiler;
        alquileres[indice].codJuego=codJuego;
        alquileres[indice].codCliente=codCliente;
        alquileres[indice].fecha.dia=dia;
        alquileres[indice].fecha.mes=mes;
        alquileres[indice].fecha.anio=anio;
        alquileres[indice].isEmpty=0;
        printf("\n\nAlta exitosa!!\n");
    }

return todoOk;
}

void listarAlquileres(eAlquileres alquileres[], int tamA)
{
    printf("Cod Alq   Juego   Cliente   Fecha de alquiler ");
    for(int i=0; i<tamA; i++)
    {
        if(alquileres[i].isEmpty==0){
            printf("\n%02d        %02d      %4d      %02d/%02d/%d ", alquileres[i].codAlquiler, alquileres[i].codJuego, alquileres[i].codCliente, alquileres[i].fecha.dia, alquileres[i].fecha.mes, alquileres[i].fecha.anio);
        }
    }
    printf("\n\n");
}



void printJuegos(eJuego juegos[], int tamJ)
{
    printf("\nCod    Descrip Importe");

    for(int i=0; i<tamJ; i++)
    {
        printf("\n%d  %10s   %5d",juegos[i].codigo, juegos[i].descripcion, juegos[i].importe );
    }
printf("\n");
}

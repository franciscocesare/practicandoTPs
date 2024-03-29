#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input.h"
#include "categorias.h"
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"
#include "informes.h"

#define TAMClientes 10
#define TAMAlquiler 10
#define TAMJuegos 6
#define TAMCategoria 5
#define TAMLocalidad 10



int menuPrincipal();

int main()
{

    int idCliente = 1000;
    int idAlquiler=1;
    char salir = 'n';

    eCliente lista [TAMClientes];
    eAlquileres alquiler [TAMAlquiler];
    eJuego juegos [TAMJuegos];
    eCategoria categorias [TAMCategoria];
    eLocalidad localidades [TAMLocalidad];

    inicializarClientes(lista, TAMClientes);
    inicializarAlquileres(alquiler, TAMAlquiler);

    idAlquiler+=hardcodearAlquileres(alquiler, TAMAlquiler, 5);
    idCliente += hardcodearClientes(lista, TAMClientes, 9);

    harcodearJuego(juegos, TAMJuegos);
    hardcodearCategoria(categorias, TAMCategoria);
    harcodearlocalidad(localidades, TAMLocalidad);


    do
    {
        switch (menuPrincipal())
        {
        case 1:

            switch( menuClientes())
            {
            case 1:
                if (altaCliente(lista, TAMClientes, idCliente, localidades, TAMLocalidad))
                {
                    idCliente ++;
                }
                mostrarClientes(lista, TAMClientes, localidades, TAMLocalidad);
                system("pause");
                break;

            case 2:

                borrarCliente(lista, TAMClientes, localidades, TAMLocalidad);
                system("pause");
                break;

            case 3:

                modificarCliente(lista, TAMClientes, localidades, TAMLocalidad);
                system("pause");
                break;

            case 4:
                ordenarCliente(lista, TAMClientes);
                mostrarClientes(lista, TAMClientes, localidades, TAMLocalidad);
                system("pause");
                break;
            case 5:
                printf("Volver al menu anterior\n");
                system("pause");
                break;

            default:
                printf("\nOpcion Invalida!\n\n");
                system("pause");
            }
            break;

        case 2:
            switch(menuAlquileres())
            {
            case 1:

                if (altaAlquiler(alquiler, TAMAlquiler, juegos, TAMJuegos, lista, TAMClientes, categorias, TAMCategoria, idAlquiler, localidades, TAMLocalidad))
                {
                    idAlquiler++;
                }

                system("pause");

                break;

            case 2:

                mostrarAlquileres(alquiler, TAMAlquiler, juegos, TAMJuegos, lista, TAMClientes);
                system("pause");
                break;
            case 3:
                printf("Volver al menu anterior\n");
                system("pause")
                ;
                break;
            }
            break;

        case 3:
            switch(menuInformes())
            {
            case 1:
                mostrarJuegosMesa(juegos, TAMJuegos, categorias, TAMCategoria);
                system("pause");

                break;

            case 2:

                mostrarAlquilerPorCliente(lista,TAMClientes,alquiler, TAMAlquiler,categorias, TAMCategoria, juegos, TAMJuegos, localidades, TAMLocalidad);
                system("pause");
                break;

            case 3:
                mostrarImporteCliente(lista, TAMClientes, alquiler, TAMAlquiler, categorias, TAMCategoria, juegos, TAMJuegos, localidades, TAMLocalidad);
                system("pause");

                break;

            case 4:
                clientesSinAlquiler(lista, TAMClientes, alquiler, TAMAlquiler, localidades, TAMLocalidad);///REVISAR!!!
                system("pause");

                break;

            case 5:
                juegosSinAlquiler(juegos, TAMJuegos, alquiler, TAMAlquiler, categorias, TAMCategoria);
                system("pause");

                break;
            case 6:
                obtenerDatosAlquilerJuego(juegos,TAMJuegos,alquiler, TAMAlquiler,categorias, TAMCategoria,lista, TAMClientes);
                system("pause");
            case 7:
                clientesDeterminadaLocalidad(lista, TAMClientes, localidades, TAMLocalidad);
                system("pause");
            case 8:
                printf("Volver al menu anterior\n");
                system("pause");
                break;
            }
            break;

        case 4:
            printf("Confirma salir?\n\n");
            fflush(stdin);
            salir = getche();

            system("pause");
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
            system("pause");

        }

    }
    while(tolower(salir == 'n'));

    return 0;

}



int menuPrincipal()
{
    int opcion;

    system("cls");
    printf("****** ALQUILERES DE JUEGOS BAUS SRL *******\n\n");
    printf("1-CLIENTES\n");
    printf("2-ALQUILERES\n");
    printf("3-INFORMES\n");
    printf("4-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}




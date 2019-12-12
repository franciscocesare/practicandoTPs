#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "entidad_1.h"
#include "entidad_2.h"
#include "entidad_3.h"
#include "entidad_4.h"
#include "informes.h"

#define TAM_ENTIDAD_1 10 ///clientes
#define TAM_ENTIDAD_2 5  ///categorias
#define TAM_ENTIDAD_3 6  ///juegos
#define TAM_ENTIDAD_4 10  ///Alquiler




int menuPrincipal();

int main()
{

    int idCliente = 1000;
    int idAlquiler=1;
    char salir = 'n';

    eCliente lista [TAM_ENTIDAD_1];
    eAlquileres alquiler [TAM_ENTIDAD_4];
    eJuego juegos [TAM_ENTIDAD_3];
    eCategoria categorias [TAM_ENTIDAD_2];

    inicializarClientes(lista, TAM_ENTIDAD_1);
    inicializarAlquileres(alquiler, TAM_ENTIDAD_4);

    idAlquiler+=hardcodearAlquileres(alquiler, TAM_ENTIDAD_4, 5);
    idCliente += hardcodearClientes(lista, TAM_ENTIDAD_1, 8);

    harcodearJuego(juegos, TAM_ENTIDAD_3);
    hardcodearCategoria(categorias, TAM_ENTIDAD_2);


    do
    {
        switch (menuPrincipal())
        {
        case 1:

            switch( menuClientes())
            {
            case 1:
                if (altaCliente(lista, TAM_ENTIDAD_1, idCliente))
                {
                    idCliente ++;
                }
                mostrarClientes(lista, TAM_ENTIDAD_1);
                system("pause");
                break;

            case 2:

                borrarCliente(lista, TAM_ENTIDAD_1);
                system("pause");
                break;

            case 3:

                modificarCliente(lista, TAM_ENTIDAD_1);
                system("pause");
                break;

            case 4:
                ordenarCliente(lista, TAM_ENTIDAD_1);
                mostrarClientes(lista, TAM_ENTIDAD_1);
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

                if (altaAlquiler(alquiler, TAM_ENTIDAD_4, juegos, TAM_ENTIDAD_3, lista, TAM_ENTIDAD_1, categorias, TAM_ENTIDAD_2, idAlquiler))
                {
                    idAlquiler++;
                }

                system("pause");

                break;

            case 2:

                mostrarAlquileres(alquiler, TAM_ENTIDAD_4, juegos, TAM_ENTIDAD_3, lista, TAM_ENTIDAD_1);
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
                mostrarJuegosMesa(juegos, TAM_ENTIDAD_3, categorias, TAM_ENTIDAD_2);
                system("pause");

                break;

            case 2:

                mostrarAlquilerPorCliente(lista,TAM_ENTIDAD_1,alquiler, TAM_ENTIDAD_4,categorias, TAM_ENTIDAD_2, juegos, TAM_ENTIDAD_3);
                system("pause");
                break;

            case 3:
                mostrarImporteCliente(lista, TAM_ENTIDAD_1, alquiler, TAM_ENTIDAD_4, categorias, TAM_ENTIDAD_2, juegos, TAM_ENTIDAD_3);
                system("pause");

                break;

            case 4:
                clientesSinAlquiler(lista, TAM_ENTIDAD_1, alquiler, TAM_ENTIDAD_4);///REVISAR!!!
                system("pause");

                break;

            case 5:
                juegosSinAlquiler(juegos, TAM_ENTIDAD_3, alquiler, TAM_ENTIDAD_4, categorias, TAM_ENTIDAD_2);
                system("pause");


                break;
            case 6:
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


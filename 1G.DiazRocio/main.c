#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "categoria.h"
#include "juego.h"
#include "clientes.h"
#include "alquileres.h"
#include "informes.h"

#define TAMC 6
#define TAMJ 4
#define TAMCAT 5
#define TAMA 6

int menuOpciones();

int main()
{
    int salir;
    int atrasInf;
    int idCliente=1000;
    int idAlquier=10000;

    eJuego juegos[TAMJ];
    eCategoria cat[TAMCAT];
    eCliente clientes[TAMC];
    eAlquiler alquiler[TAMA];

    inicializarClientes(clientes,TAMC);
    inicializarAlquiler(alquiler,TAMA);

    harcodearCategoria(cat,TAMCAT);
    harcodearJuego(juegos,TAMJ);
    idCliente=idCliente+harcodearClientes(clientes,TAMC,6);
    idAlquier=idAlquier+harcodearAlquileres(alquiler,TAMA,6);


    do
    {
        switch(menuOpciones())
        {
        case 1:
            if(altaCliente(clientes,TAMC,idCliente))
            {
                idCliente++;
            }
            break;

        case 2:
            modificarCliente(clientes,TAMC);
            break;

        case 3:
            bajaCliente(clientes,TAMC);
            break;

        case 4:
            ordenarCliente(clientes,TAMC);
            mostrarClientes(clientes,TAMC);
            break;

        case 5:
            if(altaAlquiler(alquiler,TAMA,juegos,TAMJ,clientes,TAMC,cat,TAMCAT,idAlquier))
            {
                idAlquier++;
            }
            break;

        case 6:
            mostrarAlquileres(alquiler,TAMA,juegos,TAMJ,clientes,TAMC);
            break;

        case 7:
            do
            {
                switch(menuInformes())
                {
                case 1 :
                    mostrarJuegosMesa(juegos,TAMJ,cat,TAMCAT);
                    break;

                case 2 :
                    mostrarAlquilerPorCliente(clientes,TAMC,alquiler,TAMA,cat,TAMCAT,juegos,TAMJ);
                    break;

                case 3 :
                    mostrarImporteCliente(clientes,TAMC,alquiler,TAMA,cat,TAMCAT,juegos,TAMJ);
                    break;

                case 4 :
                    clientesSinAlquiler(clientes,TAMC,alquiler,TAMA);
                    break;

                case 5 :
                    juegosSinAlquiler(juegos,TAMJ,alquiler,TAMA,cat,TAMCAT);
                    break;

                case 6 :
                    atrasInf=confimarSalir("\nVolver atras? s/n: ");
                    break;

                }
                printf("\n\n");
                system("pause");

            }while(atrasInf !=1);
        break;

        case 8:
            salir=confimarSalir("\nDesea salir? s/n: ");
            break;

        default:
            printf("Ingrese opcion correcta\n");
        }

        printf("\n\n");
        system("pause");

    }
    while(salir != 1);

    return 0;
}

int menuOpciones()
{
    int opcion;

    system("cls");
    printf("  ***  MENU DE OPCIONES ***   \n\n");
    printf("1. Alta cliente\n");
    printf("2. Modificar cliente\n");
    printf("3. Baja cliente\n");
    printf("4. Listar clientes\n");
    printf("5. Alta alquileres\n");
    printf("6. Listar alquileres\n");
    printf("7. Informes\n");
    printf("8. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}




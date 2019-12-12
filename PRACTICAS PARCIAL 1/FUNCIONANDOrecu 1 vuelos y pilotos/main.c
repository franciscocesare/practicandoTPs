#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "categoria.h"
#include "juego.h"
#include "clientes.h"
#include "alquileres.h"
#include "informes.h"

#define TAMPILOTO 5
#define TAMDESTINO 5
///#define TAMCAT 5
#define TAMVUELO 9

int menuOpciones();

int main()
{
    int salir;
    int atrasInf;
    int flag=0;

    // int idPiloto=100;
    int idVuelo=1000;
    // int idDestino=1;

    ePiloto pilotos[TAMPILOTO];
    eVuelo vuelos [TAMVUELO];
    eDestino destinos[TAMDESTINO];

    inicializarVuelos(vuelos,TAMVUELO);
    ///inicializarAlquiler(alquiler,TAMA);

    harcodearPilotos(pilotos, TAMPILOTO);
    harcodearDestino(destinos, TAMDESTINO);
    harcodearVuelos(vuelos, TAMVUELO, 7);
    /// harcodearCategoria(cat,TAMCAT);

    ///harcodearJuego(juegos,TAMJ);
    /// idDestino=iDdestino+harcodearDestino(destinos,TAMDESTINO);
    idVuelo=idVuelo+harcodearVuelos(vuelos,TAMVUELO,9);


    do
    {
        switch(menuOpciones())
        {

        case 1:

            if (altaVuelo(vuelos, TAMVUELO,pilotos, TAMPILOTO, destinos, TAMDESTINO, idVuelo))
            {
                idVuelo ++;
                flag=1;
            }
            break;

        case 2:

            if (flag)
            {
                bajaVuelo(vuelos, TAMVUELO, destinos, TAMDESTINO, pilotos, TAMPILOTO);
            }
            else
            {
                printf("\nprimero debe cargar algun vuelo\n");
            }
            break;

        case 3:

            if (flag)
                modificarVuelo(vuelos, TAMVUELO, destinos, TAMDESTINO, pilotos, TAMPILOTO);///ver que nunca deja de pedir la modificacion
            else
            {
                printf("\nprimero debe cargar algun vuelo\n");
            }
            break;

        case 4:
            if (flag)
            {

                system("pause");
                mostrarDestinos(destinos, TAMDESTINO);
                printf("\n-------------------------\n\n");
                mostrarPilotos(pilotos, TAMPILOTO);///me muestra uno con basura nomas
                printf("\n-------------------------\n\n");
              ///  ordenarPilotos(pilotos, TAMPILOTO);
                mostrarVuelos(vuelos, TAMVUELO, destinos, TAMDESTINO, pilotos, TAMPILOTO);
            }
            else
            {

                printf("\nprimero debe cargar algun vuelo\n");
            }

            break;

        case 5:
            if (flag)

            {
                do
                {
                    switch(menuInformes())
                    {
                    case 1 :
                        //mostrarJuegosMesa(juegos,TAMJ,cat,TAMCAT);
                        ///VUELOS DE UN PILOTO SLECCIONADO
                        vuelosPilotoSeleccionado(vuelos, TAMVUELO, pilotos, TAMPILOTO, destinos, TAMDESTINO);
                        //  system("pause");
                        break;

                    case 2 :

                        pilotosDestinoSeleccionado(vuelos, TAMVUELO, pilotos, TAMPILOTO, destinos, TAMDESTINO);
                        // system("pause");
                        break;

                    case 3 :

                        recaudacionPilotoSeleccionado(pilotos, TAMPILOTO, vuelos, TAMVUELO, destinos, TAMDESTINO);
                        //system("pause");
                        break;

                    case 4 :
                        //clientesSinAlquiler(clientes,TAMC,alquiler,TAMA);
                        ///printf("4. Destino mas elegido\n");
                        destinoMasElegido(destinos, TAMDESTINO, vuelos, TAMVUELO);

                        break;


                    case 5 :
                        atrasInf=confimarSalir("\nVolver atras? s/n: ");
                        break;

                    }
                    printf("\n\n");
                    system("pause");

                }
                while(atrasInf !=1);
            }
            else
            {
                printf("\nNO PODEMOS HACER INFORMES SIN CARGAR ALGUN ALTA DE VUELO\n");
            }
            break;

        case 6:
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
    printf("1. Alta Vuelo\n");
    printf("2. Baja Vuelo\n");
    printf("3. Modificar Estado Vuelo\n");
    printf("4. Listar Vuelos\n");
    printf("5. Informes\n");
    printf("6. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}




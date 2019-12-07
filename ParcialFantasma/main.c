#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "entidad_1.h"
#include "entidad_2.h"
#include "entidad_3.h"
#include "informes.h"

#define TAM_ENTIDAD_1 5
#define TAM_ENTIDAD_2 5
#define TAM_ENTIDAD_3 10

int menuOpciones();

int main()
{
    int salir;
    int atrasInf;

    int idEntidad_1=100;
    int idEntidad_2=1000;
    int idEntidad_3=1;

    ePiloto pilotos[TAMPILOTO]; ///como se va a llamar la lista y el tam de cada una
    eVuelo vuelos [TAMVUELO];
    eDestino destinos[TAMDESTINO];

    inicializarVuelos(vuelos,TAMVUELO); ///inicializa las que tienen isEmpty
    ///inicializarAlquiler(alquiler,TAMA);

   hardcodearENTIDAD_1(pilotos, TAMPILOTO); ///hardcodeo en VOID las que no tienen id incremental
   hardcodearENTIDAD_2(destinos, TAMDESTINO);///hardcodeo en VOID las que no tienen id incremental
   hardcodearENTIDAD_3(vuelos, TAMVUELO, 7);///hardcodeo en INT las que tienen id incremental

   idVuelo=idVuelo+harcodearVuelos(vuelos,TAMVUELO,7);///ID incremental con el hardcodeo

    do
    {
        switch(menuOpciones())
        {

        case 1:

            /*if (altaVuelo(vuelos, TAMVUELO,pilotos, TAMPILOTO, destinos, TAMDESTINO, idVuelo))
            {
                idVuelo ++;
            }
            */
            break;

        case 2:

           /// bajaVuelo(vuelos, TAMVUELO, destinos, TAMDESTINO, pilotos, TAMPILOTO);
            break;

        case 3:

            /// modificarVuelo(vuelos, TAMVUELO, destinos, TAMDESTINO, pilotos, TAMPILOTO);///ver que nunca deja de pedir la modificacion
            break;

        case 4:
           // mostrarAlquileres(alquiler,TAMA,juegos,TAMJ,clientes,TAMC);
             //printf("4. Listar Vuelos\n");
             //mostrarVuelo(vuelos[2], destinos, TAMDESTINO, pilotos, TAMPILOTO);

           // mostrarDestino(destinos[2]);
            system("pause");
            mostrarDestinos(destinos, TAMDESTINO);
            printf("\n-------------------------\n\n");
            mostrarPilotos(pilotos, TAMPILOTO);///me muestra uno con basura nomas
            printf("\n-------------------------\n\n");
            mostrarVuelos(vuelos, TAMVUELO, destinos, TAMDESTINO, pilotos, TAMPILOTO);


            break;

        case 5:
            do
            {
                switch(menuInformes())
                {
                case 1 :
                ///vuelosPilotoSeleccionado(vuelos, TAMVUELO, pilotos, TAMPILOTO, destinos, TAMDESTINO);
                  ///  system("pause");
                    break;

                case 2 :

                    ///pilotosDestinoSeleccionado(vuelos, TAMVUELO, pilotos, TAMPILOTO, destinos, TAMDESTINO);
                   /// system("pause");
                    break;

                case 3 :

                    ///recaudacionPilotoSeleccionado(pilotos, TAMPILOTO, vuelos, TAMVUELO, destinos, TAMDESTINO);
                    system("pause"); ///SI EN LA FUNCION NO TIENE SYSTEM PAUSE
                    break;

                case 4 :

                    ///7destinoMasElegido(vuelos, TAMVUELO, destinos, TAMDESTINO);

                    break;


                case 5 :
                    atrasInf=confimarSalir("\nVolver atras? s/n: ");
                    break;

                }
                printf("\n\n");
                system("pause");

            }while(atrasInf !=1);
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
    printf("1. Alta xxxxxx\n");
    printf("2. Baja xxxxxxxx\n");
    printf("3. Modificar xxxxxxxx\n");
    printf("4. Listar xxxxxx\n");
    printf("5. Informes\n");
    printf("6. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

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
#define TAM_ENTIDAD_3 9


int menuOpciones();

int main()
{
    int salir;
    int atrasInf;
    int flag=0;


    int idVuelo=1000;


    ePiloto pilotos[TAM_ENTIDAD_1];
    eVuelo vuelos [TAM_ENTIDAD_3];
    eDestino destinos[TAM_ENTIDAD_2];

    inicializarVuelos(vuelos,TAM_ENTIDAD_3);

    harcodearPilotos(pilotos, TAM_ENTIDAD_1);
    harcodearDestino(destinos, TAM_ENTIDAD_2);
    harcodearVuelos(vuelos, TAM_ENTIDAD_3, 7);



    idVuelo=idVuelo+harcodearVuelos(vuelos,TAM_ENTIDAD_3,9);


    do
    {
        switch(menuOpciones())
        {

        case 1:

            if (altaVuelo(vuelos, TAM_ENTIDAD_3,pilotos, TAM_ENTIDAD_1, destinos, TAM_ENTIDAD_2, idVuelo))
            {
                idVuelo ++;
                flag=1;
            }
            break;

        case 2:

            if (flag)
            {
                bajaVuelo(vuelos, TAM_ENTIDAD_3, destinos, TAM_ENTIDAD_2, pilotos, TAM_ENTIDAD_1);
            }
            else
            {
                printf("\nprimero debe cargar algun vuelo\n");
            }
            break;

        case 3:

            if (flag)
                modificarVuelo(vuelos, TAM_ENTIDAD_3, destinos, TAM_ENTIDAD_2, pilotos, TAM_ENTIDAD_1);///ver que nunca deja de pedir la modificacion
            else
            {
                printf("\nprimero debe cargar algun vuelo\n");
            }
            break;

        case 4:
            if (flag)
            {

                system("pause");
                mostrarDestinos(destinos, TAM_ENTIDAD_2);
                printf("\n-------------------------\n\n");
                mostrarPilotos(pilotos, TAM_ENTIDAD_1);///me muestra uno con basura nomas
                printf("\n-------------------------\n\n");

                mostrarVuelos(vuelos, TAM_ENTIDAD_3, destinos, TAM_ENTIDAD_2, pilotos, TAM_ENTIDAD_1);
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

                        vuelosPilotoSeleccionado(vuelos, TAM_ENTIDAD_3, pilotos, TAM_ENTIDAD_1, destinos, TAM_ENTIDAD_2);

                        break;

                    case 2 :

                        pilotosDestinoSeleccionado(vuelos, TAM_ENTIDAD_3, pilotos, TAM_ENTIDAD_1, destinos, TAM_ENTIDAD_2);

                        break;

                    case 3 :

                        recaudacionPilotoSeleccionado(pilotos, TAM_ENTIDAD_1, vuelos, TAM_ENTIDAD_3, destinos, TAM_ENTIDAD_2);

                        break;

                    case 4 :

                        destinoMasElegido(destinos, TAM_ENTIDAD_2, vuelos, TAM_ENTIDAD_3);

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


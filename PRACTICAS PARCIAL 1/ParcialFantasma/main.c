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
{ int salir;
    int atrasInf;
    int flag=0;

    // int idPiloto=100;
    int idVuelo=1000; ///ACA VA A IR EL ID QUE SEA INCREMENTAL
    // int idDestino=1;

    ePiloto pilotos[TAMPILOTO]; ///DEFINO CADA LISTA
    eVuelo vuelos [TAMVUELO]; ///DEFINO CADA LISTA
    eDestino destinos[TAMDESTINO]; ///DEFINO CADA LISTA

    inicializarVuelos(vuelos,TAMVUELO); ///INICIALIZAR EL QUE TIENE CAMPO ISEMPTY
    ///inicializarAlquiler(alquiler,TAMA);

    harcodearPilotos(pilotos, TAMPILOTO); ///HARDCODEO VOID XQ NO TIENE ISEMPTY
    harcodearDestino(destinos, TAMDESTINO); ///HARDCODEO VOID XQ NO TIENE ISEMPTY
    harcodearVuelos(vuelos, TAMVUELO, 7); ///harcodie 9, 2 en isemty 1
    /// harcodearCategoria(cat,TAMCAT);

    ///harcodearJuego(juegos,TAMJ);
    /// idDestino=iDdestino+harcodearDestino(destinos,TAMDESTINO);

    idVuelo=idVuelo+harcodearVuelos(vuelos,TAMVUELO,9);  ///PARA EL ID INCREMENTAL


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
                printf("\nprimero debe cargar xxxxxx\n");
            }
            break;

        case 3:

            if (flag)
                modificarVuelo(vuelos, TAMVUELO, destinos, TAMDESTINO, pilotos, TAMPILOTO);///ver que nunca deja de pedir la modificacion
            else
            {
                printf("\nprimero debe cargar xxxxxxxx\n");
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

                printf("\nprimero debe cargar algun xxxxx\n");
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
                printf("\nNO PODEMOS HACER INFORMES SIN CARGAR ALGUN ALTA DE xxxxxx\n");
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
    printf("1. Alta XXXXXXX\n");
    printf("2. Baja XXXXXX\n");
    printf("3. Modificar XXXXXXXXx\n");
    printf("4. Listar XXXXXXXXX\n");
    printf("5. Informes\n");
    printf("6. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

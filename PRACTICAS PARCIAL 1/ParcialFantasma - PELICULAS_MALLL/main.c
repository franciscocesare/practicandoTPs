#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputDiaz.h"
#include "entidad_1.h"
#include "entidad_2.h"
#include "entidad_3.h"
#include "informes.h"

#define TAMPELICULAS 5
#define TAMACTORES 5
#define TAMGENEROS 5

int menuOpciones();

int main()
{ int salir;
    int atrasInf;
    int flag=0;

    // int idPiloto=100;
    int idPelicula=1000; ///ACA VA A IR EL ID QUE SEA INCREMENTAL
    // int idDestino=1;

    ePelicula peliculas[TAMPELICULAS]; ///DEFINO CADA LISTA
    eGenero generos [TAMGENEROS]; ///DEFINO CADA LISTA
    eActores actores[TAMACTORES]; ///DEFINO CADA LISTA

    inicializarPeliculas(peliculas, TAMPELICULAS); ///INICIALIZAR EL QUE TIENE CAMPO ISEMPTY


    hardcodearGeneros(generos, TAMGENEROS); ///HARDCODEO VOID XQ NO TIENE ISEMPTY
    hardcodearActores(actores, TAMACTORES); ///HARDCODEO VOID XQ NO TIENE ISEMPTY
    hardcodearPeliculas(peliculas, TAMPELICULAS, 7); ///harcodie 9, 2 en isemty 1


    idPelicula=idPelicula+hardcodearPeliculas(peliculas, TAMPELICULAS,7);  ///PARA EL ID INCREMENTAL


    do
    {
        switch(menuOpciones())
        {

        case 1:

            if (altaPelicula(peliculas, TAMPELICULAS, generos, TAMGENEROS, actores, TAMACTORES))
            {
                idPelicula ++;
                flag=1;
            }
            break;

        case 2:

            if (flag)
            {
              ///  bajaVuelo(vuelos, TAMVUELO, destinos, TAMDESTINO, pilotos, TAMPILOTO);
            }
            else
            {
                printf("\nprimero debe cargar xxxxxx\n");
            }
            break;

        case 3:

            if (flag)
                modificarPelicula(peliculas, TAMPELICULAS, generos, TAMGENEROS, actores, TAMACTORES);///ver que nunca deja de pedir la modificacion
            else
            {
                printf("\nprimero debe cargar xxxxxxxx\n");
            }
            break;

        case 4:
            if (flag)
            {
                mostrarPeliculas(peliculas, TAMPELICULAS, generos, TAMGENEROS, actores, TAMACTORES);
/*
                system("pause");
                mostrarDestinos(destinos, TAMDESTINO);
                printf("\n-------------------------\n\n");
                mostrarPilotos(pilotos, TAMPILOTO);///me muestra uno con basura nomas
                printf("\n-------------------------\n\n");
              ///  ordenarPilotos(pilotos, TAMPILOTO);
                mostrarVuelos(vuelos, TAMVUELO, destinos, TAMDESTINO, pilotos, TAMPILOTO);
           */
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
                    ///    vuelosPilotoSeleccionado(vuelos, TAMVUELO, pilotos, TAMPILOTO, destinos, TAMDESTINO);
                        //  system("pause");
                        break;

                    case 2 :

                      ///  pilotosDestinoSeleccionado(vuelos, TAMVUELO, pilotos, TAMPILOTO, destinos, TAMDESTINO);
                        // system("pause");
                        break;

                    case 3 :

                     ///   recaudacionPilotoSeleccionado(pilotos, TAMPILOTO, vuelos, TAMVUELO, destinos, TAMDESTINO);
                        //system("pause");
                        break;

                    case 4 :
                        //clientesSinAlquiler(clientes,TAMC,alquiler,TAMA);
                        ///printf("4. Destino mas elegido\n");
                    ///    destinoMasElegido(destinos, TAMDESTINO, vuelos, TAMVUELO);

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

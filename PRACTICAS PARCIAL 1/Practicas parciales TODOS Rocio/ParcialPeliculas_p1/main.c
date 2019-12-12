#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "peliculas.h"
#include "generosActores.h"

#define TAM 15
#define TAMA 5
#define TAMG 4


int main()
{
    int idPelicula=1000;
    int salir;
    ePeliculas peliculas[TAM];
    eGenero generos[TAMG]= {{100,"Terror"},{101,"Comedia"},{102,"Accion"},{103,"Drama"}};
    eActores actores[TAMA]= {{1, "Julieta Roberto", "EEUU"},{2, " Roberto Deniro", "EEUU"},{3, " Richar Darin", "Argentina"},{4, "Tita Merelo", "Argentina"},{5, "Sandro", "Argentina"}};

    inicilizarPeliculas(peliculas,TAM);

    idPelicula = idPelicula + hardcodeoPeliculas(peliculas,TAM,11);

    do
    {

        switch(menuPrincipal())
        {
        case 1 :
            if(altaPelicula(peliculas,TAM,actores,TAMA,generos,TAMG,idPelicula))
            {
                idPelicula++;
            }
            break;

        case 2 :
            modificarPelicula(peliculas,TAM,actores,TAMA,generos,TAMG);
            break;

        case 3 :
            bajaPelicula(peliculas,TAM,actores,TAMA,generos,TAMG);
            break;

        case 4 :
            mostrarGeneros(generos,TAMG);
            break;

        case 5 :
            mostrarActores(actores,TAMA);
            break;

        case 6 :
            mostrarPeliculas(peliculas,TAM,generos,TAMG,actores,TAMA);
            break;

        case 7 :
            salir=confimarSalir("\nDesea salir? s/n: ");
            break;

        default:
            printf("\nOpcion invalida.\n\n");
        }

        system("pause");
    }
    while(salir != 1);


    return 0;
}

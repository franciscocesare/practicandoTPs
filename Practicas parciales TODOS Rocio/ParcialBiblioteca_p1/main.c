#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "libros.h"
#include "autores.h"
#include "socios.h"
#include "prestamos.h"
#include "inputDiaz.h"

#define TAMA 10
#define TAML 10
#define TAMS 11
#define TAMP 15

char menuOpciones();

int main()
{
    int salir;
    int idSocio=100;
    int idPrestamos=1000;

    eAutores autores[TAMA];
    eLibro libros[TAML];
    eSocio socios[TAMS];
    ePrestamo prestamos[TAMP];

   iniciarlizarSocios(socios,TAMS);
   iniciarlizarPrestamos(prestamos,TAMP);

   hardCodeAutores(autores,TAMA,10);
   hardCodeLibros(libros,TAML,10);

   idSocio=idSocio+hardCodeSocios(socios,TAMS,10);
   idPrestamos=idPrestamos+hardCodePrestamos(prestamos,TAML,9);

    do
    {
        switch(menuOpciones())
        {
        case 'a':
            if(altaSocio(socios,TAMS,idSocio)==1)
            {
                idSocio++;
            }

            break;

        case 'b':
            modificarSocio(socios,TAMS);
            break;

        case 'c':
            bajaSocio(socios,TAMS);
            break;

            case 'd':
                ordenarSocios(socios,TAMS);
                mostrarSocios(socios,TAMS);
            break;


            case 'e':
                ordenarLibros(libros,TAML);
                mostrarLibros(libros,TAML,autores,TAMA);
            break;

            case 'f':
                ordenarActores(autores,TAMA);
                mostrarAutores(autores,TAMA);
            break;


            case 'g':
                if(altaPrestamo(prestamos,TAMP,socios,TAMS,libros,TAML,autores,TAMA,idPrestamos)==1)
                {
                    idPrestamos++;
                }
            break;

            case 'h':
                mostrarPrestamos(prestamos,TAMP,socios,TAMS,libros,TAML);
            break;

        case 'i':
            salir=confimarSalir("\nDesea salir? s/n: ");
            break;

        default:
            printf("\nIngrese opcion invalida\n\n");

        }

        printf("\n\n");
        system("pause");

    }while(salir != 1);

    printf("Chau\n\n");



    return 0;
}

char menuOpciones()
{
    char opcion;

    system("cls");
    printf("*** MENU DE OPCIONES ***\n\n");

    printf("A_ Alta socios\n");
    printf("B_ Modificar socios\n");
    printf("C_ Baja socios\n");
    printf("D_ Listar socios\n");
    printf("E_ Listar libros\n");
    printf("F_ Listar autores\n");
    printf("G_ Alta prestamos\n");
    printf("H_ Listar prestamos\n\n");
    printf("I_ Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion=getchar();

    opcion=tolower(opcion);

    while(opcion > 'c' && opcion < 'a')
    {
        printf("Ingrese opcion valida: ");
        fflush(stdin);
        opcion=getchar();

        opcion=tolower(opcion);
    }

    return opcion;
}






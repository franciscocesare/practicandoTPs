#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carrera.h"
#include "alumno.h"

#define TAM 15
#define TAMC 3


int menu();

int main()
{
    eAlumno lista[TAM];
    eCarrera carreras[TAMC]= {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};

    int legajo=20000;
    char salir = 'n';

    inicializarAlumnos( lista, TAM);

    legajo=legajo+hardcodearAlumnos(lista,TAM, 9);

    do
    {
        switch( menu())
        {
        case 1:
            if(altaAlumno(lista, TAM,legajo,carreras,TAMC))
            {
                legajo++;
            }
            break;

        case 2:
            bajaAlumno(lista, TAM,carreras, TAMC);
            break;

        case 3:
            ModificarAlumno(lista, TAM,carreras,TAMC);
            break;

        case 4:
            mostrarAlumnos(lista, TAM,carreras,TAMC);
            break;

        case 5:
            if(ordenarAlumnos(lista, TAM) != -1)
            {
                system("cls");
                printf("Datos ordenados!!\n\n");
            }
            else
            {
                printf("Error al ordenar\n\n");
                system("cls");
            }
            break;

        case 6:
            printf("Informes Alumno\n\n");
            break;

        case 7:
            mostrarCarreras(carreras,TAMC);
            break;

        case 8:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Mostrar carreras\n");
    printf("8-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}




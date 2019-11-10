#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carrera.h"
#include "alumno.h"

void mostrarCarreras(eCarrera vec[], int tamC)
{
    int flag = 0;
    system("cls");

    printf("   Id     Descripcion\n");
    printf(" ------   ----------- \n\n");

    for(int i=0; i < tamC; i++)
    {
        mostrarCarrera(vec[i]);
        flag = 1;
    }

    if( flag == 0)
    {
        printf("\nNo hay carreras que mostrar\n");
    }

    printf("\n\n");
}

int obtenerNomCarrera(eCarrera vec[], int tamC, int id, char dondeAsinar[])
{
    int todoOk=-1;

    for(int i= 0 ; i<tamC; i++)
    {
        if(id == vec[i].idCarrera)
        {
            strcpy(dondeAsinar,vec[i].descripcion);
            todoOk=1;
            break;
        }
    }

    return todoOk;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("****** Menu de Informes *******\n\n");
    printf("1-Mostrar alumnos de una carrera.\n");
    printf("2-Mostrar alumnos por carrera\n");
    printf("3-Mostrar cantidad de alumnos por carrera\n");
    printf("4-Mostrar la carrera con mas inscriptos\n");
    printf("5-Mostrar mejor promedio por carrera\n");
    printf("6-Mostrar alumnos varones\n");
    printf("7-Mostrar mujeres de alguna carrera\n");
    printf("8-Mostrar alumnos mayores a 30 de Licenciatura\n");
    printf("9-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void informes(eAlumno vec[], int tamA, eCarrera vecC[], int tamC)
{
    char salir;

    switch(menuInformes())
    {
    case 1:
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;

    case 6:
        break;

    case 7:
        break;

    case 8:
        break;

    case 9:
        printf("Confirma salir?:");
        fflush(stdin);
        salir = getche();
        break;

    default:
        printf("Opcion invalida!\n\n");

    }
    while(salir != 's');
}

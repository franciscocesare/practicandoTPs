#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 10

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;

} eAlumno;

int menuOpciones();
void mostrarAlumno(eAlumno vec);
void mostrarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnosNombre( eAlumno vec[], int tam);

int main()
{
    eAlumno alumnos[TAM];
    char salir = 's';

    do
    {
        switch(menuOpciones())
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
            printf("Desea salir? s/n: ");
            fflush(stdin);
            salir=getchar();
            break;

        default:
            system("cls");
            printf("Opcion invalida!!!\n");

        }
    }
    while(salir != 's');


    return 0;
}

int menuOpciones()
{
    int opcion;

    system("cls");
    printf("----- MENU DE OPCIONES ------\n\n");
    printf("1_ Alta alumno\n");
    printf("2_ Baja alumno\n");
    printf("3_ Modifica alumno\n");
    printf("4_ Listar alumnos\n");
    printf("5_ Ordenar alumnos\n");
    printf("6_ Informes\n");
    printf("7_ Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void mostrarAlumno(eAlumno vec)
{
    printf(" %d  %8s    %d     %c     %2d        %2d      %.2f   %02d/%02d/%d\n",vec.legajo,vec.nombre,vec.edad,vec.sexo,vec.nota1,vec.nota2,vec.promedio,vec.fechaIngreso.dia,vec.fechaIngreso.mes,vec.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    printf("Legajo   Nombre   Edad   Sexo   Nota-1   Nota-2  Promedio    Fecha Ingreso\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarAlumno(vec[i]);
    }
}

void ordenarAlumnosNombre( eAlumno vec[], int tam)
{
    eAlumno auxAlumno;

    for(int i=0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if( strcmp(vec[i].nombre, vec[j].nombre) > 0)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
}

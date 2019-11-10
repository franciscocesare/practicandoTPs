#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 2

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
    int isEmpty;

} eAlumno;

void mostrarAlumno(eAlumno x);
void mostrarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno vec[], int tam);
int buscarLibre(eAlumno vec[], int tam);
int buscarAlumno(int legajo, eAlumno vec[], int tam);
int altaAlumno(eAlumno vec[], int tam);
eAlumno newAlumno(int leg,char nombre[],int edad, char sexo, int nota1, int nota2, eFecha f);
int bajaAlumno(eAlumno vec[], int tam);
int ModificarAlumno(eAlumno vec[], int tam);
void hardcodearAlumnos( eAlumno vec[],int cant);
int menu();

int main()
{
    eAlumno lista[TAM];
    char salir = 'n';

    inicializarAlumnos( lista, TAM);

    hardcodearAlumnos(lista, 6);

    do
    {
        switch( menu())
        {
        case 1:
            altaAlumno(lista, TAM);
            break;

        case 2:
            bajaAlumno(lista, TAM);
            break;

        case 3:
            ModificarAlumno(lista, TAM);
            break;

        case 4:
            mostrarAlumnos(lista, TAM);
            break;

        case 5:

            ordenarAlumnos(lista, TAM);
            break;

        case 6:
            printf("Informes Alumno\n\n");
            break;

        case 7:
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
    printf("7-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


void mostrarAlumno(eAlumno x)
{
    printf("  %d     %s     %d    %c   %d  %d  %.2f %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam)
{

    int flag = 0;
    system("cls");

    printf(" Legajo Nombre Edad Sexo Nota1 Nota2 Promedio FIngreso\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlumno(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay alumnos que mostrar\n");
    }

    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam)
{
    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].legajo > vec[j].legajo)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
}

void inicializarAlumnos(eAlumno vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int buscarLibre(eAlumno vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAlumno(int legajo, eAlumno vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlumno(eAlumno vec[], int tam){
    int todoOk = 0;
    int indice;
    int esta;
    int legajo;
    char nombre[20];
    char sexo;
    int edad;
    int n1;
    int n2;
    eFecha fecha;

    system("cls");

    printf("*****Alta Alumno*****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1){
        printf("\nSistema completo\n\n");
    }
    else{

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarAlumno(legajo, vec, tam);

        if( esta != -1){
            printf("\nEse legajo ya se encuentra registrado\n\n");
            mostrarAlumno(vec[esta]);

        }
        else{
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(nombre);

                printf("Ingrese edad: ");
                scanf("%d", &edad);

                printf("Ingrese sexo: ");
                fflush(stdin);
                scanf("%c", &sexo);

                printf("Ingrese nota 1: ");
                scanf("%d", &n1);

                printf("Ingrese nota 2: ");
                scanf("%d", &n2);

                printf("Ingrese fecha ingreso: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

                vec[indice] = newAlumno(legajo, nombre, edad, sexo, n1, n2, fecha);
                todoOk = 1;
                printf("Alta exitosa!!\n\n");

        }

    }

    return todoOk;
}

eAlumno newAlumno(
                  int leg,
                  char nombre[],
                  int edad,
                  char sexo,
                  int nota1,
                  int nota2,
                  eFecha fecha){

    eAlumno al;
    al.legajo = leg;
    strcpy( al.nombre, nombre);
    al.sexo = sexo;
    al.edad = edad;
    al.nota1 = nota1;
    al.nota2 = nota2;
    al.promedio = (float) (nota1 + nota2 )/2;
    al.fechaIngreso = fecha;
    al.isEmpty = 0;

    return al;
}


int bajaAlumno(eAlumno vec[], int tam){
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, vec , tam);

    if( indice == -1){
        printf("No existe un alumno con ese legajo\n\n");

    }
    else{

        mostrarAlumno(vec[indice]);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's'){
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else{
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}

int ModificarAlumno(eAlumno vec[], int tam){

    int todoOk = 0;
    int legajo;
    int indice;

    system("cls");
    printf("***** Modificar Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    int opcion;

    indice = buscarAlumno(legajo, vec , tam);

    if( indice == -1){
        printf("No existe un alumno con ese legajo\n\n");

    }
    else{

        mostrarAlumno(vec[indice]);

        printf("1- Modificar nota1\n");
        printf("2- Modificar nota2\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
    case 1:
        printf("Ingrese nueva nota: ");
        scanf("%d", &vec[indice].nota1);
        vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
        break;

    case 2:
        printf("Ingrese nueva nota: ");
        scanf("%d", &vec[indice].nota2);
        vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
        break;
    case 3:
        printf("Se ha cancelado la mofdificacion ");
        break;

        }
    }
    return todoOk;
}


void hardcodearAlumnos( eAlumno vec[],int cant)
{
     eAlumno datos [15]=
        {
            {1234, "Juan", 20, 'm', 4, 6, 5,{16, 9, 2019},0},
            {1111, "Juana", 19, 'f', 7, 4, 5.5,{20, 3, 2018},0},
            {1221, "Ariel", 21, 'm', 10, 2, 6,{12, 11, 2013},0},
            {1001, "Jazmin", 20, 'f', 8, 8, 8,{9, 8, 2018},0},
            {1020, "Abril", 22, 'f', 4, 5, 4.5,{4, 5, 2015},0},
            {1234, "Lucas", 22, 'm', 6, 6, 6,{17, 12, 2017},0},
            {1111, "Rocio", 24, 'f', 7, 5, 6,{23, 11, 2019},0},
            {1221, "Diego", 21, 'm', 10, 2, 6,{11, 4, 2012},0},
            {1001, "Mariela", 18, 'f', 8, 9, 8.5,{7, 4, 2011},0},
            {1020, "Micaela", 23, 'f', 4, 7, 5.5,{8, 3, 2010},0},
            {1234, "Tomas", 21, 'm', 7, 6, 6.5,{17, 12, 2017},0},
            {1111, "Camila", 20, 'f', 7, 8, 7.5,{23, 11, 2019},0},
            {1221, "Lucas", 19, 'm', 10, 4, 7,{11, 4, 2012},0},
            {1001, "Valentina", 18, 'f', 9, 9, 9,{7, 4, 2011},0},
            {1020, "Rosario", 22, 'f', 9, 7, 8,{8, 3, 2010},0}
        };

    for(int i=0; i<cant; i++)
    {
        vec[i] = datos[i];
    }

}


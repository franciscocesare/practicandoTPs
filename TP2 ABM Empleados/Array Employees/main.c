#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "conio.h"
#include "ctype.h"

#define TAM 5

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

///prototipos funciones para despues llevarme

void inicializarEmpleados(Employee vec[], int tam);
int buscarLibre(Employee vec[], int tam);
int altaEmpleado(Employee vec[], int tam,int idEmployee);
Employee newEmployee(int id, char name[],char lastName[], float salary, int sector);
void mostrarEmpleado(Employee x);
void mostrarEmpleados(Employee vec[], int tam);
int buscarEmpleado(int id, Employee vec[], int tam);
int ModificarEmpleado(Employee vec[], int tam);
void sortEmployeesByLastName(Employee vec[], int tam);
void sortEmployeesBySector(Employee vec[], int tam);
int bajaEmpleado(Employee vec[], int tam);
int menu();
int menuInformes();

int main()
{
    Employee lista[TAM];
    char salir = 'n';
    int idEmployee=1;

    inicializarEmpleados( lista, TAM);

    ///hardcodearEmpleados(lista, TAM, 5);///el numero final es la cantidad a mostrar hardcodeados

    do
    {
        switch( menu())
        {
        case 1:
            if (altaEmpleado(lista, TAM, idEmployee))
            {
                idEmployee ++;
            }

            break;

        case 2:
            bajaEmpleado(lista, TAM);
            break;

        case 3:
            ModificarEmpleado(lista, TAM);
            break;

        case 4:
            switch (menuInformes())
                {
                    case 1:
                        printf("empleados ordenados alfabéticamente por Apellido y Sector\n\n");
                        sortEmployeesByLastName(lista, TAM);
                        ///sortEmployeesBySector(lista,TAM);
                        mostrarEmpleados(lista, TAM);
                        system("pause");

                        break;

                    case 2:
                    printf("Total y promedio de los salarios\n");

                    printf("empleades que superan el salario promedio\n");

             mostrarEmpleados(lista, TAM);
                    break;
                }
                break;

        case 5:
            printf("Confirma salir del ABM emplades?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(tolower (salir == 'n'));

    return 0;
}

///desarrollo funciones que despues me llevo a employees.c

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Empleades *******\n\n");
    printf("1-Alta Empleade\n");
    printf("2-Baja Empleade\n");
    printf("3-Modificar Empleade \n");
    printf("4-Informes Empleades\n");
    printf("5-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int altaEmpleado(Employee vec[], int tam, int idEmployee)
{

    int todoOk = 0;
    int indice;
    int esta;
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
///   int isEmpty;

    system("cls");

    printf("*****Alta Empleade*****\n\n");

    indice = buscarLibre(vec, tam); ///a ver si hay lugar libre, lo guarda en indice 1 si hay, -1 sino

    if( indice == -1)
    {
        printf("\nEl Sistema Esta Completo\n\n");
    }
    else
    {
        vec[indice].id = idEmployee;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(name);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(lastName);

        printf("Ingrese salario: ");
        scanf("%f", &salary);

        printf("Ingrese sector, sectores de 1 al 5: ");
        fflush(stdin);
        scanf("%d", &sector);
        while (sector<0 || sector>5)
        {
            printf("Sector invalido, intentelo nuevamente: ");
            scanf("%d", &sector);
        }

        vec[indice] = newEmployee(idEmployee, name, lastName, salary, sector);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");

    }



    return todoOk;
}

Employee newEmployee(

    int idEmployee,
    char name[],
    char lastName[],
    float salary,
    int sector)
{

    Employee al;
    al.id = idEmployee;
    strcpy( al.name, name);
    strcpy( al.lastName, lastName);
    al.sector = sector;
    al.salary = salary;
    al.isEmpty = 0;

    return al;
}

void mostrarEmpleado(Employee x)
{
    printf(" %d  %10s   %10s    %d    %3.2f \n",
           x.id,
           x.lastName,
           x.name,
           x.sector,
           x.salary);
}

void mostrarEmpleados(Employee vec[], int tam)
{

    int flag = 0;
    system("cls");

    printf(" ID   APELLIDO    NOMBRE    SECTOR      SALARIO\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay empleades que mostrar\n");
    }

    printf("\n\n");
}

///aca quise ordenar en una funcion por apellido y por sector

void sortEmployeesByLastName(Employee vec[], int tam)
{
    Employee auxEmployeeLastName;
    Employee auxEmployeeSector;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].lastName > vec[j].lastName && vec [i].sector > vec [i].sector)
            {
                auxEmployeeLastName = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmployeeLastName;
                auxEmployeeSector = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmployeeSector;

            }
        }
    }
    ///printf("Empleades Ordenados\n\n");
}

/*void sortEmployeesBySector(Employee vec[], int tam) ///por nombre por ahora
{
    Employee auxEmployee;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].sector > vec[j].sector)
            {
                auxEmployee = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmployee;
            }
        }
    }
    ///printf("Empleades Ordenados\n\n");
}
*/
int bajaEmpleado(Employee vec[], int tam)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Empleade *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(id, vec, tam);

    if( indice == -1)
    {
        printf("No existe un empleade con ese ID\n\n");

    }
    else
    {

        mostrarEmpleado(vec[indice]);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja de empleade exitosa!!!");
        }
        else
        {
            printf("\nNo se realizo la baja correspondiente ");
        }
    }

    return todoOk;
}
int ModificarEmpleado(Employee vec[], int tam)
{

    int todoOk = 0;
    int id;
    int indice;
    ///char confirma;
    system("cls");
    printf("***** Modificar Empleade *****\n\n");
    printf("Ingrese id del empleade: ");
    scanf("%d", &id);
    int opcion;

    indice = buscarEmpleado(id, vec, tam);

    if( indice == -1)
    {
        printf("No existe un empleade con ese id\n\n");

    }
    else
    {

        mostrarEmpleado(vec[indice]);

        printf("***MODIFICAR UN EMPLEADE***");
        printf("1- Modificar nombre\n");
        printf("2- Modificar apellido\n");
        printf("3- Modificar salario\n");
        printf("4- Modificar sector\n");
        printf("5- Salir\n\n");
        printf("Ingrese opcion: \n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nombre nuevo: ");
            fflush(stdin);
            scanf("%s", vec[indice].name);
            break;

        case 2:
            printf("Ingrese nuevo apellido : ");
            fflush(stdin);
            scanf("%s", vec[indice].lastName);
            break;

        case 3:
            printf("Ingrese nuevo salario: ");
            scanf("%f", &vec[indice].salary);
            break;

        case 4:
            printf("Ingrese nuevo sector: ");
            scanf("%d", &vec[indice].sector);
            while (vec[indice].sector<0 || vec[indice].sector>5)
            {
                printf("Sector invalido, intentelo nuevamente: ");
                scanf("%d", &vec[indice].sector);
            }

            break;

        case 5:
            printf("Se ha cancelado la modificacion ");
            break;

        }
    }
    return todoOk;
}

void inicializarEmpleados(Employee vec[], int tam)///inicia el array, pone todas las posicciones en 1. VACIO
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int buscarLibre(Employee vec[], int tam)
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

int buscarEmpleado(int id, Employee vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("*** Menu de informes Empleades ***\n\n");
    printf("1-Empleades ordenados alfabéticamente por Apellido y Sector\n");
    printf("2-Total y promedio de los salarios, y cuántos empleades superan el salario promedio\n");
    printf("3-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

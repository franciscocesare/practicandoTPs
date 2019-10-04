#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "conio.h"
#include "ctype.h"

#define TAM 4
/*
-REVISAR ALGUNAS VALIDACIONES HACER POR EJEMPLO QUE NO SE PASEN DEL STRING?
-PASAR A .C LOS DESARROLLOS Y .H LAS CABECERAS LAS FUNCIONES
-VER TOLOWERCASE EN ALGUNOS CASOS
-HACER ULTIMO PUNTO DE INFORMES
-ORDENAR UN POCO LOS PRINT QUE ESTAN DESFAZADOS
-DEFINIR EL TAM EN 1000
-BORRAR LOS HARDCODEADOS
-NO HICE findEmployeeById, esta mal????
*/

typedef struct
{
    int id;
    char name[30];
    char lastName[30];
    float salary;
    int sector;
    int isEmpty;
} Employee;

///prototipos funciones para despues llevarme

void initEmployee(Employee vec[], int tam);
int findFree(Employee vec[], int tam);
int addEmployee(Employee vec[], int tam,int idEmployee);
Employee newEmployee(int id, char name[],char lastName[], float salary, int sector);
void showEmployee(Employee x);
void printEmployees(Employee vec[], int tam);
int findEmployee(int id, Employee vec[], int tam);
int modifyEmployee(Employee vec[], int tam);
void sortEmployeesByLastName(Employee vec[], int tam);
int removeEmployee(Employee vec[], int tam);
int menu();
int menuReports();

int main()
{
    Employee lista[TAM]=
    {
        {1121, "juan", "perez", 30000, 2,0},
        {1431, "pepe", "gutierrez", 35000, 3,0},
        {1317, "alberto", "gerez", 20000, 4,0},
        {1521, "roque", "zalar", 27000, 1,0},


    };



    char salir = 'n';
    int idEmployee=1;

    //initEmployee(lista, TAM);

    ///hardcodearEmpleados(lista, TAM, 5);///el numero final es la cantidad a mostrar hardcodeados

    do
    {
        switch( menu())
        {
        case 1:
            if (addEmployee(lista, TAM, idEmployee))
            {
                idEmployee ++;
            }

            break;

        case 2:
            removeEmployee(lista, TAM);
            break;

        case 3:
            modifyEmployee(lista, TAM);
            break;

        case 4:
            switch (menuReports())
            {
            case 1:
                printf("empleados ordenados alfabeticamente por Apellido y Sector\n\n");
                sortEmployeesByLastName(lista, TAM);
                ///sortEmployeesBySector(lista,TAM);
                printEmployees(lista, TAM);
                system("pause");

                break;

            case 2:
                printf("Total y promedio de los salarios\n");

                printf("empleades que superan el salario promedio\n");

                printEmployees(lista, TAM);
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
    while(tolower(salir == 'n'));

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


int addEmployee(Employee vec[], int tam, int idEmployee)
{

    int todoOk = 0;
    int index;
    ///int esta;
    ///int id;
    char name[30];
    char auxName[25];
    char lastName[40];
    char auxLastName[30];
    float salary;
    int sector;
///   int isEmpty;

    system("cls");

    printf("*****Alta Empleade*****\n\n");

    index = findFree(vec, tam); ///a ver si hay lugar libre, lo guarda en index 1 si hay, -1 sino

    if( index == -1)
    {
        printf("\nEl Sistema Esta Completo\n\n");
    }
    else
    {
        vec[index].id = idEmployee;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxName);
        while (strlen (auxName) >25)///condicion de dato invalido, para que lo siga pidiendo
        {
            printf("Error Nombre muy largo, ingrese el nombre: ");
            fflush(stdin);
            gets(auxName);
        }
        strcpy (name, auxName); ///si el dato es valido, lo copio en nombre!

        //return 0;

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxLastName);
        while (strlen (auxLastName) >30)///condicion de dato invalido, para que lo siga pidiendo
        {
            printf("Error apellido muy largo, ingrese el Apellido: ");
            fflush(stdin);
            gets(auxLastName);
        }
        strcpy (lastName, auxLastName); ///si el dato es valido, lo copio en nombre!

        //return 0;

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

        vec[index] = newEmployee(idEmployee, name, lastName, salary, sector);
        todoOk = 1;
        printf("\nSe ha realizado el alta del empleade\n\n");

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

void showEmployee(Employee x)
{
    printf(" %d  %10s   %10s    %d    %3.2f \n",
           x.id,
           x.lastName,
           x.name,
           x.sector,
           x.salary);
}

void printEmployees(Employee vec[], int tam)
{

    int flag = 0;
    system("cls");

    printf(" ID   APELLIDO    NOMBRE    SECTOR      SALARIO\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            showEmployee(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay empleades que mostrar\n");
    }

    printf("\n\n");
}

///ordenar en una funcion por apellido y por sector

void sortEmployeesByLastName(Employee vec[], int tam)
{
    Employee auxEmployeeSector;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if(strcmp(vec[i].lastName, vec[j].lastName)>0 || vec [i].sector > vec [i].sector)
            {
                auxEmployeeSector = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmployeeSector;
            }
        }
    }

}


int removeEmployee(Employee vec[], int tam)
{
    int todoOk = 0;
    int id;
    int index;
    char confirma;
    system("cls");
    printf("***** Baja Empleade *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    index = findEmployee(id, vec, tam);

    if( index == -1)
    {
        printf("No existe un empleade con ese ID\n\n");

    }
    else
    {

        showEmployee(vec[index]);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[index].isEmpty = 1;
            todoOk = 1;
            printf("Baja de empleade exitosa!\n");
        }
        else
        {
            printf("\nNo se realizo la baja correspondiente ");
        }
    }

    return todoOk;
}
int modifyEmployee(Employee vec[], int tam)
{

    int todoOk = 0;
    int id;
    int index;
    ///char confirma;
    system("cls");
    printf("\n***** Modificar Empleade *****\n\n");
    printf("Ingrese id del empleade: ");
    scanf("%d", &id);
    int opcion;

    index = findEmployee(id, vec, tam);

    if( index == -1)
    {
        printf("No existe un empleade con ese id\n\n");

    }
    else
    {
        printf(" ID     APELLIDO       NOMBRE  SECTOR  SALARIO\n\n");
        showEmployee(vec[index]);

        printf("\n\n***QUE DESEA MODIFICAR DEL EMPLEADE***\n\n");
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
            scanf("%s", vec[index].name);
            break;

        case 2:
            printf("Ingrese nuevo apellido : ");
            fflush(stdin);
            scanf("%s", vec[index].lastName);
            break;

        case 3:
            printf("Ingrese nuevo salario: ");
            scanf("%f", &vec[index].salary);
            break;

        case 4:
            printf("Ingrese nuevo sector: ");
            scanf("%d", &vec[index].sector);
            while (vec[index].sector<0 || vec[index].sector>5)
            {
                printf("Sector invalido, intentelo nuevamente: ");
                scanf("%d", &vec[index].sector);
            }

            break;

        case 5:
            printf("Se ha cancelado la modificacion ");
            break;

        }
    }
    return todoOk;
}

void initEmployee(Employee vec[], int tam)///inicia el array, pone todas las posicciones en 1. VACIO
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int findFree(Employee vec[], int tam)
{
    int index = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            index = i;
            break;
        }
    }
    return index;
}

int findEmployee(int id, Employee vec[], int tam)
{
    int index = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id == id && vec[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int menuReports()
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

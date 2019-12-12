#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputDiaz.h"
#include "empleados.h"
#include "sectores.h"

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

int buscarLibreEmp(eEmpleado vec[],int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int harcodearEmp(eEmpleado vec[],int tam, int cant)
{
    int cont=0;
    eEmpleado lista[]=
    {
        {1000,"Diaz","Rocio",'f',40000,{3,6,2018},5,0},
        {1001,"Saa","Abril",'f',38000,{17,6,2019},3,0},
        {1002,"Sosa","Lucas",'m',36000,{19,11,2016},4,0},
        {1003,"Pron","Juan",'m',41000,{4,8,2019},1,0},
        {1004,"Rodriguez","Camila",'f',42000,{22,9,2015},5,0}

    };

    if(cant<=tam && cant<=5)
    {
        for(int i=0; i<cant; i++)
        {
            vec[i]=lista[i];
            cont++;
        }
    }

    return cont;
}

void mostrarEmpleado(eEmpleado vec, eSector sec[], int tam)
{
    char sector[21];

    obtenerNomSec(sec,tam,vec.idSector,sector);

    printf(" %2d   %10s   %10s       %c      %.2f     %02d/%02d/%d   %10s\n",vec.legajo,
           vec.apellido,vec.nombre,vec.sexo,vec.salario,
           vec.fechaIngreso.dia,vec.fechaIngreso.mes,
           vec.fechaIngreso.anio,sector);
}

void mostrarEmpleados(eEmpleado emp[], int tamE, eSector sec[], int tamS)
{
    int cont=0;

    system("cls");
    printf(" ID     APELLIDO       NOMBRE     SEXO      SALARIO       FECHA             SECTOR\n\n");

    for(int i=0; i<tamE; i++)
    {
        if(emp[i].isEmpty==0)
        {
            mostrarEmpleado(emp[i],sec,tamS);
            cont++;
        }
    }

    if(cont==0)
    {
        printf("\nNo hay empleados en el sistema\n\n");
    }
}

void ordenarEmp(eEmpleado emp[], int tam)
{
    eEmpleado aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmpi(emp[i].apellido,emp[j].apellido)>0)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }
            else
            {
                if(strcmpi(emp[i].apellido,emp[j].apellido)==0 && strcmpi(emp[i].nombre,emp[j].nombre)>0)
                {
                    aux=emp[i];
                    emp[i]=emp[j];
                    emp[j]=aux;
                }
            }
        }
    }
}

int altaEmp(eEmpleado emp[], int tamE, eSector sec[], int tamS, int id)
{
    int todoOk=0;
    int indice;

    system("cls");
    printf("  *** MENU ALTA EMPLEADO ***  \n\n");

    indice=buscarLibreEmp(emp,tamE);

    if(indice==-1)
    {
        printf("\nNo hay espacio disponible\n\n");
    }
    else
    {
        emp[indice].legajo=id;
        getStringAlpha(51,"Ingrese nombre: ",emp[indice].nombre);
        getStringAlpha(51,"Ingrese apellido: ",emp[indice].apellido);
        getSexo(&emp[indice].sexo,"Ingrese sexo f/m: ");
        getFloatRange(0,100000,&emp[indice].salario,"Ingrese salario: ");

        getIntRange(&emp[indice].fechaIngreso.dia,1,31,"Ingrese dia de ingreso: ");
        getIntRange(&emp[indice].fechaIngreso.mes,1,12,"Ingrese mes de ingreso: ");
        getIntRange(&emp[indice].fechaIngreso.anio,1990,2019,"Ingrese anio de ingreso: ");

        mostrarSectores(sec, tamS);
        getIntRange(&emp[indice].idSector,1,5,"Ingrese numero de sector: ");


        emp[indice].isEmpty=0;
        todoOk=1;
        printf("\nAlta realizada con exito\n\n");
    }

    return todoOk;
}

int buscarEmpId(eEmpleado emp[], int tam, int id)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(emp[i].isEmpty==0 && emp[i].legajo==id)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void bajaEmp(eEmpleado emp[], int tamE, eSector sec[], int tamS)
{
    int confirma;
    int indice;
    int id;

    mostrarEmpleados(emp,tamE,sec,tamS);

    getIntRange(&id,1000,9999,"Ingrese id del empleado: ");

    indice=buscarEmpId(emp,tamE,id);

    while(indice==-1)
    {
        getIntRange(&id,1000,9999,"Ingrese id del empleado valido: ");

        indice=buscarEmpId(emp,tamE,id);
    }
    if(indice !=-1)
    {
        confirma=confimarSalir("\n\nDar de baja empleado? s/n: ");

        if(confirma==1)
        {
            emp[indice].isEmpty=1;
            printf("\nOperacion realizada\n\n");
        }
        else
        {
            printf("\nOperacion cancelada\n\n");
        }
    }

}

int menuModificacion()
{
    int opcion;

    system("cls");
    printf("  ***  MENU DE MODIFICACION ***   \n\n");
    printf("1. Apellido\n");
    printf("2. Nombre\n");
    printf("3. Sexo\n");
    printf("4. Salario\n");
    printf("5. Fecha ingreso\n");
    printf("6. Sector\n");
    printf("7. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void modificarEmp(eEmpleado emp[], int tamE, eSector sec[], int tamS)
{
    int indice;
    int atras;
    int id;

    mostrarEmpleados(emp,tamE,sec,tamS);

    getIntRange(&id,1000,9999,"Ingrese id del empleado: ");

    indice=buscarEmpId(emp,tamE,id);

    while(indice==-1)
    {
        getIntRange(&id,1000,9999,"Ingrese id del empleado valido: ");

        indice=buscarEmpId(emp,tamE,id);
    }
    if(indice !=-1)
    {
        do
        {
            switch(menuModificacion())
            {
            case 1:
                getStringAlpha(51,"Ingrese apellido: ",emp[indice].apellido);
                break;

            case 2:
                getStringAlpha(51,"Ingrese nombre: ",emp[indice].nombre);
                break;

            case 3:
                getSexo(&emp[indice].sexo,"Ingrese sexo f/m: ");
                break;

            case 4:
                getFloatRange(0,100000,&emp[indice].salario,"Ingrese salario: ");
                break;

            case 5:
                getIntRange(&emp[indice].fechaIngreso.dia,1,31,"Ingrese dia de ingreso: ");
                getIntRange(&emp[indice].fechaIngreso.mes,1,12,"Ingrese mes de ingreso: ");
                getIntRange(&emp[indice].fechaIngreso.anio,1990,2019,"Ingrese anio de ingreso: ");
                break;

            case 6:
                mostrarSectores(sec, tamS);
                getIntRange(&emp[indice].idSector,1,5,"Ingrese numero de sector: ");
                break;

            case 7:
                atras=confimarSalir("Volver al menu de opciones? s/n: ");
                break;
            }

        }while(atras != 1);
    }
}

void obtenerNomEmp(eEmpleado emp[], int tam, int id, char dondeAsignar[])
{
    for(int i=0; i<tam; i++)
    {
        if(emp[i].isEmpty==0 && emp[i].legajo==id)
        {
            strcpy(dondeAsignar,emp[i].apellido);
            //strcat(dondeAsignar,", ");
            //strcat(dondeAsignar,emp[i].nombre);
        }
    }
}




















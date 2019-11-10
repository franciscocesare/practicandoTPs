#include <stdio.h>
#include <stdlib.h>
#include "inputDiaz.h"
#include "empleados.h"
#include "sectores.h"
#include "menus.h"
#include "almuerzos.h"

int menuInformes()
{
    int opcion;

    system("cls");
    printf("    #####  Menu de Informes  ####\n\n\n");

    printf("1_ Total y promedio de los importes, y cuantos menues superan ese promedio..\n");
    printf("2_ Total y promedio de los importes, y cuantos menues NO superan ese promedio.\n");
    printf("3_ La cantidad de menues que fueron consumidos por al menos 5 (cinco) empleados.\n");
    printf("4_ La cantidad de menues que fueron consumidos por menos de 5 (cinco) empleados.\n");
    printf("5_ Todos los menues cuyo importe sea menor o igual a $125.\n");
    printf("6_ Todos los menues cuyo importe sea mayor a $125.");
    printf("7_ Todos los empleados que consumieron un menu determinado.\n");
    printf("8_ Todos los menues consumidos por un empleado determinado.\n");
    printf("9_ Todos los almuerzos consumidos en una fecha determinada.\n");
    printf("10_ Todos los empleados que consumieron un almuerzo en una fecha determinada.\n");
    printf("11_ Volver al menu principal.\n");
    printf("\n\nIngresar opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void total_promedioDeMenues(eMenu vec[], int tam)
{
    float total;
    float promedio;
    int cont=0;
    int menus=0;

    system("cls");

    for(int i=0; i<tam;i++)
    {
        total=total+vec[i].importe;
        cont++;

        promedio=total / cont;

        if(promedio < vec[i].importe)
        {
            menus++;
            mostrarMenu(vec[i]);
        }
    }

    printf("La cantidad de menus que superan el promedio es de %d\n",menus);
    printf("\nEl total de los menus es de %.2f\nEl promedio de todos es de %.2f\n",total,promedio);

}

void total_promedioDeMenues2(eMenu vec[], int tam)
{
    float total;
    float promedio;
    int cont=0;
    int menus=0;

    system("cls");

    for(int i=0; i<tam;i++)
    {
        total=total+vec[i].importe;
        cont++;

        promedio=total / cont;

        if(promedio > vec[i].importe)
        {
            menus++;
            mostrarMenu(vec[i]);
        }
    }

    printf("La cantidad de menus que no superan el promedio es de %d\n",menus);
    printf("\nEl total de los menus es de %.2f\nEl promedio de todos es de %.2f\n",total,promedio);

}

int contarMenusPorEmpleado(eAlmuerzo almuerzos[], int tamAlm, eEmpleado emp[], int tamE, int idEmp)
{
    int contador = 0;

    for(int i=0; i<tamE; i++)
    {
        if(emp[i].legajo == idEmp && emp[i].isEmpty == 0)
        {
            for(int j=0; j<tamAlm; j++)
            {
                if(almuerzos[j].idEmp == emp[i].legajo)
                {
                    contador++;
                }
            }
        }
    }

    return contador;
}

void contarCantidadMenusPorEmpleado(eAlmuerzo almuerzos[], int tamAlm, eEmpleado emp[], int tamE){

    char desc[20];
    int cantidad=0;

    system("cls");

    for(int i=0; i<tamE; i++)
    {
        if(i >= 5)
        {
            break;
        }

        obtenerNomEmp(emp,tamE,emp[i].legajo,desc);
        printf("empleado %s ", desc);

        cantidad = contarMenusPorEmpleado(almuerzos,tamAlm,emp,tamE,emp[i].legajo);
        printf("Cantidad: %d \n\n", cantidad);
    }
}




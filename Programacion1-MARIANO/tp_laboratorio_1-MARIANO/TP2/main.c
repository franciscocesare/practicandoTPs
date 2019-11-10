// Trabajo Practico Nº2 - Laboratorio y Programacion 1 - UTN. 2019
// Alumno: Arias Mariano Luis.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "funcionesGenerales.h"
#include "utn.h"
#define CANT 1000

int main()
{
    Employee empleado[CANT];
    initEmployees(empleado, CANT, 0);
    int opcion, i;
    int flagAlta=0;
    int freePlace;
    int auxAlta,auxModificar,auxBajaInt;
    char auxBaja[20];
    int auxSearch;
    int idIncremental=0;
    float totalSalarios, promedioSalario;
    int contador;
    int cantidadSuperiorPromedio=0;

    printf("TP 2 PROGRAMACION Y LABORATORIO I - UTN 2019 - ARIAS MARIANO\n");
    printf("\n\t\tBIENVENIDO AL MENU DE EMPLEADOS\n");

    do {
        opcion=menu();
        switch(opcion){

        case 1://ALTA
            freePlace=searchLugar(empleado, CANT);
            if (freePlace==-1){
                printf("\n\tNo queda lugar libre.\n");
                break;
            }
            auxAlta=addEmployee(empleado, CANT, freePlace, idIncremental);
            if (auxAlta!=-1){
                system("cls");
                printf("Ha realizado Alta de Empleado exitosa.\n\n");
                idIncremental++;
                flagAlta=1;
            }else{
                printf("\nHay un error. Realizar alta nuevamente.");
            }
            break;
        case 2://MODIFICAR
            if(!flagAlta){
                printf("\nNo ha dado de alta a nadie aun.");
                }else{
                auxModificar=modifyEmployee(empleado,CANT);
                }
                if(auxModificar){
                        system("cls");
                        printf("Modificacion exitosa.");
                }
        break;
    case 3: //BAJA
        if(!flagAlta){
            printf("\nNo ha dado de alta a nadie aun");
        }else{
            if(!getStringNumeros("\n Ingrese Id del Empleado a eliminar: ",auxBaja)){
                    printf("Error. Ingrese solo numeros");
                    break;
                }
            auxBajaInt=atoi(auxBaja);

            auxSearch=findEmployeeById(empleado, CANT, auxBajaInt);
            if(auxSearch==-1){
                printf("\nNo se encontro empleado");
                break;
            }
            auxBajaInt=removeEmployee(empleado,CANT,auxSearch);
        }
        break;
    case 4:
         if(!flagAlta){
            printf("No ha dado de alta a nadie aun.");
            break;
        }

        sortEmployee(empleado,CANT);
        printEmployees(empleado,CANT);
        totalSalarios=sumaSalary(empleado, CANT);
        printf("\n\n\tLa suma total de salarios es de $ %.2f",totalSalarios);

        contador=contadorEmployees(empleado, CANT);
        printf("\n\n\tEmpleados activos: %d",contador);
        promedioSalario=totalSalarios/contador;
        printf("\n\n\tEl promedio de salarios es de $ %.2f",promedioSalario);
        cantidadSuperiorPromedio=contadorArribaPromedio(empleado, CANT, promedioSalario, contador);
        printf("\n\n\tLa cantidad de Empleados que superan el promedio es de %d",cantidadSuperiorPromedio);

        break;
        }
    }while (opcion!=0);

    return 0;
}

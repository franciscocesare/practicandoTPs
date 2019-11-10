#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    char salir = 'n';

    if(listaEmpleados!=NULL)
    {
        do{
            switch(menu())
            {
            case 1:
                if(!flag)
                {
                    if(controller_loadFromText("data.csv",listaEmpleados))
                    {
                        flag=1;
                        printf("\nArchivo cargado correctamente.\n");
                    }
                    else
                    {
                        printf("\nNo se pudo cargar el archivo correctamente.\n");
                    }
                }
                else
                {
                    printf("\nYa se cargo el archivo.\n");
                }
                break;

            case 2:
                if(!flag)
                {
                    if(controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        flag=1;
                        printf("\nArchivo cargado correctamente.\n");
                    }
                    else
                    {
                        printf("\nNo se pudo cargar el archivo correctamente.\n");
                    }
                }else
                {
                    printf("\nYa se cargo el archivo.\n");
                }
                break;

            case 3:
                if(flag)
                {
                    controller_addEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nSe debe cargar un archivo previamente.\n");
                }

                break;

            case 4:
                if(flag)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nSe debe cargar un archivo previamente.\n");
                }

                break;

            case 5:
                if(!flag)
                {
                    printf("\nSe debe cargar un archivo previamente.\n");
                }
                else
                {
                   controller_removeEmployee(listaEmpleados);
                }
                break;

            case 6:
                if(!flag)
                {
                    printf("\nSe debe cargar un archivo previamente.\n");
                }
                else
                {
                   controller_ListEmployee(listaEmpleados);
                }

                break;

            case 7:
                 if(!flag)
                {
                    printf("\nSe debe cargar un archivo previamente.\n");
                }
                else
                {
                   controller_sortEmployee(listaEmpleados);
                }
                break;

            case 8:
                if(flag)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                    printf("\nSe genero el archivo texto(.csv) correctamente.\n");
                }else
                {
                    printf("\nDebe cargarse un archivo primeramente.\n");
                }

                break;

            case 9:
                if(flag)
                {
                    controller_saveAsBinary("data.bin" , listaEmpleados);
                    printf("\nSe genero el archivo binario(.bin) correctamente.\n");
                }else
                {
                    printf("\nDebe cargarse un archivo primeramente.\n");
                }

                break;

            case 10:
                printf("\nConfirma la salida del sistema? (s/n): ");
                fflush(stdin);
                scanf("%c",&salir);
                break;

            default:
                printf("\nOPCION INVALIDA\n");

            }
        system("\n\npause\n");
        }while(salir == 'n');
    }
    else
    {
        printf("\nERROR. No se consiguio espacio en memoria para el LinkedList");
    }

    system("\n\npause");
    return 0;
}

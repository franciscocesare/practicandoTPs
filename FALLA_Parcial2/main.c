#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "Dominio.h"
#include "validaciones.h"
#include "parser.h"


int main()
{
    int flag=0;


    FILE *pArchivo;
    LinkedList* listaCachorro = ll_newLinkedList();
   // LinkedList* listaMapeada = NULL; ///aca hacer los filters
    //LinkedList* listaFilterA = NULL; ///aca hacer los filters
   // LinkedList* listaFilterM = NULL; ///aca hacer los filters

    char salir = 'n';

    if(listaCachorro!=NULL)
    {
        do
        {
            switch(menu())
            {
            case 1:

                if((pArchivo=fopen("cachorros.csv","r"))==NULL)
                {
                    printf("\nNO SE PUDO ABRIR EL ARCHIVO\n");

                }
                else if (controller_loadFromText("cachorros.csv", listaCachorro))///(parser_CachorroFromText(pArchivo, listaCachorro))

                {   printf("HOLA\n");
                    system("cls");
                    printf("\nEL ARCHIVO ESTA CARGADO CORRECTAMENTE\n");
                    flag=1;
                }

                fclose(pArchivo);
                break;

            case 2:  ///LISTAR ORIGINAL, SIN TIPO MAPEADO


                   /// printf("GOAOAOA");
                    showCachorros(listaCachorro);


                break;

            case 3: ///MAPEAR Y CARGAR, CON TIPO DE VEHICULO
            /*
                if (flag)
                {
                    listaMapeada = ll_map(listaDominios, seteaTipo);
                    printf("\nSE HA MAPEADO LA LISTA ORIGINAL Y AGREGADO EL TIPO\n");

                }*/
                break;

            case 4: ///Listar vehiculos con tipo
                /*
                if(listaMapeada != NULL)
                {
                    showDominios(listaMapeada);
                }
                else
                {
                    printf("\nERROR, TAL VEZ NO HAY ARCHIVOS CARGADOS.\n");
                }
            */
                break;


            case 5:///Listar vehiculos separados por tipo
            /*
                listaFilterA = ll_filter(listaMapeada, filterTipo, 'A');
                listaFilterM = ll_filter(listaMapeada, filterTipo, 'M');

                if(listaFilterA != NULL && listaFilterM != NULL)
                {
                    showDominios(listaFilterA);
                    printf("\n");
                    showDominios(listaFilterM);
                }

                /*if(!flag)///hacer flag de seteo motos y seteo autos
                {
                    printf("\nSe debe cargar un archivo previamente.\n");
                }
                else
                {
                   controller_removeEmployee(listaEmpleados);
                }
                */
                break;

            case 6:///generar archivo de salida Autos Y MOTOS
                /*
                if (flag)
                {

                    controller_saveAsText("auto.csv", listaFilterA);
                    controller_saveAsText("moto.csv", listaFilterM);

                }

                /*if(!flag)
                {
                    printf("\nSe debe cargar un archivo previamente.\n");
                }
                else
                {
                   controller_ListEmployee(listaEmpleados);
                }
                */
                break;


            case 8: ///SALIR
                printf("\nConfirma la salida del sistema? (s/n): ");
                fflush(stdin);
                scanf("%c",&salir);
                break;

            default:
                printf("\nOPCION INVALIDA\n");

            }
            system("\n\npause\n");
        }
        while(salir == 'n');
    }
    {
        printf("\nERROR. No se consiguio espacio en memoria para el LinkedList");
    }

    system("\n\npause");
    return 0;
}


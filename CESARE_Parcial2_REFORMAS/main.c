#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "Dominio.h"
#include "validaciones.h"
#include "parser.h"


int main()
{
    int flag=0;
    int flagMap=0;
    int flagMapDesktop=0;


    ///FILE *pArchivo;

    ///LinkedList* listaCachorro = ll_newLinkedList();
    LinkedList* listaComputer = ll_newLinkedList();
    LinkedList* listaMapeadaDesktop = NULL;
    ///  LinkedList* listaMapeadaOfertas = NULL;

    ///LinkedList* lista45Dias = NULL; ///cada nuevo linkedlist que crea MAP, se incializa en NULL
    ///LinkedList* listaMachos = NULL;
    ///LinkedList* listaCallejeros = NULL;
    ///LinkedList* listaReservados = NULL;
    // LinkedList* listaMapeada = NULL; ///aca hacer los filters
    //LinkedList* listaFilterA = NULL; ///aca hacer los filters
    // LinkedList* listaFilterM = NULL; ///aca hacer los filters

    char salir = 'n';
    char nombreArchivo [15];
    char nombreArchivoAux [15]="datos.csv";

    ///int count=0;  LA USO SI USO LL_COUNT

    if(listaComputer!=NULL)
    {
        do
        {
            switch(menu())
            {
            case 1:

                getString(nombreArchivo, "INGRESE EL NOMBRE DEL ARCHIVO QUE DESEA ABRIR, SIN EXTENSION :\n\n", "ERROR ");
                strcat(nombreArchivo, ".csv");

                if (!strcmpi(nombreArchivo,nombreArchivoAux))///(parser_CachorroFromText(pArchivo, listaCachorro))

                {
                    system("cls");
                    if (controller_loadFromText(nombreArchivo, listaComputer))
                    {
                        system("cls");
                        printf("\nEL ARCHIVO ESTA CARGADO CORRECTAMENTE, PUEDE CONTINUAR\n");
                        flag=1;
                    }

                }
                else
                {
                    system("cls");
                    printf("\n***EL ARCHIVO NO EXISTE***\n");
                }

                break;

            case 2:
                if (flag)

                {
                    controller_sort(listaComputer);

                   if (flagMap==0)
                   {
                       printf("\n\n EL ARCHIVO ESTA ORDENADO, AUN NO SETEO LAS OFERTAS\n\n");
                   }

                }
                else
                {
                    system("cls");
                    printf("\n***Primero debe cargar algun archivo***\n");
                }
                break;

            case 3: ///mostrar

                if (flag)
                {

                    showComputers(listaComputer);

                    ///count=ll_counter(listaComputer, filter_desktop); SI OIDEN COUNT
                    /// printf("%\nHAY %d  LAPTOS:\n", count);

                    ///lista45Dias = ll_filter(listaCachorro, filter_45dias);///filtra y genera una nueva lista
                    ///controller_saveAsText("cachorros45dias.csv", lista45Dias);///guarda esa nueva lista en texto, con el nombre pasado como parametro


                }
                else
                {
                    system("cls");
                    printf("\n***Primero debe cargar algun archivo***\n");
                }

                break;

            case 4: ///LL MAP
                if (flag)

                {
                    /// listaMapeadaOfertas=ll_map(listaComputer, setearOferta);
                    controller_map(listaComputer);
                    printf("\n **Se mapeo y cargo el tipo de Pc** \n");
                    flagMap=1;
                }

                else
                {
                    system("cls");
                    printf("\n***Primero debe cargar algun archivo para setearlo***\n");
                }

                break;


            case 5:///filtar y mostrar


                if (flag && flagMap)
                {
                    system("cls");
                    listaMapeadaDesktop = ll_filter(listaComputer, filter_desktop);///filtra y genera una nueva lista
                    printf("\n***Se Mapeo y Filtro las Tipo Desktop***\n");
                    system("pause");
                    showComputers(listaMapeadaDesktop);
                    flagMapDesktop=1;
                }
                else
                {
                    system("cls");
                    printf("\n***Algun paso se salteo, controle haber seteado las ofertas***\n");
                }
                break;

            case 6:/// generar dato de salida filtrado;


                if(flagMapDesktop==1 && flag==1)
                {
                    /// listaMapeadaDesktop = ll_filter(listaComputer, filter_desktop);///filtra y genera una nueva lista
                    printf("\n***Se genero un archivo de salida Filtrado por Desktop****\n");
                    controller_saveAsText("filtrado.csv", listaMapeadaDesktop);///guarda esa nueva lista en texto, con el nombre pasado como parametro

                }
                else
                {
                    system("cls");
                    printf("\n***Primero se debe mapear y filtrar el archivo***\n");

                }
                break;

            case 7: ///SALIR
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


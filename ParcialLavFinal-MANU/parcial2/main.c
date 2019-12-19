#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"

#include "LinkedList.h"
#include "biblioteca.h"
#include "Controller.h"
#include "computer.h"
#include "menu.h"


int main()
{
    char salir = 'N';
    int flag = 0;
    int flagOrder = 0;
    int flagFilter=0;
    int flagMap=0;
    int devolution;

    char path[50];

    LinkedList* listaComputer = ll_newLinkedList();
    LinkedList* listaMapeada = NULL;
    LinkedList* listaFiltrada = NULL;

   do{
        switch(menu())
        {
            case 1:
            if(!flag){
                    printf("Ingresa el archivo: ");
                    scanf("%s", path);
                    strcat(path, ".csv");
                    if(controller_loadFromText(path, listaComputer)){
                        printf("\n   **********************\n");
                        printf("   * Cargo Exitosamente *\n");
                        printf("   **********************\n\n");
                        flag=1;
                    }else{
                        printf("\n   *******************\n");
                        printf("   * Error al cargar *\n");
                        printf("   *******************\n\n");
                    }
            }else if(flag){
                        printf("\n   *******************\n");
                        printf("   * YA esta cargado *\n");
                        printf("   *******************\n\n");
            }
            else{
                        printf("\n   *******************\n");
                        printf("   * Error al cargar *\n");
                        printf("   *******************\n\n");
            }
            break;

        case 2:
                if(!flag){
                        printf("\n   ******************************\n");
                        printf("   * No hay ningun dato cargado *\n");
                        printf("   ******************************\n\n");
                }else if(flagOrder){
                        printf("\n   *******************\n");
                        printf("   * YA esta ordenado *\n");
                        printf("   *******************\n\n");
                }
                else{
                    if(controller_sortComputer(listaComputer)){
                        printf("\n   ******************************\n");
                        printf("   * Se ordeno Correctamente *\n");
                        printf("   ******************************\n\n");
                        flagOrder=1;
                    }

                }

                system("pause");
            break;
        case 3:
            if(flag){
                showComputers(listaComputer);
            }
            else{
                        printf("\n   *******************\n");
                        printf("   * Primero debe cargar *\n");
                        printf("   *******************\n\n");
            }
            break;
        case 4:
            if(flag && flagOrder && !flagMap){
                listaMapeada = ll_Map(listaComputer, setearOferta);
                if(listaMapeada != NULL){
                    showComputers(listaMapeada);
                        printf("\n   ********************\n");
                        printf("   * Mapeo Exitoso !! *\n");
                        printf("   ********************\n\n");
                    flagMap=1;
                }
            }
            else if(flag && flagOrder && flagMap){
                printf("\n   ******************\n");
                printf("   * YA esta Mapeado *\n");
                printf("   *******************\n\n");
            }else{
                        printf("\n   *******************************\n");
                        printf("   * Primero debe cargar y ordenar *\n");
                        printf("   *********************************\n\n");
            }
            break;
        case 5:
            if( flag && flagMap){
               listaFiltrada = ll_filter(listaMapeada, filtrarDesktop);
               if(listaFiltrada != NULL){
                    showComputers(listaFiltrada);
                    flagFilter=1;
               }
            }else{
                        printf("\n   *******************************\n");
                        printf("   * Primero debe cargar y mapear *\n");
                        printf("   *********************************\n\n");
            }
            break;
        case 6:
            if(flagFilter){

                devolution = controller_saveAsText("filtrado.csv", listaFiltrada);
                if(devolution){
                    printf("\n   **********************\n");
                    printf("   * Cargo Exitosamente *\n");
                    printf("   **********************\n\n");
                }else if(!devolution){
                    printf("\n   **********************\n");
                    printf("   * ERROR DE CARGA *\n");
                    printf("   **********************\n\n");
                }

            }
            break;

        case 7:
                getChar(&salir,"Desea Salir?  S o N: ","Error. Ingrese S o N: ", 'S', 'N');
                printf("\n\n");
        }
        system("pause");
   }while(salir == 'N');



    return 0;
}

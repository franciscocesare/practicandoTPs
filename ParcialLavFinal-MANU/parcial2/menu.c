#include <stdio.h>
#include <stdlib.h>
#include "stdlib.h"

#include "menu.h"
#include "biblioteca.h"


int menu(void)
{
    int option;

        system("cls");
        printf("***************** PARCIAL LAVORATORIO 2  *****************\n");
        printf("*************    Biblioteca LinkedList    *************\n\n");

        printf("1. Cargar el archivo (modo texto)\n");
        printf("2. Ordenar\n");
        printf("3. Imprimir en pantalla \n");
        printf("4. Mapear\n");
        printf("5. Filtrar\n");
        printf("6. Guardar en archivo csv\n");

        printf("7. Salir\n");

        getIntRange(&option, "\nIngrese Opcion: ", "Error. Reingrese Opcion: ", 1, 7);

    return option;
}

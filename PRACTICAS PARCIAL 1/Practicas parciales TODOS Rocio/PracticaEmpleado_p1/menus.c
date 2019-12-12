#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"

void harcodearMenus(eMenu vec[], int tam)
{
    eMenu lista[]=
    {
        {10,"Milanesa con pure",200},
        {11,"Hamburguesa con papas",250},
        {12,"Fideos con salsa",160},
        {13,"Pastel de papa",210},
        {14,"Sanguche de lomito",180}

    };

    for(int i=0; i<tam; i++)
    {
        vec[i]=lista[i];
    }
}

void mostrarMenu(eMenu vec)
{
    printf(" %d  %24s   %.2f\n",vec.id,vec.descripcion,vec.importe);
}

void mostrarMenus(eMenu vec[], int tam)
{
    system("cls");
    printf(" ID               MENU          IMPORTE\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarMenu(vec[i]);
    }
}

void obtenerNomMenu(eMenu vec[], int tam, int id, char dondeAsignar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].id == id)
        {
            strcpy(dondeAsignar,vec[i].descripcion);
        }
    }
}

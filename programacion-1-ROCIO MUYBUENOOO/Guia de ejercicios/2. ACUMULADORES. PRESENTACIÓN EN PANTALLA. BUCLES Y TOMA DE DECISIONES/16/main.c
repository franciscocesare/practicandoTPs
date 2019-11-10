#include <stdio.h>
#include <stdlib.h>

/* Hacer el programa que nos permita introducir un número por
teclado y nos informe si es positivo o negativo */

int main()
{
    int num;

    printf("ingrese numero neg o pos: ");
    scanf("%d",&num);

    if(num > 0)
    {
        printf("\nnumero postivo\n");
    }
    else
    {
        printf("\nnumero negativo\n");
    }
    return 0;
}

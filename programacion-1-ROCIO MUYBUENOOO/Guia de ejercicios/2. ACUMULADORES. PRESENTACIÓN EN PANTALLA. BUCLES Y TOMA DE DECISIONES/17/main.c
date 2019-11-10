#include <stdio.h>
#include <stdlib.h>

/* Hacer el programa que nos permita introducir un
número por teclado y nos informe si es par o impar */

int main()
{
    int num;

    printf("ingrese numero: ");
    scanf("%d",&num);

    if(num %2 == 0)
    {
        printf("\nnumero par\n");
    }
    else
    {
        printf("\nnumero impar\n");
    }

    return 0;
}

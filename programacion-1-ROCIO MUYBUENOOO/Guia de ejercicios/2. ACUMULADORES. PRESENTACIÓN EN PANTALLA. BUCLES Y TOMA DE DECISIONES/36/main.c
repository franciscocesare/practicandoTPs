#include <stdio.h>
#include <stdlib.h>

/* Realizar la tabla de multiplicar de un número entre 0 y 10 de forma que
se visualice de la siguiente forma: 4x1= 4 4x2= 8 */

int main()
{
    int tabla;
    int resultado;

    printf("ingrese numero entre 0/10: ");
    scanf("%d",&tabla);
    printf("\n");

    for(int i=0; i<11; i++)
    {
        resultado=tabla*i;

        printf("%dx%d=%d\n",tabla,i,resultado);

    }

    return 0;
}

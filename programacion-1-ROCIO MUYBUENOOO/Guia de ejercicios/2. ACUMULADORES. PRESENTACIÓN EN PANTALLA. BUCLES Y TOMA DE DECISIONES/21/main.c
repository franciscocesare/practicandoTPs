#include <stdio.h>
#include <stdlib.h>

/* Hacer el programa que nos permita contar los múltiplos de 3
desde la unidad hasta un número que introducimos por teclado */

int main()
{
    int num;
    int cont=0;

    printf("ingrese numero: ");
    scanf("%d",&num);

    while(cont < num-1)
    {
        cont++;

        if(cont %3 == 0)
        {
            printf("%d\n",cont);
        }
    }

    return 0;
}

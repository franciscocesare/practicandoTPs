#include <stdio.h>
#include <stdlib.h>

/* Hacer el programa que imprima todos los números naturales que hay
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
        printf("%d-",cont);
    }

    return 0;
}

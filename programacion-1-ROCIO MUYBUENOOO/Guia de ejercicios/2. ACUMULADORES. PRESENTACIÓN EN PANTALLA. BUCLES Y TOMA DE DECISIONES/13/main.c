#include <stdio.h>
#include <stdlib.h>

// Hacer el programa que imprima los números del 100 al 0 en orden decreciente

int main()
{
    int cont=101;

    while(cont > 0)
    {
        cont--;
        printf("%d\n",cont);
    }
    return 0;
}

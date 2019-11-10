#include <stdio.h>
#include <stdlib.h>

// Escribir en y codificar en C un programa que muestre los múltiplos de 6 comprendidos entre 0 y 100


int main()
{
    int cont=0;

    while(cont < 100)
    {
        cont++;

        if(cont %6 == 0)
        {
            printf("%d\n",cont);
        }
    }
    return 0;
}

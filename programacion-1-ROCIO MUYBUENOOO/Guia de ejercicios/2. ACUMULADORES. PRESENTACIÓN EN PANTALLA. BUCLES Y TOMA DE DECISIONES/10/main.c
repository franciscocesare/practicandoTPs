#include <stdio.h>
#include <stdlib.h>

// Escribir en C un programa que muestre los números impares entre 0 y 100 y que imprima cuantos impares hay

int main()
{
    int cant=0;
    int cont=0;

    while(cont < 100)
    {
        cont++;

        if(cont %2 != 0)
        {
            printf("%d ",cont);
            cant++;
        }
    }

    printf("\n\ncantida de impares %d\n\n",cant);

    return 0;
}

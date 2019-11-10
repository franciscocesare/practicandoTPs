#include <stdio.h>
#include <stdlib.h>

// De 10 números ingresadas indicar cuantos son mayores a cero y cuantos son menores a cero

int main()
{
    int numeros[10];
    int contPos=0;
    int contNeg=0;

    for(int i=0; i<10; i++)
    {
        printf("ingreser numero: ");
        scanf("%d",&numeros[i]);

        if(numeros[i] > 0)
        {
            contPos++;
        }
        else
        {
            contNeg++;
        }
    }

    printf("\ncantidad de positivos %d\ncantidad de negativos %d\n\n",contPos, contNeg);

    return 0;
}
